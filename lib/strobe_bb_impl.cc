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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "strobe_bb_impl.h"

namespace gr {
  namespace basics {

    strobe_bb::sptr
    strobe_bb::make(unsigned char level_min, unsigned char level_max)
    {
      return gnuradio::get_initial_sptr
        (new strobe_bb_impl(level_min, level_max));
    }

    /*
     * The private constructor
     */
    strobe_bb_impl::strobe_bb_impl(unsigned char level_min,
        unsigned char level_max)
      : gr::block("strobe_bb",
              gr::io_signature::make(2, 2, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char))),
        d_level_min(level_min), d_level_max(level_max)
    {}

    /*
     * Our virtual destructor.
     */
    strobe_bb_impl::~strobe_bb_impl()
    {
    }

    int
    strobe_bb_impl::general_work (int noutput_items,
                                  gr_vector_int &ninput_items,
                                  gr_vector_const_void_star &input_items,
                                  gr_vector_void_star &output_items)
    {
        const unsigned char *in  = (const unsigned char *) input_items[0];
        const unsigned char *clk = (const unsigned char *) input_items[1];
        unsigned char *out       = (unsigned char *) output_items[0];

        unsigned char level_min  = d_level_min;
        unsigned char level_max  = d_level_max;

        int n = std::min(noutput_items,
                         std::min(ninput_items[0],
                                  ninput_items[1]));
        int j = 0;

        for(int i = 0; i < n; ++i) {
            unsigned char c = clk[i];
            if (c >= level_min && c <= level_max) {
                out[j] = in[i];
                ++j;
            }
        }

        consume_each(n);

        // Tell runtime system how many output items we produced.
        return j;
    }

  } /* namespace basics */
} /* namespace gr */

