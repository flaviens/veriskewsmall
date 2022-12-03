// Copyright Flavien Solt, ETH Zurich.
// Licensed under the General Public License, Version 3.0, see LICENSE for details.
// SPDX-License-Identifier: GPL-3.0-only

#include "Vwt_axi_adapter.h"
#include "verilated.h"

#if VM_TRACE
#if VM_TRACE_FST
#include <verilated_fst_c.h>
#else
#include <verilated_vcd_c.h>
#endif // VM_TRACE_FST
#endif // VM_TRACE

#include <iostream>
#include <fstream>
#include <stdlib.h>

#ifndef TESTBENCH_H
#define TESTBENCH_H

#if VM_TRACE
// Depth of the trace.
const int kTraceLevel = 6;
#endif // VM_TRACE

typedef Vwt_axi_adapter Module;

typedef struct {
// Adapter
  uint32_t clk_i;                // 1 bit
  uint32_t rst_ni;               // 1 bit
  uint32_t icache_data_req_i;    // 1 bit
  uint32_t dcache_data_req_i;    // 1 bit
  uint64_t icache_data_i;        // 61 bits
  uint32_t dcache_data_i[5];     // 135 bits
  uint32_t axi_resp_i[3];        // 86 bits
  uint32_t icache_data_req_i_t0; // 1 bit
  uint32_t dcache_data_req_i_t0; // 1 bit
  uint64_t icache_data_i_t0;     // 61 bits
  uint32_t dcache_data_i_t0[5];  // 135 bits
  uint32_t axi_resp_i_t0[3];     // 86 bits

// Mem top
  // uint64_t boot_addr_i;
  // uint64_t boot_addr_i_t0;
  // uint64_t clk_i;
  // uint64_t debug_req_i;
  // uint64_t debug_req_i_t0;
  // uint64_t hart_id_i;
  // uint64_t hart_id_i_t0;
  // uint64_t ipi_i;
  // uint64_t ipi_i_t0;
  // uint64_t irq_i;
  // uint64_t irq_i_t0;
  // uint64_t mem_gnt_i;
  // uint64_t mem_gnt_i_t0;
  // uint64_t mem_rdata_i;
  // uint64_t mem_rdata_i_t0;
  // uint64_t rst_ni;
  // uint64_t time_irq_i;
  // uint64_t time_irq_i_t0;

// CVA6
  // uint64_t axi_resp_i[3];
  // uint64_t axi_resp_i_t0[3];
  // uint64_t boot_addr_i;
  // uint64_t boot_addr_i_t0;
  // uint64_t clk_i;
  // uint64_t cvxif_resp_i[8];
  // uint64_t cvxif_resp_i_t0[8];
  // uint64_t debug_req_i;
  // uint64_t debug_req_i_t0;
  // uint64_t hart_id_i;
  // uint64_t hart_id_i_t0;
  // uint64_t ipi_i;
  // uint64_t ipi_i_t0;
  // uint64_t irq_i;
  // uint64_t irq_i_t0;
  // uint64_t rst_ni;
  // uint64_t time_irq_i;
  // uint64_t time_irq_i_t0;

// Cache subsystem
  // uint64_t axi_resp_i[3];
  // uint64_t axi_resp_i_t0[3];
  // uint64_t clk_i;
  // uint64_t dcache_amo_req_i[5];
  // uint64_t dcache_amo_req_i_t0[5];
  // uint64_t dcache_enable_i;
  // uint64_t dcache_enable_i_t0;
  // uint64_t dcache_flush_i;
  // uint64_t dcache_flush_i_t0;
  // uint64_t dcache_req_ports_i[13];
  // uint64_t dcache_req_ports_i_t0[13];
  // uint64_t icache_areq_i[6];
  // uint64_t icache_areq_i_t0[6];
  // uint64_t icache_dreq_i[3];
  // uint64_t icache_dreq_i_t0[3];
  // uint64_t icache_en_i;
  // uint64_t icache_en_i_t0;
  // uint64_t icache_flush_i;
  // uint64_t icache_flush_i_t0;
  // uint64_t rst_ni;
} single_input_recording_t;

// This class implements elementary interaction with the design under test.
class Testbench {
 public:
  Testbench(const std::string &trace_filename = "")
      : module_(new Module), tick_count_(0l) {

#if VM_TRACE
#if VM_TRACE_FST
    trace_ = new VerilatedFstC;
#else // VM_TRACE_FST
    trace_ = new VerilatedVcdC;
#endif // VM_TRACE_FST
    module_->trace(trace_, kTraceLevel);
    trace_->open(trace_filename.c_str());
#endif // VM_TRACE
  }

  ~Testbench(void) { close_trace(); }

  void close_trace(void) {
#if VM_TRACE  
    trace_->close();
#endif // VM_TRACE
  }

  std::unique_ptr<Module> module_;
  #if VM_TRACE
  #if VM_TRACE_FST
    VerilatedFstC *trace_;
  #else // VM_TRACE_FST
    VerilatedVcdC *trace_;
  #endif // VM_TRACE_FST
  #endif // VM_TRACE
 private:
  vluint32_t tick_count_;


  // Masks that contain ones in the corresponding fields.
  uint32_t id_mask_;
  uint32_t content_mask_;
};

#endif // TESTBENCH_H
