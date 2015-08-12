/* -*- c++ -*- */

#define BASICS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "basics_swig_doc.i"

%{
#include "basics/strobe_bb.h"
%}


%include "basics/strobe_bb.h"
GR_SWIG_BLOCK_MAGIC2(basics, strobe_bb);
