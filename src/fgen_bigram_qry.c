#include "fgen_bigram_qry.h"
#include "strbuf.h"

/* Create a new hash table, with init_size buckets */
bigramhash_t *new_bigramhash(void) {
    bigramhash_t *bigramhash;

    bigramhash          = safe_malloc(sizeof(bigramhash_t));
    bigramhash->buckets = INITIAL_SIZE;
    bigramhash->items   = 0;
    bigramhash->array   = safe_malloc(bigramhash->buckets * sizeof(void *));
    return (bigramhash);
}

static void delete_bigram(bigram_t *data) {
    if (data->bigram) {
        free(data->bigram);
    }
    free(data);
    return;
}

void destroy_bigramhash(bigramhash_t *bigramhash) {
    uint32_t  i;
    bigram_t *value;

    for (i = 0; i < bigramhash->buckets; i++) {
        if ((value = bigramhash->array[i])) {
            delete_bigram(value);
        }
    }
    free(bigramhash->array);
    free(bigramhash);
    return;
}

static size_t get_bigram_pos(bigramhash_t *bigrammap, char *buf, size_t *pos) {
    bigram_t *value;
    *pos = murmur_hash(buf, bigrammap->buckets);

    do {
        value = bigrammap->array[*pos];
        if (!value) {
            return (false);
        } else if (strcmp((char *)value->bigram, buf) == 0) {
            return (true);
        }
        *pos += 1;
        *pos &= (bigrammap->buckets - 1);
    } while (true);

    return (false);
}

static void check_bigramhash(bigramhash_t *bigrammap) {
    size_t     i;
    size_t     old_buckets;
    bigram_t **old_array;

    if ((bigrammap->buckets * GOOD_RATIO_N) > (bigrammap->items * GOOD_RATIO_D)) {
        return;
    }

    old_array   = bigrammap->array;
    old_buckets = bigrammap->buckets;
    bigrammap->buckets *= GROW_RATE;
    bigrammap->array = safe_malloc(bigrammap->buckets * sizeof(void *));
    for (i = 0; i < old_buckets; i++) {
        bigram_t *value = old_array[i];
        if (value) {
            size_t pos;
            get_bigram_pos(bigrammap, (char *)value->bigram, &pos);
            bigrammap->array[pos] = value;
        }
    }
    free(old_array);
    return;
}

bigram_t *find_bigram(bigramhash_t *bigrammap, char *buf) {
    size_t pos;
    int    found;

    found = get_bigram_pos(bigrammap, buf, &pos);
    if (!found) {
        return (NULL);
    }
    return (bigrammap->array[pos]);
}

void add_bigram(bigramhash_t *bigrammap, bigram_t *buf) {
    int    found;
    size_t pos;

    check_bigramhash(bigrammap);

    found = get_bigram_pos(bigrammap, buf->bigram, &pos);

    if (found) {
        fprintf(stderr, "ERROR: Word exists! Bailing out.\n");
        exit(EXIT_FAILURE);
    } else {
        bigrammap->array[pos] = buf;
        bigrammap->items++;
    }
    return;
}

