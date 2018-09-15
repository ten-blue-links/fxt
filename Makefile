BIN := build/bin

INDRI_INDEX :=
QUERIES :=
STAGE0 :=

FWD := index.fwd
INV := index.inv
LEX := index.lex
LENS := index.lens
BIGRAM_INV := index_bigram.inv
UNIGRAM := index_unigram.txt
BIGRAM := index_bigram.txt
DOCFEAT := index_docfeat.csv
TERMFEAT := index_termfeat.csv
ALL_CSV := all.csv
ALL_SVM := all.svm

$(FWD):
	$(BIN)/create_forward_index $(INDRI_INDEX) $@

$(INV):
	$(BIN)/create_inverted_index $(INDRI_INDEX) $@

$(LEX):
	$(BIN)/create_lexicon $(INDRI_INDEX) $@

$(LENS):
	$(BIN)/create_doc_lens $(INDRI_INDEX) $@

$(BIGRAM_INV): $(QUERIES) $(LEX)
	$(BIN)/create_bigram_inverted_index -r $(INDRI_INDEX) -q $(QUERIES) -l $(LEX) -o $@

$(UNIGRAM): $(INV) $(LENS)
	$(BIN)/generate_term_features -i $(INV) -d $(LENS) -o $@

$(BIGRAM): $(BIGRAM_INV) $(LENS)
	$(BIN)/generate_term_features -i $(BIGRAM_INV) -d $(LENS) -o $@

$(DOCFEAT): $(STAGE0) $(FWD) $(LEX)
	$(BIN)/generate_document_features $(QUERIES) $(STAGE0) $(INDRI_INDEX) $(FWD) $(LEX) $@

$(TERMFEAT): $(UNIGRAM) $(BIGRAM) $(LEX)
	$(BIN)/preret_csv $(QUERIES) $(UNIGRAM) $(BIGRAM) $(LEX)\
	    | sed -E 's/\-?nan/0.00000/g' > $@

$(ALL_CSV): $(DOCFEAT) $(TERMFEAT)
	script/termfeat_expand.awk $(DOCFEAT) $(TERMFEAT) | sed -E 's/[^,]+,//' > termfeat_expanded.tmp
	paste -d, $(DOCFEAT) termfeat_expanded.tmp > $(ALL_CSV)
	rm termfeat_expanded.tmp

$(ALL_SVM): $(ALL_CSV)
	script/csv2svm.awk $(ALL_CSV) > $(ALL_SVM)

all: $(ALL_SVM)
