// Copyright 2022 Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

/* common way to execute a testbench, sorry for the lame C-style macro */

/* used by multiple designs */
#include <chrono>

// Design-specific headers.
#include "testbench.h"

#include <iostream>
#include <cassert>
#include <sstream>

static const char *cl_get_tracefile(void)
{
#if VM_TRACE
  const char *trace_env = std::getenv("TRACEFILE"); // allow override for batch execution from python
  if(trace_env == NULL) { std::cerr << "TRACEFILE environment variable not set." << std::endl; exit(1); }
  return trace_env;
#else
  return "";
#endif
}
static const char *cl_get_recordingfile(void)
{
  const char *trace_env = std::getenv("RECORDINGFILE"); // allow override for batch execution from python
  if(trace_env == NULL) { std::cerr << "RECORDINGFILE environment variable not set." << std::endl; exit(1); }
  return trace_env;
}