bigramhash_t *load_bigrammap(const char *fname) {
    bigramhash_t *map   = new_bigramhash();
    FILE *        input = NULL;
    char          term_a[1024];
    char          term_b[1024];
    char *        d_str = NULL;
    uint64_t      cf;
    uint64_t      cdf;
    double        geo_mean;
    int           num = 0;

    double bm25_median_score;
    double bm25_firstq_score;
    double bm25_thirdq_score;
    double bm25_max_score;
    double bm25_min_score;
    double bm25_mean_score;
    double bm25_score_variance;
    double bm25_score_stddev;
    double bm25_score_confidence;
    double bm25_score_harmonic_mean;

    double tf_median_score;
    double tf_firstq_score;
    double tf_thirdq_score;
    double tf_max_score;
    double tf_min_score;
    double tf_mean_score;
    double tf_score_variance;
    double tf_score_stddev;
    double tf_score_confidence;
    double tf_score_harmonic_mean;

    double lm_median_score;
    double lm_firstq_score;
    double lm_thirdq_score;
    double lm_max_score;
    double lm_min_score;
    double lm_mean_score;
    double lm_score_variance;
    double lm_score_stddev;
    double lm_score_confidence;
    double lm_score_harmonic_mean;

    double dfr_median_score;
    double dfr_firstq_score;
    double dfr_thirdq_score;
    double dfr_max_score;
    double dfr_min_score;
    double dfr_mean_score;
    double dfr_score_variance;
    double dfr_score_stddev;
    double dfr_score_confidence;
    double dfr_score_harmonic_mean;

    double dph_median_score;
    double dph_firstq_score;
    double dph_thirdq_score;
    double dph_max_score;
    double dph_min_score;
    double dph_mean_score;
    double dph_score_variance;
    double dph_score_stddev;
    double dph_score_confidence;
    double dph_score_harmonic_mean;

    double be_median_score;
    double be_firstq_score;
    double be_thirdq_score;
    double be_max_score;
    double be_min_score;
    double be_mean_score;
    double be_score_variance;
    double be_score_stddev;
    double be_score_confidence;
    double be_score_harmonic_mean;

    double pr_median_score;
    double pr_firstq_score;
    double pr_thirdq_score;
    double pr_max_score;
    double pr_min_score;
    double pr_mean_score;
    double pr_score_variance;
    double pr_score_stddev;
    double pr_score_confidence;
    double pr_score_harmonic_mean;

    if ((input = fopen(fname, "rb")) == NULL) {
        fprintf(stderr, "fopen(%s)\n", fname);
        exit(EXIT_FAILURE);
    }

    while (fscanf(input,
                  "%s %s %" SCNu64 " %" SCNu64
                  " %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf "
                  "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
                  term_a,
                  term_b,
                  &cf,
                  &cdf,
                  &geo_mean,
                  &bm25_median_score,
                  &bm25_firstq_score,
                  &bm25_thirdq_score,
                  &bm25_max_score,
                  &bm25_min_score,
                  &bm25_mean_score,
                  &bm25_score_variance,
                  &bm25_score_stddev,
                  &bm25_score_confidence,
                  &bm25_score_harmonic_mean,
                  &tf_median_score,
                  &tf_firstq_score,
                  &tf_thirdq_score,
                  &tf_max_score,
                  &tf_min_score,
                  &tf_mean_score,
                  &tf_score_variance,
                  &tf_score_stddev,
                  &tf_score_confidence,
                  &tf_score_harmonic_mean,
                  &lm_median_score,
                  &lm_firstq_score,
                  &lm_thirdq_score,
                  &lm_max_score,
                  &lm_min_score,
                  &lm_mean_score,
                  &lm_score_variance,
                  &lm_score_stddev,
                  &lm_score_confidence,
                  &lm_score_harmonic_mean,
                  &pr_median_score,
                  &pr_firstq_score,
                  &pr_thirdq_score,
                  &pr_max_score,
                  &pr_min_score,
                  &pr_mean_score,
                  &pr_score_variance,
                  &pr_score_stddev,
                  &pr_score_confidence,
                  &pr_score_harmonic_mean,
                  &be_median_score,
                  &be_firstq_score,
                  &be_thirdq_score,
                  &be_max_score,
                  &be_min_score,
                  &be_mean_score,
                  &be_score_variance,
                  &be_score_stddev,
                  &be_score_confidence,
                  &be_score_harmonic_mean,
                  &dph_median_score,
                  &dph_firstq_score,
                  &dph_thirdq_score,
                  &dph_max_score,
                  &dph_min_score,
                  &dph_mean_score,
                  &dph_score_variance,
                  &dph_score_stddev,
                  &dph_score_confidence,
                  &dph_score_harmonic_mean,
                  &dfr_median_score,
                  &dfr_firstq_score,
                  &dfr_thirdq_score,
                  &dfr_max_score,
                  &dfr_min_score,
                  &dfr_mean_score,
                  &dfr_score_variance,
                  &dfr_score_stddev,
                  &dfr_score_confidence,
                  &dfr_score_harmonic_mean) == 75) {
        d_str = safe_strdup(term_a);
        d_str = safe_str_append(d_str, term_b);
        // fprintf(stderr, "bigram str: %s\n", d_str);
        bigram_t *curr = find_bigram(map, d_str);
        if (curr != NULL) {
            fprintf(stderr, "ERROR: Duplicate bigram <%s>!\n", d_str);
            exit(EXIT_FAILURE);
        } else {
            curr           = safe_malloc(sizeof(bigram_t));
            curr->bigram   = safe_strdup(d_str);
            curr->cf       = cf;
            curr->cdf      = cdf;
            curr->geo_mean = geo_mean;

            curr->bm25_median_score        = bm25_median_score;
            curr->bm25_firstq_score        = bm25_firstq_score;
            curr->bm25_thirdq_score        = bm25_thirdq_score;
            curr->bm25_max_score           = bm25_max_score;
            curr->bm25_min_score           = bm25_min_score;
            curr->bm25_mean_score          = bm25_mean_score;
            curr->bm25_score_variance      = bm25_score_variance;
            curr->bm25_score_stddev        = bm25_score_stddev;
            curr->bm25_score_harmonic_mean = bm25_score_harmonic_mean;

            curr->tf_median_score        = tf_median_score;
            curr->tf_firstq_score        = tf_firstq_score;
            curr->tf_thirdq_score        = tf_thirdq_score;
            curr->tf_max_score           = tf_max_score;
            curr->tf_min_score           = tf_min_score;
            curr->tf_mean_score          = tf_mean_score;
            curr->tf_score_variance      = tf_score_variance;
            curr->tf_score_stddev        = tf_score_stddev;
            curr->tf_score_harmonic_mean = tf_score_harmonic_mean;
            curr->lm_median_score        = lm_median_score;
            curr->lm_firstq_score        = lm_firstq_score;
            curr->lm_thirdq_score        = lm_thirdq_score;
            curr->lm_max_score           = lm_max_score;
            curr->lm_min_score           = lm_min_score;
            curr->lm_mean_score          = lm_mean_score;
            curr->lm_score_variance      = lm_score_variance;
            curr->lm_score_stddev        = lm_score_stddev;
            curr->lm_score_harmonic_mean = lm_score_harmonic_mean;

            curr->pr_median_score        = pr_median_score;
            curr->pr_firstq_score        = pr_firstq_score;
            curr->pr_thirdq_score        = pr_thirdq_score;
            curr->pr_max_score           = pr_max_score;
            curr->pr_min_score           = pr_min_score;
            curr->pr_mean_score          = pr_mean_score;
            curr->pr_score_variance      = pr_score_variance;
            curr->pr_score_stddev        = pr_score_stddev;
            curr->pr_score_harmonic_mean = pr_score_harmonic_mean;

            curr->be_median_score        = be_median_score;
            curr->be_firstq_score        = be_firstq_score;
            curr->be_thirdq_score        = be_thirdq_score;
            curr->be_max_score           = be_max_score;
            curr->be_min_score           = be_min_score;
            curr->be_mean_score          = be_mean_score;
            curr->be_score_variance      = be_score_variance;
            curr->be_score_stddev        = be_score_stddev;
            curr->be_score_harmonic_mean = be_score_harmonic_mean;

            curr->dph_median_score        = dph_median_score;
            curr->dph_firstq_score        = dph_firstq_score;
            curr->dph_thirdq_score        = dph_thirdq_score;
            curr->dph_max_score           = dph_max_score;
            curr->dph_min_score           = dph_min_score;
            curr->dph_mean_score          = dph_mean_score;
            curr->dph_score_variance      = dph_score_variance;
            curr->dph_score_stddev        = dph_score_stddev;
            curr->dph_score_harmonic_mean = dph_score_harmonic_mean;

            curr->dfr_median_score        = dfr_median_score;
            curr->dfr_firstq_score        = dfr_firstq_score;
            curr->dfr_thirdq_score        = dfr_thirdq_score;
            curr->dfr_max_score           = dfr_max_score;
            curr->dfr_min_score           = dfr_min_score;
            curr->dfr_mean_score          = dfr_mean_score;
            curr->dfr_score_variance      = dfr_score_variance;
            curr->dfr_score_stddev        = dfr_score_stddev;
            curr->dfr_score_harmonic_mean = dfr_score_harmonic_mean;

            add_bigram(map, curr);
        }
        num++;
    }

    // fprintf(stderr, "Number of bigrams loaded [%d]\n", num);
    fclose(input);
    return map;
}

