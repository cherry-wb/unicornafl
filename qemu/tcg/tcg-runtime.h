DEF_HELPER_FLAGS_2(div_i32, TCG_CALL_NO_RWG_SE, s32, s32, s32)
DEF_HELPER_FLAGS_2(rem_i32, TCG_CALL_NO_RWG_SE, s32, s32, s32)
DEF_HELPER_FLAGS_2(divu_i32, TCG_CALL_NO_RWG_SE, i32, i32, i32)
DEF_HELPER_FLAGS_2(remu_i32, TCG_CALL_NO_RWG_SE, i32, i32, i32)

DEF_HELPER_FLAGS_2(div_i64, TCG_CALL_NO_RWG_SE, s64, s64, s64)
DEF_HELPER_FLAGS_2(rem_i64, TCG_CALL_NO_RWG_SE, s64, s64, s64)
DEF_HELPER_FLAGS_2(divu_i64, TCG_CALL_NO_RWG_SE, i64, i64, i64)
DEF_HELPER_FLAGS_2(remu_i64, TCG_CALL_NO_RWG_SE, i64, i64, i64)

DEF_HELPER_FLAGS_2(shl_i64, TCG_CALL_NO_RWG_SE, i64, i64, i64)
DEF_HELPER_FLAGS_2(shr_i64, TCG_CALL_NO_RWG_SE, i64, i64, i64)
DEF_HELPER_FLAGS_2(sar_i64, TCG_CALL_NO_RWG_SE, s64, s64, s64)

DEF_HELPER_FLAGS_2(mulsh_i64, TCG_CALL_NO_RWG_SE, s64, s64, s64)
DEF_HELPER_FLAGS_2(muluh_i64, TCG_CALL_NO_RWG_SE, i64, i64, i64)

#if defined(UNICORN_AFL)
DEF_HELPER_FLAGS_3(afl_maybe_log, 0, void, ptr, i64, i64)
DEF_HELPER_FLAGS_4(afl_compcov_log_16, 0, void, ptr, i64, i32, i32)
DEF_HELPER_FLAGS_4(afl_compcov_log_32, 0, void, ptr, i64, i32, i32)
DEF_HELPER_FLAGS_4(afl_compcov_log_64, 0, void, ptr, i64, i64, i64)
DEF_HELPER_FLAGS_5(afl_cmplog_8, 0, void, ptr, i64, i32, i32, i32)
DEF_HELPER_FLAGS_5(afl_cmplog_16, 0, void, ptr, i64, i32, i32, i32)
DEF_HELPER_FLAGS_5(afl_cmplog_32, 0, void, ptr, i64, i32, i32, i32)
DEF_HELPER_FLAGS_5(afl_cmplog_64, 0, void, ptr, i64, i64, i64, i32)
#endif
