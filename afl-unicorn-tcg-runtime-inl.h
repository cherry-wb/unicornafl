/*
   american fuzzy lop++ - unicorn instrumentation
   ----------------------------------------------

   Originally written by Andrew Griffiths <agriffiths@google.com> and
                         Michal Zalewski

   Adapted for afl-unicorn by Dominik Maier <mail@dmnk.co>

   CompareCoverage and NeverZero counters by Andrea Fioraldi
                                  <andreafioraldi@gmail.com>

   Copyright 2015, 2016, 2017 Google Inc. All rights reserved.
   Copyright 2019 AFLplusplus Project. All rights reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at:

     http://www.apache.org/licenses/LICENSE-2.0

   This code is a shim patched into the separately-distributed source
   code of Unicorn 1.0.1. It leverages the built-in QEMU tracing functionality
   to implement AFL-style instrumentation and to take care of the remaining
   parts of the AFL fork server logic.

   The resulting libunicorn binary is essentially a standalone instrumentation
   tool; for an example of how to leverage it for other purposes, you can
   have a look at afl-showmap.c.

 */

#include "uc_priv.h"
#include "afl-unicorn-common.h"

/* This is the main instrumentation function, patched in at translate.
   cur_loc has already been shifted in afl-unicorn-translate-inl.h at this point. 
   Also this helper will only be emitted if running instrumented. */

void HELPER(afl_maybe_log)(void* uc_ptr, uint64_t cur_loc, uint64_t real_loc) {

  struct uc_struct* uc = (struct uc_struct*) uc_ptr;
  u8* afl_area_ptr = uc->afl_area_ptr; // Don't remove, it's used by INC_AFL_AREA implicitly;

  register uintptr_t afl_idx = cur_loc ^ uc->afl_prev_loc;

  INC_AFL_AREA(afl_idx);

#if defined(AFL_DEBUG)
  printf("[d] At loc 0x%lx: prev: 0x%lx, afl_idx: %lu, map[afl_idx]: %d\n", cur_loc, uc->afl_prev_loc, afl_idx, afl_area_ptr[afl_idx]);
#endif

  uc->afl_prev_loc = cur_loc >> 1;

  if (uc->__afl_trace_record_counter < uc->__afl_trace_record_max){
     uc->__afl_trace_record_counter++;
     uc->__afl_trace_record_ptr[uc->__afl_trace_record_counter] = real_loc;
  }

}

void HELPER(afl_compcov_log_16)(void* uc_ptr, uint64_t cur_loc, uint32_t arg1,
                                uint32_t arg2) {

  u8* afl_area_ptr = ((struct uc_struct*)uc_ptr)->afl_area_ptr;

  if ((arg1 & 0xff00) == (arg2 & 0xff00)) { INC_AFL_AREA(cur_loc); }

}

void HELPER(afl_compcov_log_32)(void* uc_ptr, uint64_t cur_loc, uint32_t arg1,
                                uint32_t arg2) {

  u8* afl_area_ptr = ((struct uc_struct*)uc_ptr)->afl_area_ptr;

  if ((arg1 & 0xff000000) == (arg2 & 0xff000000)) {

    INC_AFL_AREA(cur_loc + 2);
    if ((arg1 & 0xff0000) == (arg2 & 0xff0000)) {

      INC_AFL_AREA(cur_loc + 1);
      if ((arg1 & 0xff00) == (arg2 & 0xff00)) { INC_AFL_AREA(cur_loc); }

    }

  }

}

void HELPER(afl_compcov_log_64)(void* uc_ptr, uint64_t cur_loc, uint64_t arg1,
                                uint64_t arg2) {

  u8* afl_area_ptr = ((struct uc_struct*)uc_ptr)->afl_area_ptr;

  if ((arg1 & 0xff00000000000000) == (arg2 & 0xff00000000000000)) {

    INC_AFL_AREA(cur_loc + 6);
    if ((arg1 & 0xff000000000000) == (arg2 & 0xff000000000000)) {

      INC_AFL_AREA(cur_loc + 5);
      if ((arg1 & 0xff0000000000) == (arg2 & 0xff0000000000)) {

        INC_AFL_AREA(cur_loc + 4);
        if ((arg1 & 0xff00000000) == (arg2 & 0xff00000000)) {

          INC_AFL_AREA(cur_loc + 3);
          if ((arg1 & 0xff000000) == (arg2 & 0xff000000)) {

            INC_AFL_AREA(cur_loc + 2);
            if ((arg1 & 0xff0000) == (arg2 & 0xff0000)) {

              INC_AFL_AREA(cur_loc + 1);
              if ((arg1 & 0xff00) == (arg2 & 0xff00)) { INC_AFL_AREA(cur_loc); }

            }

          }

        }

      }

    }

  }

}

void HELPER(afl_cmplog_8)(void* uc_ptr, uint64_t cur_addr, uint32_t arg1,
                           uint32_t arg2, uint32_t is_imm_loc_v) {
  struct uc_struct* uc_ptr_t = (struct uc_struct*)uc_ptr;
  if (uc_ptr_t->__afl_cmp_record_counter < uc_ptr_t->__afl_cmp_record_max){
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.ins_type = 1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.addr = (uint32_t) (cur_addr);
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.is_IMM = is_imm_loc_v;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.shape = 1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].log.v0 = arg1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].log.v1 = arg2;
    uc_ptr_t->__afl_cmp_record_counter++;
  }
}

void HELPER(afl_cmplog_16)(void* uc_ptr, uint64_t cur_addr, uint32_t arg1,
                           uint32_t arg2, uint32_t is_imm_loc_v) {
  struct uc_struct* uc_ptr_t = (struct uc_struct*)uc_ptr;
  if (uc_ptr_t->__afl_cmp_record_counter < uc_ptr_t->__afl_cmp_record_max){
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.ins_type = 1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.addr = (uint32_t) (cur_addr);
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.is_IMM = is_imm_loc_v;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.shape = 2;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].log.v0 = arg1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].log.v1 = arg2;
    uc_ptr_t->__afl_cmp_record_counter++;
  }
}

void HELPER(afl_cmplog_32)(void* uc_ptr, uint64_t cur_addr, uint32_t arg1,
                           uint32_t arg2, uint32_t is_imm_loc_v) {
  struct uc_struct* uc_ptr_t = (struct uc_struct*)uc_ptr;
  if (uc_ptr_t->__afl_cmp_record_counter < uc_ptr_t->__afl_cmp_record_max){
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.ins_type = 1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.addr = (uint32_t) (cur_addr);
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.is_IMM = is_imm_loc_v;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.shape = 4;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].log.v0 = arg1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].log.v1 = arg2;
    uc_ptr_t->__afl_cmp_record_counter++;
  }
}

void HELPER(afl_cmplog_64)(void* uc_ptr, uint64_t cur_addr, uint64_t arg1,
                           uint64_t arg2, uint32_t is_imm_loc_v) {
  struct uc_struct* uc_ptr_t = (struct uc_struct*)uc_ptr;
  if (uc_ptr_t->__afl_cmp_record_counter < uc_ptr_t->__afl_cmp_record_max){
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.ins_type = 1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.addr = (uint32_t) (cur_addr);
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.is_IMM = is_imm_loc_v;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].header.shape = 8;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].log.v0 = arg1;
    uc_ptr_t->__afl_cmp_map[uc_ptr_t->__afl_cmp_record_counter].log.v1 = arg2;
    uc_ptr_t->__afl_cmp_record_counter++;
  }
}

