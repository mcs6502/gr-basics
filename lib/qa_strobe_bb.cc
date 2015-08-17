/* -*- c++ -*- */
/* 
 * Copyright 2015 Igor Mironov.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#include <gnuradio/attributes.h>
#include <gnuradio/top_block.h>
#include <gnuradio/blocks/vector_sink_b.h>
#include <gnuradio/blocks/vector_source_b.h>
#include <cppunit/TestAssert.h>
#include "qa_strobe_bb.h"
#include <basics/strobe_bb.h>

#include <iostream>

namespace gr {
  namespace basics {

    static void print_vector(const std::vector<unsigned char> &v) {
        std::ostream &out = std::cerr;
        out << "v.size()=" << v.size();
        for (std::vector<unsigned char>::const_iterator i = v.begin();
            i != v.end(); ++i) {
            out << ' ' << static_cast<int>(*i);
        }
        if (v.begin() != v.end())
            out << std::endl;
    }

    void
    qa_strobe_bb::t1()
    {
        gr::top_block_sptr tb(gr::make_top_block("t1"));

        const unsigned char input[] = "01234567";
        size_t input_len = sizeof(input) - 1;

        const unsigned char clock[] = {1, 0, 0, 0, 0, 0, 128, 255};
        size_t clock_len = sizeof(clock);

        const unsigned char output[] = "067";
        size_t output_len = sizeof(output) - 1;

        gr::blocks::vector_source_b::sptr src(
            gr::blocks::vector_source_b::make(std::vector<unsigned char>(
                input, input + input_len)));

        gr::blocks::vector_source_b::sptr clk(
            gr::blocks::vector_source_b::make(std::vector<unsigned char>(
                clock, clock + clock_len)));

        unsigned char level_min = 1;
        unsigned char level_max = 255;
        gr::basics::strobe_bb::sptr blk(gr::basics::strobe_bb::make(
            level_min, level_max));

        gr::blocks::vector_sink_b::sptr dst(gr::blocks::vector_sink_b::make());

        tb->connect(src, 0, blk, 0);
        tb->connect(clk, 0, blk, 1);
        tb->connect(blk, 0, dst, 0);
        tb->run();

        std::vector<unsigned char> expected_data(output, output + output_len);
        print_vector(expected_data);

        const std::vector<unsigned char> &actual_data = dst->data();
        print_vector(actual_data);

        CPPUNIT_ASSERT(expected_data == actual_data);
    }

  } /* namespace basics */
} /* namespace gr */

