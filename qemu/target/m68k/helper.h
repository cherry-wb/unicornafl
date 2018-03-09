DEF_HELPER_4(uc_tracecode, void, i32, i32, ptr, i64)

DEF_HELPER_1(bitrev, i32, i32)
DEF_HELPER_1(ff1, i32, i32)
DEF_HELPER_FLAGS_2(sats, TCG_CALL_NO_RWG_SE, i32, i32, i32)
DEF_HELPER_3(divuw, void, env, int, i32)
DEF_HELPER_3(divsw, void, env, int, s32)
DEF_HELPER_4(divul, void, env, int, int, i32)
DEF_HELPER_4(divsl, void, env, int, int, s32)
DEF_HELPER_4(divull, void, env, int, int, i32)
DEF_HELPER_4(divsll, void, env, int, int, s32)
DEF_HELPER_2(set_sr, void, env, i32)
DEF_HELPER_3(cf_movec_to, void, env, i32, i32)
DEF_HELPER_3(m68k_movec_to, void, env, i32, i32)
DEF_HELPER_2(m68k_movec_from, i32, env, i32)
DEF_HELPER_4(cas2w, void, env, i32, i32, i32)
DEF_HELPER_4(cas2l, void, env, i32, i32, i32)

#define dh_alias_fp ptr
#define dh_ctype_fp FPReg *
#define dh_is_signed_fp dh_is_signed_ptr

DEF_HELPER_3(exts32, void, env, fp, s32)
DEF_HELPER_3(extf32, void, env, fp, f32)
DEF_HELPER_3(extf64, void, env, fp, f64)
DEF_HELPER_2(redf32, f32, env, fp)
DEF_HELPER_2(redf64, f64, env, fp)
DEF_HELPER_2(reds32, s32, env, fp)

DEF_HELPER_3(fsround, void, env, fp, fp)
DEF_HELPER_3(fdround, void, env, fp, fp)
DEF_HELPER_3(firound, void, env, fp, fp)
DEF_HELPER_3(fitrunc, void, env, fp, fp)
DEF_HELPER_3(fsqrt, void, env, fp, fp)
DEF_HELPER_3(fssqrt, void, env, fp, fp)
DEF_HELPER_3(fdsqrt, void, env, fp, fp)
DEF_HELPER_3(fabs, void, env, fp, fp)
DEF_HELPER_3(fsabs, void, env, fp, fp)
DEF_HELPER_3(fdabs, void, env, fp, fp)
DEF_HELPER_3(fneg, void, env, fp, fp)
DEF_HELPER_3(fsneg, void, env, fp, fp)
DEF_HELPER_3(fdneg, void, env, fp, fp)
DEF_HELPER_4(fadd, void, env, fp, fp, fp)
DEF_HELPER_4(fsadd, void, env, fp, fp, fp)
DEF_HELPER_4(fdadd, void, env, fp, fp, fp)
DEF_HELPER_4(fsub, void, env, fp, fp, fp)
DEF_HELPER_4(fssub, void, env, fp, fp, fp)
DEF_HELPER_4(fdsub, void, env, fp, fp, fp)
DEF_HELPER_4(fmul, void, env, fp, fp, fp)
DEF_HELPER_4(fsmul, void, env, fp, fp, fp)
DEF_HELPER_4(fdmul, void, env, fp, fp, fp)
DEF_HELPER_4(fsglmul, void, env, fp, fp, fp)
DEF_HELPER_4(fdiv, void, env, fp, fp, fp)
DEF_HELPER_4(fsdiv, void, env, fp, fp, fp)
DEF_HELPER_4(fddiv, void, env, fp, fp, fp)
DEF_HELPER_4(fsgldiv, void, env, fp, fp, fp)
DEF_HELPER_FLAGS_3(fcmp, TCG_CALL_NO_RWG, void, env, fp, fp)
DEF_HELPER_FLAGS_2(set_fpcr, TCG_CALL_NO_RWG, void, env, i32)
DEF_HELPER_FLAGS_2(ftst, TCG_CALL_NO_RWG, void, env, fp)
DEF_HELPER_3(fconst, void, env, fp, i32)
DEF_HELPER_3(fmovemx_st_predec, i32, env, i32, i32)
DEF_HELPER_3(fmovemx_st_postinc, i32, env, i32, i32)
DEF_HELPER_3(fmovemx_ld_postinc, i32, env, i32, i32)
DEF_HELPER_3(fmovemd_st_predec, i32, env, i32, i32)
DEF_HELPER_3(fmovemd_st_postinc, i32, env, i32, i32)
DEF_HELPER_3(fmovemd_ld_postinc, i32, env, i32, i32)
DEF_HELPER_4(fmod, void, env, fp, fp, fp)
DEF_HELPER_4(frem, void, env, fp, fp, fp)

