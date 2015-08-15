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


#ifndef INCLUDED_BASICS_STROBE_BB_H
#define INCLUDED_BASICS_STROBE_BB_H

#include <basics/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace basics {

    /*!
     * \brief If enabled, copies input to output; otherwise drops input.
     * \ingroup basics
     *
     */
    class BASICS_API strobe_bb : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<strobe_bb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of basics::strobe_bb.
       *
       * To avoid accidental use of raw pointers, basics::strobe_bb's
       * constructor is in a private implementation
       * class. basics::strobe_bb::make is the public interface for
       * creating new instances.
       *
       * \param level_min The minimum level of clock that will trigger the
       *                  strobe (example: 1).
       *
       * \param level_max The maximum level of clock required to trigger the
       *                  strobe (example: 255).
       */
      static sptr make(unsigned char level_min, unsigned char level_max);
    };

  } // namespace basics
} // namespace gr

#endif /* INCLUDED_BASICS_STROBE_BB_H */