int max_score_bigram_cmp(const void *a, const void *b) {
    bigram_t *bigram_a = (bigram_t *)a;
    bigram_t *bigram_b = (bigram_t *)b;
    if (bigram_a->bm25_max_score > bigram_b->bm25_max_score) {
        return (-1);
    } else if (bigram_a->bm25_max_score < bigram_b->bm25_max_score) {
        return (1);
    }
    return (0);
}

int tf_max_score_bigram_cmp(const void *a, const void *b) {
    bigram_t *bigram_a = (bigram_t *)a;
    bigram_t *bigram_b = (bigram_t *)b;
    if (bigram_a->tf_max_score > bigram_b->tf_max_score) {
        return (-1);
    } else if (bigram_a->tf_max_score < bigram_b->tf_max_score) {
        return (1);
    }
    return (0);
}

int lm_max_score_bigram_cmp(const void *a, const void *b) {
    bigram_t *bigram_a = (bigram_t *)a;
    bigram_t *bigram_b = (bigram_t *)b;
    if (bigram_a->lm_max_score > bigram_b->lm_max_score) {
        return (-1);
    } else if (bigram_a->lm_max_score < bigram_b->lm_max_score) {
        return (1);
    }
    return (0);
}

int be_max_score_bigram_cmp(const void *a, const void *b) {
    bigram_t *bigram_a = (bigram_t *)a;
    bigram_t *bigram_b = (bigram_t *)b;
    if (bigram_a->be_max_score > bigram_b->be_max_score) {
        return (-1);
    } else if (bigram_a->be_max_score < bigram_b->be_max_score) {
        return (1);
    }
    return (0);
}

int pr_max_score_bigram_cmp(const void *a, const void *b) {
    bigram_t *bigram_a = (bigram_t *)a;
    bigram_t *bigram_b = (bigram_t *)b;
    if (bigram_a->pr_max_score > bigram_b->pr_max_score) {
        return (-1);
    } else if (bigram_a->pr_max_score < bigram_b->pr_max_score) {
        return (1);
    }
    return (0);
}

int dph_max_score_bigram_cmp(const void *a, const void *b) {
    bigram_t *bigram_a = (bigram_t *)a;
    bigram_t *bigram_b = (bigram_t *)b;
    if (bigram_a->dph_max_score > bigram_b->dph_max_score) {
        return (-1);
    } else if (bigram_a->dph_max_score < bigram_b->dph_max_score) {
        return (1);
    }
    return (0);
}

int dfr_max_score_bigram_cmp(const void *a, const void *b) {
    bigram_t *bigram_a = (bigram_t *)a;
    bigram_t *bigram_b = (bigram_t *)b;
    if (bigram_a->dfr_max_score > bigram_b->dfr_max_score) {
        return (-1);
    } else if (bigram_a->dfr_max_score < bigram_b->dfr_max_score) {
        return (1);
    }
    return (0);
}

