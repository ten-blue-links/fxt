#pragma once

class doc_stream_feature {

   public:
    void compute(query_train &qry, doc_entry &doc, Document &doc_idx, FieldIdMap &field_id_map) {

        auto body_id = field_id_map["body"];
        auto title_id = field_id_map["title"];
        auto heading_id = field_id_map["heading"];
        auto inlink_id = field_id_map["inlink"];
        auto a_id = field_id_map["a"];

        // stream length is set for the score member variables
        doc.stream_len       = doc_idx.length();
        doc.stream_len_body  = doc_idx.field_len(body_id);
        doc.stream_len_title = doc_idx.field_len(title_id);
        // penalise docs with more than 1 title tag
        if (doc_idx.tag_count(title_id) > 1) {
            doc.stream_len_title = -doc.stream_len_title;
        }
        doc.stream_len_heading = doc_idx.field_len(heading_id);
        doc.stream_len_inlink  = doc_idx.field_len(inlink_id);
        doc.stream_len_a       = doc_idx.field_len(a_id);

        double doc_tf     = 0;
        double body_tf    = 0;
        double title_tf   = 0;
        double heading_tf = 0;
        double inlink_tf  = 0;
        double a_tf       = 0;

        for (auto &q : qry.q_ft) {
            doc_tf += doc_idx.freq(q.first);
            body_tf += doc_idx.freq(body_id, q.first);
            title_tf += doc_idx.freq(title_id, q.first);
            heading_tf += doc_idx.freq(heading_id, q.first);
            inlink_tf += doc_idx.freq(inlink_id, q.first);
            a_tf += doc_idx.freq(a_id, q.first);
        }

        if (doc_tf) {
            doc.sum_stream_len  = (double)doc_idx.length() / doc_tf;
            doc.min_stream_len  = doc.sum_stream_len;
            doc.max_stream_len  = doc.sum_stream_len;
            doc.mean_stream_len = doc.sum_stream_len;
            doc.variance_stream_len =
                ((double)doc_idx.length() - doc_idx.length() * doc_idx.length()) / doc_tf;
        }
        if (body_tf) {
            doc.sum_stream_len_body  = (double)doc_idx.field_len(body_id) / body_tf;
            doc.min_stream_len_body  = (double)doc_idx.field_min_len(body_id) / body_tf;
            doc.max_stream_len_body  = (double)doc_idx.field_max_len(body_id) / body_tf;
            doc.mean_stream_len_body = (double)((double)doc_idx.field_len(body_id) /
                                                doc_idx.tag_count(body_id)) /
                                       body_tf;
            doc.variance_stream_len_body =
                (((double)doc_idx.field_len_sum_sqrs(body_id) / doc_idx.field_len(body_id)) -
                 ((double)doc_idx.field_len(body_id) /
                  doc_idx.tag_count(body_id)) *
                     ((double)doc_idx.field_len(body_id) /
                      doc_idx.tag_count(body_id))) /
                body_tf;
        }
        if (title_tf) {
            doc.sum_stream_len_title = (double)doc_idx.field_len(title_id) / title_tf;
            doc.min_stream_len_title = (double)doc_idx.field_min_len(title_id) / title_tf;
            doc.max_stream_len_title = (double)doc_idx.field_max_len(title_id) / title_tf;
            doc.mean_stream_len_title = (double)((double)doc_idx.field_len(title_id) /
                                                 doc_idx.tag_count(title_id)) /
                                        title_tf;
            doc.variance_stream_len_title = (((double)doc_idx.field_len_sum_sqrs(title_id) /
                                              doc_idx.field_len(title_id)) -
                                             ((double)doc_idx.field_len(title_id) /
                                              doc_idx.tag_count(title_id)) *
                                                 ((double)doc_idx.field_len(title_id) /
                                                  doc_idx.tag_count(title_id))) /
                                            title_tf;
        }
        if (heading_tf) {
            doc.sum_stream_len_heading =
                (double)doc_idx.field_len(heading_id) / heading_tf;
            doc.min_stream_len_heading =
                (double)doc_idx.field_min_len(heading_id) / heading_tf;
            doc.max_stream_len_heading =
                (double)doc_idx.field_max_len(heading_id) / heading_tf;
            doc.mean_stream_len_heading = (double)((double)doc_idx.field_len(heading_id) /
                                                   doc_idx.tag_count(heading_id)) /
                                          heading_tf;
            doc.variance_stream_len_heading =
                (((double)doc_idx.field_len_sum_sqrs(heading_id) /
                  doc_idx.field_len(heading_id)) -
                 ((double)doc_idx.field_len(heading_id) /
                  doc_idx.tag_count(heading_id)) *
                     ((double)doc_idx.field_len(heading_id) /
                      doc_idx.tag_count(heading_id))) /
                heading_tf;
        }
        if (inlink_tf) {
            doc.sum_stream_len_inlink = (double)doc_idx.field_len(inlink_id) / inlink_tf;
            doc.min_stream_len_inlink =
                (double)doc_idx.field_min_len(inlink_id) / inlink_tf;
            doc.max_stream_len_inlink =
                (double)doc_idx.field_max_len(inlink_id) / inlink_tf;
            doc.mean_stream_len_inlink = (double)((double)doc_idx.field_len(inlink_id) /
                                                  doc_idx.tag_count(inlink_id)) /
                                         inlink_tf;
            doc.variance_stream_len_inlink = (((double)doc_idx.field_len_sum_sqrs(inlink_id) /
                                               doc_idx.field_len(inlink_id)) -
                                              ((double)doc_idx.field_len(inlink_id) /
                                               doc_idx.tag_count(inlink_id)) *
                                                  ((double)doc_idx.field_len(inlink_id) /
                                                   doc_idx.tag_count(inlink_id))) /
                                             inlink_tf;
        }
        if (a_tf) {
            doc.sum_stream_len_a  = (double)doc_idx.field_len(a_id) / a_tf;
            doc.min_stream_len_a  = (double)doc_idx.field_min_len(a_id) / a_tf;
            doc.max_stream_len_a  = (double)doc_idx.field_max_len(a_id) / a_tf;
            doc.mean_stream_len_a = (double)((double)doc_idx.field_len(a_id) /
                                             doc_idx.tag_count(a_id)) /
                                    a_tf;
            doc.variance_stream_len_a =
                (((double)doc_idx.field_len_sum_sqrs(a_id) / doc_idx.field_len(a_id)) -
                 ((double)doc_idx.field_len(a_id) / doc_idx.tag_count(a_id)) *
                     ((double)doc_idx.field_len(a_id) /
                      doc_idx.tag_count(a_id))) /
                a_tf;
        }
    }
};
