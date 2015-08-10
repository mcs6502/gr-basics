/* -*- c++ -*- */

#define BASICS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "basics_swig_doc.i"

%{
#include "basics/strobe.h"
%}


%include "basics/strobe.h"
GR_SWIG_BLOCK_MAGIC2(basics, strobe);