static bool count_done    = false;
static int  feature_count = 0;
static void ffmt(struct strbuf *buf, long double val) {
    if (!count_done) {
        ++feature_count;
    }
    strbuf_append(buf, ",%.5Lf", val);
}

char *fgen_bigram_qry_main(bigramhash_t *bigrammap, int qnum, char **termv, size_t termc) {
    int            tcnt = 0, i = 0;
    int            num_bigrams = termc * termc - termc;
    struct strbuf *buf         = strbuf_new();
    char *         ret_buf     = NULL;

    if (MAXTERM < num_bigrams) {
        fprintf(stderr, "Too many bigrams: %d\n", num_bigrams);
        exit(EXIT_FAILURE);
    }

    bigram_t *terms = safe_malloc(MAXTERM * sizeof(bigram_t));

    char *bigram;
    for (size_t j = 0; j < termc; ++j) {
        for (size_t k = 0; k < termc; ++k) {
            if (j == k)
                continue;
            bigram       = safe_strdup(termv[j]);
            bigram       = safe_str_append(bigram, termv[k]);
            bigram_t *ct = find_bigram(bigrammap, bigram);
            if (ct) {
                terms[tcnt].bigram                   = ct->bigram;
                terms[tcnt].cdf                      = ct->cdf;
                terms[tcnt].cf                       = ct->cf;
                terms[tcnt].geo_mean                 = ct->geo_mean;
                terms[tcnt].bm25_median_score        = ct->bm25_median_score;
                terms[tcnt].bm25_firstq_score        = ct->bm25_firstq_score;
                terms[tcnt].bm25_thirdq_score        = ct->bm25_thirdq_score;
                terms[tcnt].bm25_max_score           = ct->bm25_max_score;
                terms[tcnt].bm25_min_score           = ct->bm25_min_score;
                terms[tcnt].bm25_mean_score          = ct->bm25_mean_score;
                terms[tcnt].bm25_score_variance      = ct->bm25_score_variance;
                terms[tcnt].bm25_score_stddev        = ct->bm25_score_stddev;
                terms[tcnt].bm25_score_harmonic_mean = ct->bm25_score_harmonic_mean;
                terms[tcnt].tf_median_score          = ct->tf_median_score;
                terms[tcnt].tf_firstq_score          = ct->tf_firstq_score;
                terms[tcnt].tf_thirdq_score          = ct->tf_thirdq_score;
                terms[tcnt].tf_max_score             = ct->tf_max_score;
                terms[tcnt].tf_min_score             = ct->tf_min_score;
                terms[tcnt].tf_mean_score            = ct->tf_mean_score;
                terms[tcnt].tf_score_variance        = ct->tf_score_variance;
                terms[tcnt].tf_score_stddev          = ct->tf_score_stddev;
                terms[tcnt].tf_score_harmonic_mean   = ct->tf_score_harmonic_mean;
                terms[tcnt].lm_median_score          = ct->lm_median_score;
                terms[tcnt].lm_firstq_score          = ct->lm_firstq_score;
                terms[tcnt].lm_thirdq_score          = ct->lm_thirdq_score;
                terms[tcnt].lm_max_score             = ct->lm_max_score;
                terms[tcnt].lm_min_score             = ct->lm_min_score;
                terms[tcnt].lm_mean_score            = ct->lm_mean_score;
                terms[tcnt].lm_score_variance        = ct->lm_score_variance;
                terms[tcnt].lm_score_stddev          = ct->lm_score_stddev;
                terms[tcnt].lm_score_harmonic_mean   = ct->lm_score_harmonic_mean;
                terms[tcnt].dfr_median_score         = ct->dfr_median_score;
                terms[tcnt].dfr_firstq_score         = ct->dfr_firstq_score;
                terms[tcnt].dfr_thirdq_score         = ct->dfr_thirdq_score;
                terms[tcnt].dfr_max_score            = ct->dfr_max_score;
                terms[tcnt].dfr_min_score            = ct->dfr_min_score;
                terms[tcnt].dfr_mean_score           = ct->dfr_mean_score;
                terms[tcnt].dfr_score_variance       = ct->dfr_score_variance;
                terms[tcnt].dfr_score_stddev         = ct->dfr_score_stddev;
                terms[tcnt].dfr_score_harmonic_mean  = ct->dfr_score_harmonic_mean;
                terms[tcnt].dph_median_score         = ct->dph_median_score;
                terms[tcnt].dph_firstq_score         = ct->dph_firstq_score;
                terms[tcnt].dph_thirdq_score         = ct->dph_thirdq_score;
                terms[tcnt].dph_max_score            = ct->dph_max_score;
                terms[tcnt].dph_min_score            = ct->dph_min_score;
                terms[tcnt].dph_mean_score           = ct->dph_mean_score;
                terms[tcnt].dph_score_variance       = ct->dph_score_variance;
                terms[tcnt].dph_score_stddev         = ct->dph_score_stddev;
                terms[tcnt].dph_score_harmonic_mean  = ct->dph_score_harmonic_mean;
                terms[tcnt].be_median_score          = ct->be_median_score;
                terms[tcnt].be_firstq_score          = ct->be_firstq_score;
                terms[tcnt].be_thirdq_score          = ct->be_thirdq_score;
                terms[tcnt].be_max_score             = ct->be_max_score;
                terms[tcnt].be_min_score             = ct->be_min_score;
                terms[tcnt].be_mean_score            = ct->be_mean_score;
                terms[tcnt].be_score_variance        = ct->be_score_variance;
                terms[tcnt].be_score_stddev          = ct->be_score_stddev;
                terms[tcnt].be_score_harmonic_mean   = ct->be_score_harmonic_mean;
                terms[tcnt].pr_median_score          = ct->pr_median_score;
                terms[tcnt].pr_firstq_score          = ct->pr_firstq_score;
                terms[tcnt].pr_thirdq_score          = ct->pr_thirdq_score;
                terms[tcnt].pr_max_score             = ct->pr_max_score;
                terms[tcnt].pr_min_score             = ct->pr_min_score;
                terms[tcnt].pr_mean_score            = ct->pr_mean_score;
                terms[tcnt].pr_score_variance        = ct->pr_score_variance;
                terms[tcnt].pr_score_stddev          = ct->pr_score_stddev;
                terms[tcnt].pr_score_harmonic_mean   = ct->pr_score_harmonic_mean;
                tcnt++;
            } else {
                // printf ("TERM=%s not found.\n", term);
            }
        }
    }

    if (tcnt == 0) {
        fprintf(stderr, "WARN: No bigrams for Query %d\n in collection.\n", qnum);
        if (!count_done) {
            fprintf(stderr, "WARN: Can't fill zeros count not complete.\n");
        }
        int i;
        for (i = 0; i < feature_count; ++i) {
            ffmt(buf, 0);
        }
    } else {
        /* Do this for each metric - BM25*/
        ffmt(buf, tcnt);
        {
            long double acdf    = 0.0;
            double      agm     = 0.0;
            double      aimpact = 0.0;
            double      amean   = 0.0;
            double      amedian = 0.0;
            double      ahmean  = 0.0;
            double      avar    = 0.0;
            double      aiqr    = 0.0;

            double   min = DBL_MAX, max = 0.0;
            double   min_mean = DBL_MAX, max_mean = 0.0;
            double   min_hmean = DBL_MAX, max_hmean = 0.0;
            double   min_median = DBL_MAX, max_median = 0.0;
            double   min_fq = DBL_MAX, max_fq = 0.0;
            double   min_tq = DBL_MAX, max_tq = 0.0;
            double   min_var = DBL_MAX, max_var = 0.0;
            uint64_t cdf_max = 0, cdf_min = UINT64_MAX;
            double   gm_min = DBL_MAX, gm_max = 0.0;

            qsort(terms, tcnt, sizeof(bigram_t), max_score_bigram_cmp);
            for (i = 0; i < tcnt; i++) {
                if (terms[i].bm25_max_score < min)
                    min = terms[i].bm25_max_score;
                if (terms[i].bm25_max_score > max)
                    max = terms[i].bm25_max_score;
                if (terms[i].bm25_mean_score < min_mean)
                    min_mean = terms[i].bm25_mean_score;
                if (terms[i].bm25_mean_score > max_mean)
                    max_mean = terms[i].bm25_mean_score;
                if (terms[i].bm25_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].bm25_score_harmonic_mean;
                if (terms[i].bm25_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].bm25_score_harmonic_mean;
                if (terms[i].bm25_median_score < min_median)
                    min_median = terms[i].bm25_median_score;
                if (terms[i].bm25_median_score > max_median)
                    max_median = terms[i].bm25_median_score;
                if (terms[i].bm25_firstq_score < min_fq)
                    min_fq = terms[i].bm25_firstq_score;
                if (terms[i].bm25_firstq_score > max_fq)
                    max_fq = terms[i].bm25_firstq_score;
                if (terms[i].bm25_thirdq_score < min_tq)
                    min_tq = terms[i].bm25_thirdq_score;
                if (terms[i].bm25_thirdq_score > max_tq)
                    max_tq = terms[i].bm25_thirdq_score;
                if (terms[i].bm25_score_variance < min_var)
                    min_var = terms[i].bm25_score_variance;
                if (terms[i].bm25_score_variance > max_var)
                    max_var = terms[i].bm25_score_variance;
                if (terms[i].cdf < cdf_min)
                    cdf_min = terms[i].cdf;
                if (terms[i].cdf > cdf_max)
                    cdf_max = terms[i].cdf;
                if (terms[i].geo_mean < gm_min)
                    gm_min = terms[i].geo_mean;
                if (terms[i].geo_mean > gm_max)
                    gm_max = terms[i].geo_mean;

                acdf += terms[i].cdf;
                agm += terms[i].geo_mean;
                aimpact += terms[i].bm25_max_score;
                amean += terms[i].bm25_mean_score;
                ahmean += terms[i].bm25_score_harmonic_mean;
                amedian += terms[i].bm25_median_score;
                avar += terms[i].bm25_score_variance;
                aiqr += (terms[i].bm25_firstq_score - terms[i].bm25_thirdq_score);
            }
            ffmt(buf, rintl(acdf / tcnt));
            ffmt(buf, agm / tcnt);
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, cdf_min);
            ffmt(buf, cdf_max);
            ffmt(buf, gm_min);
            ffmt(buf, gm_max);
            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - TFIDF*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min = DBL_MAX, max = 0.0;
            double min_mean = DBL_MAX, max_mean = 0.0;
            double min_hmean = DBL_MAX, max_hmean = 0.0;
            double min_median = DBL_MAX, max_median = 0.0;
            double min_fq = DBL_MAX, max_fq = 0.0;
            double min_tq = DBL_MAX, max_tq = 0.0;
            double min_var = DBL_MAX, max_var = 0.0;

            qsort(terms, tcnt, sizeof(bigram_t), tf_max_score_bigram_cmp);
            for (i = 0; i < tcnt; i++) {
                if (terms[i].tf_max_score < min)
                    min = terms[i].tf_max_score;
                if (terms[i].tf_max_score > max)
                    max = terms[i].tf_max_score;
                if (terms[i].tf_mean_score < min_mean)
                    min_mean = terms[i].tf_mean_score;
                if (terms[i].tf_mean_score > max_mean)
                    max_mean = terms[i].tf_mean_score;
                if (terms[i].tf_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].tf_score_harmonic_mean;
                if (terms[i].tf_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].tf_score_harmonic_mean;
                if (terms[i].tf_median_score < min_median)
                    min_median = terms[i].tf_median_score;
                if (terms[i].tf_median_score > max_median)
                    max_median = terms[i].tf_median_score;
                if (terms[i].tf_firstq_score < min_fq)
                    min_fq = terms[i].tf_firstq_score;
                if (terms[i].tf_firstq_score > max_fq)
                    max_fq = terms[i].tf_firstq_score;
                if (terms[i].tf_thirdq_score < min_tq)
                    min_tq = terms[i].tf_thirdq_score;
                if (terms[i].tf_thirdq_score > max_tq)
                    max_tq = terms[i].tf_thirdq_score;
                if (terms[i].tf_score_variance < min_var)
                    min_var = terms[i].tf_score_variance;
                if (terms[i].tf_score_variance > max_var)
                    max_var = terms[i].tf_score_variance;

                aimpact += terms[i].tf_max_score;
                amean += terms[i].tf_mean_score;
                ahmean += terms[i].tf_score_harmonic_mean;
                amedian += terms[i].tf_median_score;
                avar += terms[i].tf_score_variance;
                aiqr += (terms[i].tf_firstq_score - terms[i].tf_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric LM*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min = DBL_MAX, max = 0.0;
            double min_mean = DBL_MAX, max_mean = 0.0;
            double min_hmean = DBL_MAX, max_hmean = 0.0;
            double min_median = DBL_MAX, max_median = 0.0;
            double min_fq = DBL_MAX, max_fq = 0.0;
            double min_tq = DBL_MAX, max_tq = 0.0;
            double min_var = DBL_MAX, max_var = 0.0;

            qsort(terms, tcnt, sizeof(bigram_t), lm_max_score_bigram_cmp);
            for (i = 0; i < tcnt; i++) {
                if (terms[i].lm_max_score < min)
                    min = terms[i].lm_max_score;
                if (terms[i].lm_max_score > max)
                    max = terms[i].lm_max_score;
                if (terms[i].lm_mean_score < min_mean)
                    min_mean = terms[i].lm_mean_score;
                if (terms[i].lm_mean_score > max_mean)
                    max_mean = terms[i].lm_mean_score;
                if (terms[i].lm_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].lm_score_harmonic_mean;
                if (terms[i].lm_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].lm_score_harmonic_mean;
                if (terms[i].lm_median_score < min_median)
                    min_median = terms[i].lm_median_score;
                if (terms[i].lm_median_score > max_median)
                    max_median = terms[i].lm_median_score;
                if (terms[i].lm_firstq_score < min_fq)
                    min_fq = terms[i].lm_firstq_score;
                if (terms[i].lm_firstq_score > max_fq)
                    max_fq = terms[i].lm_firstq_score;
                if (terms[i].lm_thirdq_score < min_tq)
                    min_tq = terms[i].lm_thirdq_score;
                if (terms[i].lm_thirdq_score > max_tq)
                    max_tq = terms[i].lm_thirdq_score;
                if (terms[i].lm_score_variance < min_var)
                    min_var = terms[i].lm_score_variance;
                if (terms[i].lm_score_variance > max_var)
                    max_var = terms[i].lm_score_variance;

                aimpact += terms[i].lm_max_score;
                amean += terms[i].lm_mean_score;
                ahmean += terms[i].lm_score_harmonic_mean;
                amedian += terms[i].lm_median_score;
                avar += terms[i].lm_score_variance;
                aiqr += (terms[i].lm_firstq_score - terms[i].lm_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - PR*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min = DBL_MAX, max = 0.0;
            double min_mean = DBL_MAX, max_mean = 0.0;
            double min_hmean = DBL_MAX, max_hmean = 0.0;
            double min_median = DBL_MAX, max_median = 0.0;
            double min_fq = DBL_MAX, max_fq = 0.0;
            double min_tq = DBL_MAX, max_tq = 0.0;
            double min_var = DBL_MAX, max_var = 0.0;

            qsort(terms, tcnt, sizeof(bigram_t), pr_max_score_bigram_cmp);
            for (i = 0; i < tcnt; i++) {
                if (terms[i].pr_max_score < min)
                    min = terms[i].pr_max_score;
                if (terms[i].pr_max_score > max)
                    max = terms[i].pr_max_score;
                if (terms[i].pr_mean_score < min_mean)
                    min_mean = terms[i].pr_mean_score;
                if (terms[i].pr_mean_score > max_mean)
                    max_mean = terms[i].pr_mean_score;
                if (terms[i].pr_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].pr_score_harmonic_mean;
                if (terms[i].pr_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].pr_score_harmonic_mean;
                if (terms[i].pr_median_score < min_median)
                    min_median = terms[i].pr_median_score;
                if (terms[i].pr_median_score > max_median)
                    max_median = terms[i].pr_median_score;
                if (terms[i].pr_firstq_score < min_fq)
                    min_fq = terms[i].pr_firstq_score;
                if (terms[i].pr_firstq_score > max_fq)
                    max_fq = terms[i].pr_firstq_score;
                if (terms[i].pr_thirdq_score < min_tq)
                    min_tq = terms[i].pr_thirdq_score;
                if (terms[i].pr_thirdq_score > max_tq)
                    max_tq = terms[i].pr_thirdq_score;
                if (terms[i].pr_score_variance < min_var)
                    min_var = terms[i].pr_score_variance;
                if (terms[i].pr_score_variance > max_var)
                    max_var = terms[i].pr_score_variance;

                aimpact += terms[i].pr_max_score;
                amean += terms[i].pr_mean_score;
                ahmean += terms[i].pr_score_harmonic_mean;
                amedian += terms[i].pr_median_score;
                avar += terms[i].pr_score_variance;
                aiqr += (terms[i].pr_firstq_score - terms[i].pr_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - BE*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min = DBL_MAX, max = 0.0;
            double min_mean = DBL_MAX, max_mean = 0.0;
            double min_hmean = DBL_MAX, max_hmean = 0.0;
            double min_median = DBL_MAX, max_median = 0.0;
            double min_fq = DBL_MAX, max_fq = 0.0;
            double min_tq = DBL_MAX, max_tq = 0.0;
            double min_var = DBL_MAX, max_var = 0.0;

            qsort(terms, tcnt, sizeof(bigram_t), be_max_score_bigram_cmp);
            for (i = 0; i < tcnt; i++) {
                if (terms[i].be_max_score < min)
                    min = terms[i].be_max_score;
                if (terms[i].be_max_score > max)
                    max = terms[i].be_max_score;
                if (terms[i].be_mean_score < min_mean)
                    min_mean = terms[i].be_mean_score;
                if (terms[i].be_mean_score > max_mean)
                    max_mean = terms[i].be_mean_score;
                if (terms[i].be_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].be_score_harmonic_mean;
                if (terms[i].be_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].be_score_harmonic_mean;
                if (terms[i].be_median_score < min_median)
                    min_median = terms[i].be_median_score;
                if (terms[i].be_median_score > max_median)
                    max_median = terms[i].be_median_score;
                if (terms[i].be_firstq_score < min_fq)
                    min_fq = terms[i].be_firstq_score;
                if (terms[i].be_firstq_score > max_fq)
                    max_fq = terms[i].be_firstq_score;
                if (terms[i].be_thirdq_score < min_tq)
                    min_tq = terms[i].be_thirdq_score;
                if (terms[i].be_thirdq_score > max_tq)
                    max_tq = terms[i].be_thirdq_score;
                if (terms[i].be_score_variance < min_var)
                    min_var = terms[i].be_score_variance;
                if (terms[i].be_score_variance > max_var)
                    max_var = terms[i].be_score_variance;

                aimpact += terms[i].be_max_score;
                amean += terms[i].be_mean_score;
                ahmean += terms[i].be_score_harmonic_mean;
                amedian += terms[i].be_median_score;
                avar += terms[i].be_score_variance;
                aiqr += (terms[i].be_firstq_score - terms[i].be_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - DPH*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min = DBL_MAX, max = 0.0;
            double min_mean = DBL_MAX, max_mean = 0.0;
            double min_hmean = DBL_MAX, max_hmean = 0.0;
            double min_median = DBL_MAX, max_median = 0.0;
            double min_fq = DBL_MAX, max_fq = 0.0;
            double min_tq = DBL_MAX, max_tq = 0.0;
            double min_var = DBL_MAX, max_var = 0.0;

            qsort(terms, tcnt, sizeof(bigram_t), dph_max_score_bigram_cmp);
            for (i = 0; i < tcnt; i++) {
                if (terms[i].dph_max_score < min)
                    min = terms[i].dph_max_score;
                if (terms[i].dph_max_score > max)
                    max = terms[i].dph_max_score;
                if (terms[i].dph_mean_score < min_mean)
                    min_mean = terms[i].dph_mean_score;
                if (terms[i].dph_mean_score > max_mean)
                    max_mean = terms[i].dph_mean_score;
                if (terms[i].dph_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].dph_score_harmonic_mean;
                if (terms[i].dph_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].dph_score_harmonic_mean;
                if (terms[i].dph_median_score < min_median)
                    min_median = terms[i].dph_median_score;
                if (terms[i].dph_median_score > max_median)
                    max_median = terms[i].dph_median_score;
                if (terms[i].dph_firstq_score < min_fq)
                    min_fq = terms[i].dph_firstq_score;
                if (terms[i].dph_firstq_score > max_fq)
                    max_fq = terms[i].dph_firstq_score;
                if (terms[i].dph_thirdq_score < min_tq)
                    min_tq = terms[i].dph_thirdq_score;
                if (terms[i].dph_thirdq_score > max_tq)
                    max_tq = terms[i].dph_thirdq_score;
                if (terms[i].dph_score_variance < min_var)
                    min_var = terms[i].dph_score_variance;
                if (terms[i].dph_score_variance > max_var)
                    max_var = terms[i].dph_score_variance;

                aimpact += terms[i].dph_max_score;
                amean += terms[i].dph_mean_score;
                ahmean += terms[i].dph_score_harmonic_mean;
                amedian += terms[i].dph_median_score;
                avar += terms[i].dph_score_variance;
                aiqr += (terms[i].dph_firstq_score - terms[i].dph_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
        /* Do this for each metric - DFR*/
        {
            double aimpact = 0.0;
            double amean   = 0.0;
            double amedian = 0.0;
            double ahmean  = 0.0;
            double avar    = 0.0;
            double aiqr    = 0.0;

            double min = DBL_MAX, max = 0.0;
            double min_mean = DBL_MAX, max_mean = 0.0;
            double min_hmean = DBL_MAX, max_hmean = 0.0;
            double min_median = DBL_MAX, max_median = 0.0;
            double min_fq = DBL_MAX, max_fq = 0.0;
            double min_tq = DBL_MAX, max_tq = 0.0;
            double min_var = DBL_MAX, max_var = 0.0;

            qsort(terms, tcnt, sizeof(bigram_t), dfr_max_score_bigram_cmp);
            for (i = 0; i < tcnt; i++) {
                if (terms[i].dfr_max_score < min)
                    min = terms[i].dfr_max_score;
                if (terms[i].dfr_max_score > max)
                    max = terms[i].dfr_max_score;
                if (terms[i].dfr_mean_score < min_mean)
                    min_mean = terms[i].dfr_mean_score;
                if (terms[i].dfr_mean_score > max_mean)
                    max_mean = terms[i].dfr_mean_score;
                if (terms[i].dfr_score_harmonic_mean < min_hmean)
                    min_hmean = terms[i].dfr_score_harmonic_mean;
                if (terms[i].dfr_score_harmonic_mean > max_hmean)
                    max_hmean = terms[i].dfr_score_harmonic_mean;
                if (terms[i].dfr_median_score < min_median)
                    min_median = terms[i].dfr_median_score;
                if (terms[i].dfr_median_score > max_median)
                    max_median = terms[i].dfr_median_score;
                if (terms[i].dfr_firstq_score < min_fq)
                    min_fq = terms[i].dfr_firstq_score;
                if (terms[i].dfr_firstq_score > max_fq)
                    max_fq = terms[i].dfr_firstq_score;
                if (terms[i].dfr_thirdq_score < min_tq)
                    min_tq = terms[i].dfr_thirdq_score;
                if (terms[i].dfr_thirdq_score > max_tq)
                    max_tq = terms[i].dfr_thirdq_score;
                if (terms[i].dfr_score_variance < min_var)
                    min_var = terms[i].dfr_score_variance;
                if (terms[i].dfr_score_variance > max_var)
                    max_var = terms[i].dfr_score_variance;

                aimpact += terms[i].dfr_max_score;
                amean += terms[i].dfr_mean_score;
                ahmean += terms[i].dfr_score_harmonic_mean;
                amedian += terms[i].dfr_median_score;
                avar += terms[i].dfr_score_variance;
                aiqr += (terms[i].dfr_firstq_score - terms[i].dfr_thirdq_score);
            }
            ffmt(buf, aimpact / tcnt);
            ffmt(buf, amean / tcnt);
            ffmt(buf, ahmean / tcnt);
            ffmt(buf, amedian / tcnt);
            ffmt(buf, aiqr / tcnt);
            ffmt(buf, avar / tcnt);

            ffmt(buf, min);
            ffmt(buf, max);
            ffmt(buf, min_mean);
            ffmt(buf, max_mean);
            ffmt(buf, min_median);
            ffmt(buf, max_median);
            ffmt(buf, min_hmean);
            ffmt(buf, max_hmean);
            ffmt(buf, min_var);
            ffmt(buf, max_var);
            ffmt(buf, min_fq);
            ffmt(buf, max_fq);
            ffmt(buf, min_tq);
            ffmt(buf, max_tq);
        }
    }

    free(terms);

    ret_buf = safe_strdup(buf->data);
    strbuf_free(buf);

    if (!count_done) {
        count_done = true;
    }

    return ret_buf;
}