DEF_HELPER_3(mac_move, void, env, i32, i32)
DEF_HELPER_3(macmulf, i64, env, i32, i32)
DEF_HELPER_3(macmuls, i64, env, i32, i32)
DEF_HELPER_3(macmulu, i64, env, i32, i32)
DEF_HELPER_2(macsats, void, env, i32)
DEF_HELPER_2(macsatu, void, env, i32)
DEF_HELPER_2(macsatf, void, env, i32)
DEF_HELPER_2(mac_set_flags, void, env, i32)
DEF_HELPER_2(set_macsr, void, env, i32)
DEF_HELPER_2(get_macf, i32, env, i64)
DEF_HELPER_1(get_macs, i32, i64)
DEF_HELPER_1(get_macu, i32, i64)
DEF_HELPER_2(get_mac_extf, i32, env, i32)
DEF_HELPER_2(get_mac_exti, i32, env, i32)
DEF_HELPER_3(set_mac_extf, void, env, i32, i32)
DEF_HELPER_3(set_mac_exts, void, env, i32, i32)
DEF_HELPER_3(set_mac_extu, void, env, i32, i32)

DEF_HELPER_2(flush_flags, void, env, i32)
DEF_HELPER_2(set_ccr, void, env, i32)
DEF_HELPER_FLAGS_1(get_ccr, TCG_CALL_NO_WG_SE, i32, env)
DEF_HELPER_2(raise_exception, void, env, i32)

DEF_HELPER_FLAGS_3(bfffo_reg, TCG_CALL_NO_RWG_SE, i32, i32, i32, i32)

DEF_HELPER_FLAGS_4(bfexts_mem, TCG_CALL_NO_WG, i32, env, i32, s32, i32)
DEF_HELPER_FLAGS_4(bfextu_mem, TCG_CALL_NO_WG, i64, env, i32, s32, i32)
DEF_HELPER_FLAGS_5(bfins_mem, TCG_CALL_NO_WG, i32, env, i32, i32, s32, i32)
DEF_HELPER_FLAGS_4(bfchg_mem, TCG_CALL_NO_WG, i32, env, i32, s32, i32)
DEF_HELPER_FLAGS_4(bfclr_mem, TCG_CALL_NO_WG, i32, env, i32, s32, i32)
DEF_HELPER_FLAGS_4(bfset_mem, TCG_CALL_NO_WG, i32, env, i32, s32, i32)
DEF_HELPER_FLAGS_4(bfffo_mem, TCG_CALL_NO_WG, i64, env, i32, s32, i32)

DEF_HELPER_3(chk, void, env, s32, s32)
DEF_HELPER_4(chk2, void, env, s32, s32, s32)

#if defined(CONFIG_SOFTMMU)
DEF_HELPER_3(ptest, void, env, i32, i32)
DEF_HELPER_3(pflush, void, env, i32, i32)
DEF_HELPER_FLAGS_1(reset, TCG_CALL_NO_RWG, void, env)
#endif
