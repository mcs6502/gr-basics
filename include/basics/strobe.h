/* -*- c++ -*- */
/* 
 * Copyright 2015 <+YOU OR YOUR COMPANY+>.
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


#ifndef INCLUDED_BASICS_STROBE_H
#define INCLUDED_BASICS_STROBE_H

#include <basics/api.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
  namespace basics {

    /*!
     * \brief <+description of block+>
     * \ingroup basics
     *
     */
    class BASICS_API strobe : virtual public gr::sync_decimator
    {
     public:
      typedef boost::shared_ptr<strobe> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of basics::strobe.
       *
       * To avoid accidental use of raw pointers, basics::strobe's
       * constructor is in a private implementation
       * class. basics::strobe::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace basics
} // namespace gr

#endif /* INCLUDED_BASICS_STROBE_H */

