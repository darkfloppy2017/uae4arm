#include "sysdeps.h"
#include "m68k.h"
#include "memory.h"
#include "readcpu.h"
#include "newcpu.h"
#include "fpu/fpu.h"
#include "cputbl.h"
#include "cpu_emulation.h"
#include "debug.h"
#define SET_CFLG_ALWAYS(x) SET_CFLG(x)
#define SET_NFLG_ALWAYS(x) SET_NFLG(x)
#define CPUFUNC_FF(x) x##_ff
#define CPUFUNC_NF(x) x##_nf
#define CPUFUNC(x) CPUFUNC_FF(x)
#ifdef NOFLAGS
# include "noflags.h"
#endif

#if !defined(PART_1) && !defined(PART_2) && !defined(PART_3) && !defined(PART_4) && !defined(PART_5) && !defined(PART_6) && !defined(PART_7) && !defined(PART_8)
#define PART_1 1
#define PART_2 1
#define PART_3 1
#define PART_4 1
#define PART_5 1
#define PART_6 1
#define PART_7 1
#define PART_8 1
#endif

#ifdef PART_1
void REGPARAM2 CPUFUNC(op_0_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_18_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_28_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_38_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_39_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3c_0)(uae_u32 opcode) /* ORSR */
{
	cpuop_begin();
{	MakeSR();
{	uae_s16 src = get_iword(2);
	src &= 0xFF;
	regs.sr |= src;
	MakeFromSR();
}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_60_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_68_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_70_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_78_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_79_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_7c_0)(uae_u32 opcode) /* ORSR */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel18; }
{	MakeSR();
{	uae_s16 src = get_iword(2);
	regs.sr |= src;
	MakeFromSR();
}}}m68k_incpc(4);
endlabel18: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_98_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a0_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a8_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b8_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b9_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = get_ilong(6);
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s8)get_byte(dsta); upper = (uae_s32)(uae_s8)get_byte(dsta+1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel27; }
}
}}}m68k_incpc(4);
endlabel27: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s8)get_byte(dsta); upper = (uae_s32)(uae_s8)get_byte(dsta+1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel28; }
}
}}}m68k_incpc(6);
endlabel28: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f0_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s8)get_byte(dsta); upper = (uae_s32)(uae_s8)get_byte(dsta+1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel29; }
}
}}}}endlabel29: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f8_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s8)get_byte(dsta); upper = (uae_s32)(uae_s8)get_byte(dsta+1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel30; }
}
}}}m68k_incpc(6);
endlabel30: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f9_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s8)get_byte(dsta); upper = (uae_s32)(uae_s8)get_byte(dsta+1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel31; }
}
}}}m68k_incpc(8);
endlabel31: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_fa_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s8)get_byte(dsta); upper = (uae_s32)(uae_s8)get_byte(dsta+1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel32; }
}
}}}m68k_incpc(6);
endlabel32: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_fb_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s8)get_byte(dsta); upper = (uae_s32)(uae_s8)get_byte(dsta+1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel33; }
}
}}}}endlabel33: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_100_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_108_0)(uae_u32 opcode) /* MVPMR */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr memp = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_u16 val = (get_byte(memp) << 8) + get_byte(memp + 2);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_110_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_118_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_120_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_128_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_130_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_138_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_139_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13a_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_getpc () + 2;
	dsta += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13b_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13c_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = get_ibyte(2);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_140_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= 31;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	m68k_dreg(regs, dstreg) = (dst);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_148_0)(uae_u32 opcode) /* MVPMR */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr memp = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_u32 val = (get_byte(memp) << 24) + (get_byte(memp + 2) << 16)
              + (get_byte(memp + 4) << 8) + get_byte(memp + 6);
	m68k_dreg(regs, dstreg) = (val);
}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_150_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_158_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_160_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_168_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_170_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_178_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_179_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_17a_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_getpc () + 2;
	dsta += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_17b_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_180_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	m68k_dreg(regs, dstreg) = (dst);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_188_0)(uae_u32 opcode) /* MVPRM */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
	uaecptr memp = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	put_byte(memp, src >> 8); put_byte(memp + 2, src);
}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_190_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_198_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1a0_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1a8_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1b0_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1b8_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1b9_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1ba_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_getpc () + 2;
	dsta += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1bb_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1c0_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	m68k_dreg(regs, dstreg) = (dst);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1c8_0)(uae_u32 opcode) /* MVPRM */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
	uaecptr memp = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	put_byte(memp, src >> 24); put_byte(memp + 2, src >> 16);
	put_byte(memp + 4, src >> 8); put_byte(memp + 6, src);
}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1d0_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1d8_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1e0_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1e8_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1f0_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1f8_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1f9_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1fa_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_getpc () + 2;
	dsta += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1fb_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_200_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_210_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_218_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_220_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_228_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_230_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_238_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_239_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23c_0)(uae_u32 opcode) /* ANDSR */
{
	cpuop_begin();
{	MakeSR();
{	uae_s16 src = get_iword(2);
	src |= 0xFF00;
	regs.sr &= src;
	MakeFromSR();
}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_240_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_250_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_258_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_260_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_268_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_270_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_278_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_279_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_27c_0)(uae_u32 opcode) /* ANDSR */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel96; }
{	MakeSR();
{	uae_s16 src = get_iword(2);
	regs.sr &= src;
	MakeFromSR();
}}}m68k_incpc(4);
endlabel96: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_280_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_290_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_298_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2a0_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2a8_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2b0_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2b8_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2b9_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = get_ilong(6);
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2d0_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s16)get_word(dsta); upper = (uae_s32)(uae_s16)get_word(dsta+2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel105; }
}
}}}m68k_incpc(4);
endlabel105: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2e8_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s16)get_word(dsta); upper = (uae_s32)(uae_s16)get_word(dsta+2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel106; }
}
}}}m68k_incpc(6);
endlabel106: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2f0_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s16)get_word(dsta); upper = (uae_s32)(uae_s16)get_word(dsta+2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel107; }
}
}}}}endlabel107: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2f8_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s16)get_word(dsta); upper = (uae_s32)(uae_s16)get_word(dsta+2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel108; }
}
}}}m68k_incpc(6);
endlabel108: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2f9_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s16)get_word(dsta); upper = (uae_s32)(uae_s16)get_word(dsta+2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel109; }
}
}}}m68k_incpc(8);
endlabel109: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2fa_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s16)get_word(dsta); upper = (uae_s32)(uae_s16)get_word(dsta+2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel110; }
}
}}}m68k_incpc(6);
endlabel110: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2fb_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=(uae_s32)(uae_s16)get_word(dsta); upper = (uae_s32)(uae_s16)get_word(dsta+2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel111; }
}
}}}}endlabel111: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_400_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_410_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_418_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_420_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_428_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_430_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_438_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_439_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_440_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_450_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_458_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_460_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_468_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_470_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_478_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_479_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_480_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_490_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_498_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a0_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a8_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4b0_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4b8_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4b9_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = get_ilong(6);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4d0_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=get_long(dsta); upper = get_long(dsta+4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel136; }
}
}}}m68k_incpc(4);
endlabel136: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e8_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=get_long(dsta); upper = get_long(dsta+4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel137; }
}
}}}m68k_incpc(6);
endlabel137: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4f0_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=get_long(dsta); upper = get_long(dsta+4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel138; }
}
}}}}endlabel138: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4f8_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=get_long(dsta); upper = get_long(dsta+4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel139; }
}
}}}m68k_incpc(6);
endlabel139: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4f9_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=get_long(dsta); upper = get_long(dsta+4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel140; }
}
}}}m68k_incpc(8);
endlabel140: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4fa_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=get_long(dsta); upper = get_long(dsta+4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel141; }
}
}}}m68k_incpc(6);
endlabel141: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4fb_0)(uae_u32 opcode) /* CHK2 */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower=get_long(dsta); upper = get_long(dsta+4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG) { Exception(6,oldpc); goto endlabel142; }
}
}}}}endlabel142: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_600_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_610_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_618_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_620_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_628_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_630_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_638_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_639_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_640_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_650_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_658_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_660_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_668_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_670_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_678_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_679_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_680_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_690_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_698_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6a0_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6a8_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6b0_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6b8_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6b9_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = get_ilong(6);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6c0_0)(uae_u32 opcode) /* RTM */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{m68k_incpc(2);
	op_illg(opcode);
}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6c8_0)(uae_u32 opcode) /* RTM */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{m68k_incpc(2);
	op_illg(opcode);
}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6d0_0)(uae_u32 opcode) /* CALLM */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{m68k_incpc(2);
	op_illg(opcode);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6e8_0)(uae_u32 opcode) /* CALLM */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{m68k_incpc(2);
	op_illg(opcode);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6f0_0)(uae_u32 opcode) /* CALLM */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{m68k_incpc(2);
	op_illg(opcode);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6f8_0)(uae_u32 opcode) /* CALLM */
{
	cpuop_begin();
#ifndef NOFLAGS
{m68k_incpc(2);
	op_illg(opcode);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6f9_0)(uae_u32 opcode) /* CALLM */
{
	cpuop_begin();
#ifndef NOFLAGS
{m68k_incpc(2);
	op_illg(opcode);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6fa_0)(uae_u32 opcode) /* CALLM */
{
	cpuop_begin();
#ifndef NOFLAGS
{m68k_incpc(2);
	op_illg(opcode);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6fb_0)(uae_u32 opcode) /* CALLM */
{
	cpuop_begin();
#ifndef NOFLAGS
{m68k_incpc(2);
	op_illg(opcode);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_800_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_810_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_818_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_820_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_828_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_830_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_838_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_839_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_83a_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_83b_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_83c_0)(uae_u32 opcode) /* BTST */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uae_s8 dst = get_ibyte(4);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_840_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= 31;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	m68k_dreg(regs, dstreg) = (dst);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_850_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_858_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_860_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_868_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_870_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_878_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_879_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_87a_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_87b_0)(uae_u32 opcode) /* BCHG */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_880_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	m68k_dreg(regs, dstreg) = (dst);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_890_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_898_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8a0_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8a8_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8b0_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8b8_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8b9_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8ba_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8bb_0)(uae_u32 opcode) /* BCLR */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8c0_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	m68k_dreg(regs, dstreg) = (dst);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8d0_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8d8_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8e0_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8e8_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8f0_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8f8_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8f9_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8fa_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8fb_0)(uae_u32 opcode) /* BSET */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a00_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a10_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a18_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a20_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a28_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a30_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a38_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a39_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a3c_0)(uae_u32 opcode) /* EORSR */
{
	cpuop_begin();
{	MakeSR();
{	uae_s16 src = get_iword(2);
	src &= 0xFF;
	regs.sr ^= src;
	MakeFromSR();
}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a40_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a50_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a58_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a60_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a68_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a70_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a78_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a79_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
#endif

#ifdef PART_2
void REGPARAM2 CPUFUNC(op_a7c_0)(uae_u32 opcode) /* EORSR */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel234; }
{	MakeSR();
{	uae_s16 src = get_iword(2);
	regs.sr ^= src;
	MakeFromSR();
}}}m68k_incpc(4);
endlabel234: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a80_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a90_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_a98_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_aa0_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_aa8_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ab0_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ab8_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ab9_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = get_ilong(6);
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ad0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpb ((uae_s8)(m68k_dreg(regs, rc)), (uae_s8)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_byte(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ad8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpb ((uae_s8)(m68k_dreg(regs, rc)), (uae_s8)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_byte(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ae0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpb ((uae_s8)(m68k_dreg(regs, rc)), (uae_s8)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_byte(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ae8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpb ((uae_s8)(m68k_dreg(regs, rc)), (uae_s8)(dst));
m68k_incpc(6);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_byte(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_af0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpb ((uae_s8)(m68k_dreg(regs, rc)), (uae_s8)(dst));
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_byte(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_af8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpb ((uae_s8)(m68k_dreg(regs, rc)), (uae_s8)(dst));
m68k_incpc(6);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_byte(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_af9_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpb ((uae_s8)(m68k_dreg(regs, rc)), (uae_s8)(dst));
m68k_incpc(8);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_byte(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c00_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c10_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c18_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c20_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c28_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c30_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c38_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c39_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s8 dst = get_byte(dsta);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c3a_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 dst = get_byte(dsta);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c3b_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s8 src = get_ibyte(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 dst = get_byte(dsta);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c40_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c50_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c58_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c60_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c68_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c70_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c78_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c79_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s16 dst = get_word(dsta);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c7a_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c7b_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 dst = get_word(dsta);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c80_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c90_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c98_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ca0_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ca8_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cb0_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = get_ilong(2);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cb8_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cb9_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = get_ilong(6);
{	uae_s32 dst = get_long(dsta);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(10);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cba_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_getpc () + 6;
	dsta += (uae_s32)(uae_s16)get_iword(6);
{	uae_s32 dst = get_long(dsta);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cbb_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s32 src = get_ilong(2);
{m68k_incpc(6);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 dst = get_long(dsta);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cd0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, rc)), (uae_s16)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_word(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cd8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, rc)), (uae_s16)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_word(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ce0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, rc)), (uae_s16)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_word(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ce8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, rc)), (uae_s16)(dst));
m68k_incpc(6);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_word(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cf0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, rc)), (uae_s16)(dst));
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_word(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cf8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 dst = get_word(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, rc)), (uae_s16)(dst));
m68k_incpc(6);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_word(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cf9_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s16 dst = get_word(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, rc)), (uae_s16)(dst));
m68k_incpc(8);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_word(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_cfc_0)(uae_u32 opcode) /* CAS2 */
{
	cpuop_begin();
{{	uae_s32 extra = get_ilong(2);
	uae_u32 rn1 = regs.regs[(extra >> 28) & 15];
	uae_u32 rn2 = regs.regs[(extra >> 12) & 15];
	uae_u16 dst1 = get_word(rn1), dst2 = get_word(rn2);
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, (extra >> 16) & 7)), (uae_s16)(dst1));
	if (GET_ZFLG) {
	optflag_cmpw ((uae_s16)(m68k_dreg(regs, extra & 7)), (uae_s16)(dst2));
	if (GET_ZFLG) {
	put_word(rn1, m68k_dreg(regs, (extra >> 22) & 7));
	put_word(rn2, m68k_dreg(regs, (extra >> 6) & 7));
	}}
	if (! GET_ZFLG) {
	m68k_dreg(regs, (extra >> 6) & 7) = (m68k_dreg(regs, (extra >> 6) & 7) & ~0xffff) | (dst2 & 0xffff);
	m68k_dreg(regs, (extra >> 22) & 7) = (m68k_dreg(regs, (extra >> 22) & 7) & ~0xffff) | (dst1 & 0xffff);
	}
}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e10_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel288; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_byte(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg);
{	uae_s8 src = sfc_get_byte(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
m68k_incpc(4);
}}}}}}}endlabel288: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e18_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel289; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_byte(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg);
{	uae_s8 src = sfc_get_byte(srca);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
m68k_incpc(4);
}}}}}}}endlabel289: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e20_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel290; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_byte(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 src = sfc_get_byte(srca);
	m68k_areg (regs, dstreg) = srca;
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
m68k_incpc(4);
}}}}}}}endlabel290: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e28_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel291; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	dfc_put_byte(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 src = sfc_get_byte(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
m68k_incpc(6);
}}}}}}}endlabel291: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e30_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel292; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
regs.fault_pc = m68k_getpc ();
	dfc_put_byte(dsta,src);
}}}else{{m68k_incpc(4);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 src = sfc_get_byte(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
}}}}}}}}endlabel292: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e38_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel293; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	dfc_put_byte(dsta,src);
}}else{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(4);
{	uae_s8 src = sfc_get_byte(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
m68k_incpc(6);
}}}}}}}endlabel293: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e39_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel294; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = get_ilong(4);
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	dfc_put_byte(dsta,src);
}}else{{	uaecptr srca = get_ilong(4);
{	uae_s8 src = sfc_get_byte(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
m68k_incpc(8);
}}}}}}}endlabel294: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e50_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel295; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_word(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg);
{	uae_s16 src = sfc_get_word(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
m68k_incpc(4);
}}}}}}}endlabel295: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e58_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel296; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_word(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg);
{	uae_s16 src = sfc_get_word(srca);
	m68k_areg(regs, dstreg) += 2;
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
m68k_incpc(4);
}}}}}}}endlabel296: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e60_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel297; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_word(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg) - 2;
{	uae_s16 src = sfc_get_word(srca);
	m68k_areg (regs, dstreg) = srca;
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
m68k_incpc(4);
}}}}}}}endlabel297: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e68_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel298; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	dfc_put_word(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 src = sfc_get_word(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
m68k_incpc(6);
}}}}}}}endlabel298: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e70_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel299; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
regs.fault_pc = m68k_getpc ();
	dfc_put_word(dsta,src);
}}}else{{m68k_incpc(4);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 src = sfc_get_word(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
}}}}}}}}endlabel299: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e78_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel300; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	dfc_put_word(dsta,src);
}}else{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(4);
{	uae_s16 src = sfc_get_word(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
m68k_incpc(6);
}}}}}}}endlabel300: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e79_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel301; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = get_ilong(4);
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	dfc_put_word(dsta,src);
}}else{{	uaecptr srca = get_ilong(4);
{	uae_s16 src = sfc_get_word(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (m68k_dreg(regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
m68k_incpc(8);
}}}}}}}endlabel301: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e90_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel302; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_long(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg);
{	uae_s32 src = sfc_get_long(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (src);
	}
m68k_incpc(4);
}}}}}}}endlabel302: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e98_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel303; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_long(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg);
{	uae_s32 src = sfc_get_long(srca);
	m68k_areg(regs, dstreg) += 4;
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (src);
	}
m68k_incpc(4);
}}}}}}}endlabel303: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ea0_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel304; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	dfc_put_long(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg) - 4;
{	uae_s32 src = sfc_get_long(srca);
	m68k_areg (regs, dstreg) = srca;
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (src);
	}
m68k_incpc(4);
}}}}}}}endlabel304: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ea8_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel305; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	dfc_put_long(dsta,src);
}}else{{	uaecptr srca = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 src = sfc_get_long(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (src);
	}
m68k_incpc(6);
}}}}}}}endlabel305: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eb0_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel306; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
regs.fault_pc = m68k_getpc ();
	dfc_put_long(dsta,src);
}}}else{{m68k_incpc(4);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 src = sfc_get_long(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (src);
	}
}}}}}}}}endlabel306: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eb8_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel307; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	dfc_put_long(dsta,src);
}}else{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 src = sfc_get_long(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (src);
	}
m68k_incpc(6);
}}}}}}}endlabel307: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eb9_0)(uae_u32 opcode) /* MOVES */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel308; }
{{	uae_s16 extra = get_iword(2);
{	if (extra & 0x0800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta = get_ilong(4);
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	dfc_put_long(dsta,src);
}}else{{	uaecptr srca = get_ilong(4);
{	uae_s32 src = sfc_get_long(srca);
	if (extra & 0x8000) {
	m68k_areg(regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg(regs, (extra >> 12) & 7) = (src);
	}
m68k_incpc(8);
}}}}}}}endlabel308: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ed0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, rc)), (uae_s32)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_long(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = dst;
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ed8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, rc)), (uae_s32)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_long(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = dst;
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ee0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, rc)), (uae_s32)(dst));
m68k_incpc(4);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_long(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = dst;
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ee8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 dst = get_long(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, rc)), (uae_s32)(dst));
m68k_incpc(6);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_long(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = dst;
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ef0_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, rc)), (uae_s32)(dst));
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_long(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = dst;
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ef8_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 dst = get_long(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, rc)), (uae_s32)(dst));
m68k_incpc(6);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_long(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = dst;
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ef9_0)(uae_u32 opcode) /* CAS */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s32 dst = get_long(dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, rc)), (uae_s32)(dst));
m68k_incpc(8);
	if (GET_ZFLG){regs.fault_pc = m68k_getpc ();
	put_long(dsta,(m68k_dreg(regs, ru)));
}else{	m68k_dreg(regs, rc) = dst;
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_efc_0)(uae_u32 opcode) /* CAS2 */
{
	cpuop_begin();
{{	uae_s32 extra = get_ilong(2);
	uae_u32 rn1 = regs.regs[(extra >> 28) & 15];
	uae_u32 rn2 = regs.regs[(extra >> 12) & 15];
	uae_u32 dst1 = get_long(rn1), dst2 = get_long(rn2);
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, (extra >> 16) & 7)), (uae_s32)(dst1));
	if (GET_ZFLG) {
	optflag_cmpl ((uae_s32)(m68k_dreg(regs, extra & 7)), (uae_s32)(dst2));
	if (GET_ZFLG) {
	put_long(rn1, m68k_dreg(regs, (extra >> 22) & 7));
	put_long(rn2, m68k_dreg(regs, (extra >> 6) & 7));
	}}
	if (! GET_ZFLG) {
	m68k_dreg(regs, (extra >> 6) & 7) = dst2;
	m68k_dreg(regs, (extra >> 22) & 7) = dst1;
	}
}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1000_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1010_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1018_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1020_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1028_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1030_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1038_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1039_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_103a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_103b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_103c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1080_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1090_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1098_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg(regs, dstreg);
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10a0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10a8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10b0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10b8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10b9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10ba_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10bb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10bc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_10fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1100_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1110_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1118_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1120_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1128_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1130_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1138_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1139_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_113a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_113b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_113c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
	m68k_areg (regs, dstreg) = dsta;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1140_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1150_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1158_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1160_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1168_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1170_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(0);
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1178_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1179_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_117a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_117b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(0);
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_117c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1180_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1190_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_1198_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11a0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11a8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11b0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11b8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11b9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11ba_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11bb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11bc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(0);
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(0);
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_11fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = get_ilong(2);
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = get_ilong(2);
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = get_ilong(2);
	fixup.flag = 0;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = get_ilong(0);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = get_ilong(6);
	optflag_testb ((uae_s8)(src));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uaecptr dsta = get_ilong(0);
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_13fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
{	uaecptr dsta = get_ilong(4);
	optflag_testb ((uae_s8)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2000_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2008_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2010_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2018_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
{	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2020_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2028_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2030_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2038_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2039_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_203a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_203b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_203c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2040_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2048_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2050_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2058_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2060_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2068_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2070_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2078_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2079_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_207a_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_207b_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_207c_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_u32 val = src;
	m68k_areg(regs, dstreg) = (val);
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2080_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2088_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2090_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2098_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20a0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20a8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20b0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20b8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20b9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20ba_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20bb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20bc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20c8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_20fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 4;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2100_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2108_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2110_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2118_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2120_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2128_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2130_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2138_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2139_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_213a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_213b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_213c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2140_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2148_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2150_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
#endif

#ifdef PART_3
void REGPARAM2 CPUFUNC(op_2158_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2160_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2168_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2170_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(0);
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2178_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2179_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_217a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_217b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(0);
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_217c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2180_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2188_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2190_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_2198_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21a0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21a8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21b0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21b8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21b9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21ba_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21bb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21bc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21c8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(0);
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(0);
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_21fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23c8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = get_ilong(2);
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
{	uaecptr dsta = get_ilong(2);
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = get_ilong(2);
	fixup.flag = 0;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = get_ilong(0);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = get_ilong(6);
	optflag_testl ((uae_s32)(src));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testl ((uae_s32)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uaecptr dsta = get_ilong(0);
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_23fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
{	uaecptr dsta = get_ilong(6);
	optflag_testl ((uae_s32)(src));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3000_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3008_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3010_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3018_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
{	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3020_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3028_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3030_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3038_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3039_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_303a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_303b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_303c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3040_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3048_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3050_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3058_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3060_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3068_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3070_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3078_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3079_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_307a_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_307b_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_307c_0)(uae_u32 opcode) /* MOVEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_u32 val = (uae_s32)(uae_s16)src;
	m68k_areg(regs, dstreg) = (val);
}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3080_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3088_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3090_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3098_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30a0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30a8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30b0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30b8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30b9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30ba_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30bb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30bc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30c8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_30fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
	m68k_areg(regs, dstreg) += 2;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3100_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3108_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3110_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3118_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3120_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3128_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3130_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3138_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3139_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_313a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_313b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_313c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
	m68k_areg (regs, dstreg) = dsta;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3140_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3148_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3150_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3158_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3160_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3168_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3170_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(0);
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3178_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3179_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(6);
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_317a_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_317b_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(0);
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_317c_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3180_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3188_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3190_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_3198_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31a0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31a8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31b0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31b8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31b9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{m68k_incpc(6);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31ba_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31bb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31bc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31c8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(0);
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(6);
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(0);
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_31fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33c0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33c8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33d0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = get_ilong(2);
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33d8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
{	uaecptr dsta = get_ilong(2);
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33e0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = get_ilong(2);
	fixup.flag = 0;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33e8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33f0_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = get_ilong(0);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33f8_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33f9_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = get_ilong(6);
	optflag_testw ((uae_s16)(src));
m68k_incpc(10);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33fa_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = get_ilong(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33fb_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uaecptr dsta = get_ilong(0);
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_33fc_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
{	uaecptr dsta = get_ilong(4);
	optflag_testw ((uae_s16)(src));
m68k_incpc(8);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4000_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((newv) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4010_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4018_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4020_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4028_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4030_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4038_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4039_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4040_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | ((newv) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4050_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4058_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4060_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4068_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4070_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
regs.fault_pc = m68k_getpc ();
	put_word(srca,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4078_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4079_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4080_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg(regs, srcreg) = (newv);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4090_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4098_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40a0_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40a8_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40b0_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
regs.fault_pc = m68k_getpc ();
	put_long(srca,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40b8_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40b9_0)(uae_u32 opcode) /* NEGX */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 newv = 0 - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40c0_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel645; }
{{	MakeSR();
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | ((regs.sr) & 0xffff);
}}}m68k_incpc(2);
endlabel645: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40d0_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel646; }
{{	uaecptr srca = m68k_areg(regs, srcreg);
	MakeSR();
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr);
}}}endlabel646: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40d8_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel647; }
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
	MakeSR();
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr);
}}}endlabel647: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40e0_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel648; }
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
	m68k_areg (regs, srcreg) = srca;
	MakeSR();
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr);
}}}endlabel648: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40e8_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel649; }
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
	MakeSR();
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr);
}}}endlabel649: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40f0_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel650; }
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
	MakeSR();
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr);
}}}}endlabel650: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40f8_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel651; }
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
	MakeSR();
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr);
}}}endlabel651: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_40f9_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel652; }
{{	uaecptr srca = get_ilong(2);
	MakeSR();
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr);
}}}endlabel652: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4100_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel653; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel653; }
}}}m68k_incpc(2);
endlabel653: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4110_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel654; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel654; }
}}}}m68k_incpc(2);
endlabel654: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4118_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel655; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel655; }
}}}}m68k_incpc(2);
endlabel655: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4120_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel656; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel656; }
}}}}m68k_incpc(2);
endlabel656: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4128_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel657; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel657; }
}}}}m68k_incpc(4);
endlabel657: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4130_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel658; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel658; }
}}}}}endlabel658: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4138_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel659; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel659; }
}}}}m68k_incpc(4);
endlabel659: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4139_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel660; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel660; }
}}}}m68k_incpc(6);
endlabel660: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_413a_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel661; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel661; }
}}}}m68k_incpc(4);
endlabel661: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_413b_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel662; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel662; }
}}}}}endlabel662: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_413c_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel663; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel663; }
}}}m68k_incpc(6);
endlabel663: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4180_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel664; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel664; }
}}}m68k_incpc(2);
endlabel664: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4190_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel665; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel665; }
}}}}m68k_incpc(2);
endlabel665: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4198_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel666; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel666; }
}}}}m68k_incpc(2);
endlabel666: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41a0_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel667; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel667; }
}}}}m68k_incpc(2);
endlabel667: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41a8_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel668; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel668; }
}}}}m68k_incpc(4);
endlabel668: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41b0_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel669; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel669; }
}}}}}endlabel669: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41b8_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel670; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel670; }
}}}}m68k_incpc(4);
endlabel670: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41b9_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel671; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel671; }
}}}}m68k_incpc(6);
endlabel671: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41ba_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel672; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel672; }
}}}}m68k_incpc(4);
endlabel672: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41bb_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel673; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel673; }
}}}}}endlabel673: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41bc_0)(uae_u32 opcode) /* CHK */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	if ((uae_s32)dst < 0) { SET_NFLG (1); Exception(6,oldpc); goto endlabel674; }
	else if (dst > src) { SET_NFLG (0); Exception(6,oldpc); goto endlabel674; }
}}}m68k_incpc(4);
endlabel674: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41d0_0)(uae_u32 opcode) /* LEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	m68k_areg(regs, dstreg) = (srca);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41e8_0)(uae_u32 opcode) /* LEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	m68k_areg(regs, dstreg) = (srca);
}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41f0_0)(uae_u32 opcode) /* LEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	m68k_areg(regs, dstreg) = (srca);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41f8_0)(uae_u32 opcode) /* LEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	m68k_areg(regs, dstreg) = (srca);
}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41f9_0)(uae_u32 opcode) /* LEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	m68k_areg(regs, dstreg) = (srca);
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41fa_0)(uae_u32 opcode) /* LEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	m68k_areg(regs, dstreg) = (srca);
}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_41fb_0)(uae_u32 opcode) /* LEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	m68k_areg(regs, dstreg) = (srca);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4200_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	SET_CZNV (FLAGVAL_Z);
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((0) & 0xff);
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4210_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4218_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4220_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4228_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4230_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
	SET_CZNV (FLAGVAL_Z);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,0);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4238_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4239_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4240_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	SET_CZNV (FLAGVAL_Z);
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | ((0) & 0xffff);
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4250_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4258_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4260_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
	m68k_areg (regs, srcreg) = srca;
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4268_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4270_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
	SET_CZNV (FLAGVAL_Z);
regs.fault_pc = m68k_getpc ();
	put_word(srca,0);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4278_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4279_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4280_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	SET_CZNV (FLAGVAL_Z);
	m68k_dreg(regs, srcreg) = (0);
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4290_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4298_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 4;
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42a0_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
	m68k_areg (regs, srcreg) = srca;
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,0);
}}	cpuop_end();
}
#endif

#ifdef PART_4
void REGPARAM2 CPUFUNC(op_42a8_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42b0_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
	SET_CZNV (FLAGVAL_Z);
regs.fault_pc = m68k_getpc ();
	put_long(srca,0);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42b8_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42b9_0)(uae_u32 opcode) /* CLR */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
	SET_CZNV (FLAGVAL_Z);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(srca,0);
}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42c0_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	MakeSR();
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | ((regs.sr & 0xff) & 0xffff);
}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42d0_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	MakeSR();
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr & 0xff);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42d8_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += 2;
	MakeSR();
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr & 0xff);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42e0_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
	m68k_areg (regs, srcreg) = srca;
	MakeSR();
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr & 0xff);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42e8_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
	MakeSR();
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr & 0xff);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42f0_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
	MakeSR();
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr & 0xff);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42f8_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
	MakeSR();
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr & 0xff);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_42f9_0)(uae_u32 opcode) /* MVSR2 */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
	MakeSR();
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(srca,regs.sr & 0xff);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4400_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{{	uae_u32 dst;
	optflag_subb (dst, (uae_s8)(src), (uae_s8)(0));
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((dst) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4410_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{{	uae_u32 dst;
	optflag_subb (dst, (uae_s8)(src), (uae_s8)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4418_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{{	uae_u32 dst;
	optflag_subb (dst, (uae_s8)(src), (uae_s8)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4420_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{{	uae_u32 dst;
	optflag_subb (dst, (uae_s8)(src), (uae_s8)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4428_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{{	uae_u32 dst;
	optflag_subb (dst, (uae_s8)(src), (uae_s8)(0));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4430_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{{	uae_u32 dst;
	optflag_subb (dst, (uae_s8)(src), (uae_s8)(0));
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4438_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{{	uae_u32 dst;
	optflag_subb (dst, (uae_s8)(src), (uae_s8)(0));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4439_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{{	uae_u32 dst;
	optflag_subb (dst, (uae_s8)(src), (uae_s8)(0));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4440_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{{	uae_u32 dst;
	optflag_subw (dst, (uae_s16)(src), (uae_s16)(0));
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4450_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{{	uae_u32 dst;
	optflag_subw (dst, (uae_s16)(src), (uae_s16)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4458_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{{	uae_u32 dst;
	optflag_subw (dst, (uae_s16)(src), (uae_s16)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4460_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{{	uae_u32 dst;
	optflag_subw (dst, (uae_s16)(src), (uae_s16)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4468_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{{	uae_u32 dst;
	optflag_subw (dst, (uae_s16)(src), (uae_s16)(0));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4470_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{{	uae_u32 dst;
	optflag_subw (dst, (uae_s16)(src), (uae_s16)(0));
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4478_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{{	uae_u32 dst;
	optflag_subw (dst, (uae_s16)(src), (uae_s16)(0));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4479_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{{	uae_u32 dst;
	optflag_subw (dst, (uae_s16)(src), (uae_s16)(0));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4480_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{{	uae_u32 dst;
	optflag_subl (dst, (uae_s32)(src), (uae_s32)(0));
	m68k_dreg(regs, srcreg) = (dst);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4490_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{{	uae_u32 dst;
	optflag_subl (dst, (uae_s32)(src), (uae_s32)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4498_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{{	uae_u32 dst;
	optflag_subl (dst, (uae_s32)(src), (uae_s32)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44a0_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{{	uae_u32 dst;
	optflag_subl (dst, (uae_s32)(src), (uae_s32)(0));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44a8_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{{	uae_u32 dst;
	optflag_subl (dst, (uae_s32)(src), (uae_s32)(0));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44b0_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{{	uae_u32 dst;
	optflag_subl (dst, (uae_s32)(src), (uae_s32)(0));
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44b8_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{{	uae_u32 dst;
	optflag_subl (dst, (uae_s32)(src), (uae_s32)(0));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44b9_0)(uae_u32 opcode) /* NEG */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{{	uae_u32 dst;
	optflag_subl (dst, (uae_s32)(src), (uae_s32)(0));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44c0_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44d0_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44d8_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44e0_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44e8_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44f0_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44f8_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44f9_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44fa_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44fb_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_44fc_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
	MakeSR();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4600_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_u32 dst = ~src;
	optflag_testb ((uae_s8)(dst));
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((dst) & 0xff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4610_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uae_u32 dst = ~src;
	optflag_testb ((uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4618_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uae_u32 dst = ~src;
	optflag_testb ((uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4620_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 dst = ~src;
	optflag_testb ((uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4628_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_u32 dst = ~src;
	optflag_testb ((uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4630_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_u32 dst = ~src;
	optflag_testb ((uae_s8)(dst));
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4638_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_u32 dst = ~src;
	optflag_testb ((uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4639_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uae_u32 dst = ~src;
	optflag_testb ((uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4640_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_u32 dst = ~src;
	optflag_testw ((uae_s16)(dst));
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4650_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_u32 dst = ~src;
	optflag_testw ((uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4658_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_u32 dst = ~src;
	optflag_testw ((uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4660_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 dst = ~src;
	optflag_testw ((uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4668_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 dst = ~src;
	optflag_testw ((uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4670_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_u32 dst = ~src;
	optflag_testw ((uae_s16)(dst));
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4678_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 dst = ~src;
	optflag_testw ((uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4679_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_u32 dst = ~src;
	optflag_testw ((uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4680_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_u32 dst = ~src;
	optflag_testl ((uae_s32)(dst));
	m68k_dreg(regs, srcreg) = (dst);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4690_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_u32 dst = ~src;
	optflag_testl ((uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4698_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_u32 dst = ~src;
	optflag_testl ((uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46a0_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 dst = ~src;
	optflag_testl ((uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46a8_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 dst = ~src;
	optflag_testl ((uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46b0_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_u32 dst = ~src;
	optflag_testl ((uae_s32)(dst));
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46b8_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 dst = ~src;
	optflag_testl ((uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46b9_0)(uae_u32 opcode) /* NOT */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_u32 dst = ~src;
	optflag_testl ((uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(srca,dst);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46c0_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel773; }
{{	uae_s16 src = m68k_dreg(regs, srcreg);
	regs.sr = src;
	MakeFromSR();
}}}m68k_incpc(2);
endlabel773: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46d0_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel774; }
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}m68k_incpc(2);
endlabel774: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46d8_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel775; }
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
	regs.sr = src;
	MakeFromSR();
}}}}m68k_incpc(2);
endlabel775: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46e0_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel776; }
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
	regs.sr = src;
	MakeFromSR();
}}}}m68k_incpc(2);
endlabel776: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46e8_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel777; }
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}m68k_incpc(4);
endlabel777: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46f0_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel778; }
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}}endlabel778: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46f8_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel779; }
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}m68k_incpc(4);
endlabel779: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46f9_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel780; }
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}m68k_incpc(6);
endlabel780: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46fa_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel781; }
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}m68k_incpc(4);
endlabel781: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46fb_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel782; }
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
	regs.sr = src;
	MakeFromSR();
}}}}}endlabel782: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_46fc_0)(uae_u32 opcode) /* MV2SR */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel783; }
{{	uae_s16 src = get_iword(2);
	regs.sr = src;
	MakeFromSR();
}}}m68k_incpc(4);
endlabel783: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4800_0)(uae_u32 opcode) /* NBCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((newv) & 0xff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4808_0)(uae_u32 opcode) /* LINK */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 offs = get_ilong(2);
{	uaecptr olda = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = olda;
{	uae_s32 src = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) = (m68k_areg(regs, 7));
	m68k_areg(regs, 7) += offs;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(olda,src);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4810_0)(uae_u32 opcode) /* NBCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4818_0)(uae_u32 opcode) /* NBCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4820_0)(uae_u32 opcode) /* NBCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4828_0)(uae_u32 opcode) /* NBCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4830_0)(uae_u32 opcode) /* NBCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4838_0)(uae_u32 opcode) /* NBCD */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4839_0)(uae_u32 opcode) /* NBCD */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg;
	if (newv_lo > 9) { newv_lo -= 6; }
	newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,newv);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4840_0)(uae_u32 opcode) /* SWAP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_u32 dst = ((src >> 16)&0xFFFF) | ((src&0xFFFF)<<16);
	optflag_testl ((uae_s32)(dst));
	m68k_dreg(regs, srcreg) = (dst);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4848_0)(uae_u32 opcode) /* BKPT */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{m68k_incpc(2);
	op_illg(opcode);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4850_0)(uae_u32 opcode) /* PEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = dsta;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4868_0)(uae_u32 opcode) /* PEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uaecptr dsta = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = dsta;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4870_0)(uae_u32 opcode) /* PEA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uaecptr dsta = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = dsta;
regs.fault_pc = m68k_getpc ();
	put_long(dsta,srca);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4878_0)(uae_u32 opcode) /* PEA */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uaecptr dsta = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = dsta;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4879_0)(uae_u32 opcode) /* PEA */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	uaecptr dsta = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = dsta;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_487a_0)(uae_u32 opcode) /* PEA */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uaecptr dsta = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = dsta;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_487b_0)(uae_u32 opcode) /* PEA */
{
	cpuop_begin();
#ifndef NOFLAGS
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uaecptr dsta = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = dsta;
regs.fault_pc = m68k_getpc ();
	put_long(dsta,srca);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4880_0)(uae_u32 opcode) /* EXT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_u16 dst = (uae_s16)(uae_s8)src;
	optflag_testw ((uae_s16)(dst));
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4890_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = m68k_areg(regs, dstreg);
m68k_incpc(4);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { put_word(srca, m68k_areg(regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; }
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48a0_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = m68k_areg(regs, dstreg);
m68k_incpc(4);
{	uae_u16 amask = mask & 0xff, dmask = (mask >> 8) & 0xff;
	while (amask) { srca -= 2; put_word(srca, m68k_areg(regs, movem_index2[amask])); amask = movem_next[amask]; }
	while (dmask) { srca -= 2; put_word(srca, m68k_dreg(regs, movem_index2[dmask])); dmask = movem_next[dmask]; }
	m68k_areg(regs, dstreg) = srca;
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48a8_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { put_word(srca, m68k_areg(regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; }
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48b0_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
{m68k_incpc(4);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { put_word(srca, m68k_areg(regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; }
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48b8_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { put_word(srca, m68k_areg(regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; }
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48b9_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = get_ilong(4);
m68k_incpc(8);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_word(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { put_word(srca, m68k_areg(regs, movem_index1[amask])); srca += 2; amask = movem_next[amask]; }
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48c0_0)(uae_u32 opcode) /* EXT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_u32 dst = (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(dst));
	m68k_dreg(regs, srcreg) = (dst);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48d0_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = m68k_areg(regs, dstreg);
m68k_incpc(4);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { put_long(srca, m68k_areg(regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; }
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48e0_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = m68k_areg(regs, dstreg);
m68k_incpc(4);
{	uae_u16 amask = mask & 0xff, dmask = (mask >> 8) & 0xff;
	while (amask) { srca -= 4; put_long(srca, m68k_areg(regs, movem_index2[amask])); amask = movem_next[amask]; }
	while (dmask) { srca -= 4; put_long(srca, m68k_dreg(regs, movem_index2[dmask])); dmask = movem_next[dmask]; }
	m68k_areg(regs, dstreg) = srca;
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48e8_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { put_long(srca, m68k_areg(regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; }
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48f0_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
{m68k_incpc(4);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { put_long(srca, m68k_areg(regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; }
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48f8_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = (uae_s32)(uae_s16)get_iword(4);
m68k_incpc(6);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { put_long(srca, m68k_areg(regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; }
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_48f9_0)(uae_u32 opcode) /* MVMLE */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uae_u16 mask = get_iword(2);
{	uaecptr srca = get_ilong(4);
m68k_incpc(8);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) { put_long(srca, m68k_dreg(regs, movem_index1[dmask])); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { put_long(srca, m68k_areg(regs, movem_index1[amask])); srca += 4; amask = movem_next[amask]; }
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_49c0_0)(uae_u32 opcode) /* EXT */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_u32 dst = (uae_s32)(uae_s8)src;
	optflag_testl ((uae_s32)(dst));
	m68k_dreg(regs, srcreg) = (dst);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a00_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
	optflag_testb ((uae_s8)(src));
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a10_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a18_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
	optflag_testb ((uae_s8)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a20_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
	optflag_testb ((uae_s8)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a28_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a30_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a38_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a39_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a3a_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a3b_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a3c_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uae_s8 src = get_ibyte(2);
	optflag_testb ((uae_s8)(src));
}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a40_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
	optflag_testw ((uae_s16)(src));
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a48_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_areg(regs, srcreg);
	optflag_testw ((uae_s16)(src));
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a50_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	optflag_testw ((uae_s16)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a58_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
	optflag_testw ((uae_s16)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a60_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
	optflag_testw ((uae_s16)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a68_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	optflag_testw ((uae_s16)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a70_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
	optflag_testw ((uae_s16)(src));
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a78_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	optflag_testw ((uae_s16)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a79_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
	optflag_testw ((uae_s16)(src));
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a7a_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
	optflag_testw ((uae_s16)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a7b_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
	optflag_testw ((uae_s16)(src));
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a7c_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uae_s16 src = get_iword(2);
	optflag_testw ((uae_s16)(src));
}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a80_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
	optflag_testl ((uae_s32)(src));
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a88_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg(regs, srcreg);
	optflag_testl ((uae_s32)(src));
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a90_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	optflag_testl ((uae_s32)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4a98_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
	optflag_testl ((uae_s32)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4aa0_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
	optflag_testl ((uae_s32)(src));
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4aa8_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
	optflag_testl ((uae_s32)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ab0_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
	optflag_testl ((uae_s32)(src));
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ab8_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
	optflag_testl ((uae_s32)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ab9_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
	optflag_testl ((uae_s32)(src));
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4aba_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
	optflag_testl ((uae_s32)(src));
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4abb_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
	optflag_testl ((uae_s32)(src));
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4abc_0)(uae_u32 opcode) /* TST */
{
	cpuop_begin();
{{	uae_s32 src = get_ilong(2);
	optflag_testl ((uae_s32)(src));
}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ac0_0)(uae_u32 opcode) /* TAS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
	optflag_testb ((uae_s8)(src));
	src |= 0x80;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((src) & 0xff);
}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ad0_0)(uae_u32 opcode) /* TAS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
	src |= 0x80;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ad8_0)(uae_u32 opcode) /* TAS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
	optflag_testb ((uae_s8)(src));
	src |= 0x80;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ae0_0)(uae_u32 opcode) /* TAS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
	optflag_testb ((uae_s8)(src));
	src |= 0x80;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ae8_0)(uae_u32 opcode) /* TAS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
	src |= 0x80;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4af0_0)(uae_u32 opcode) /* TAS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
	src |= 0x80;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4af8_0)(uae_u32 opcode) /* TAS */
{
	cpuop_begin();
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
	src |= 0x80;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4af9_0)(uae_u32 opcode) /* TAS */
{
	cpuop_begin();
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
	optflag_testb ((uae_s8)(src));
	src |= 0x80;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,src);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c00_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	m68k_mull(opcode, dst, extra);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c10_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(4);
	m68k_mull(opcode, dst, extra);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c18_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
m68k_incpc(4);
	m68k_mull(opcode, dst, extra);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c20_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
m68k_incpc(4);
	m68k_mull(opcode, dst, extra);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c28_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(6);
	m68k_mull(opcode, dst, extra);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c30_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
	m68k_mull(opcode, dst, extra);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c38_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(6);
	m68k_mull(opcode, dst, extra);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c39_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(8);
	m68k_mull(opcode, dst, extra);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c3a_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(6);
	m68k_mull(opcode, dst, extra);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c3b_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 dst = get_long(dsta);
	m68k_mull(opcode, dst, extra);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c3c_0)(uae_u32 opcode) /* MULL */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uae_s32 dst = get_ilong(4);
m68k_incpc(8);
	m68k_mull(opcode, dst, extra);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c40_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	m68k_divl(opcode, dst, extra, oldpc);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c50_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(4);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c58_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
m68k_incpc(4);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c60_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
m68k_incpc(4);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c68_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(6);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c70_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c78_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(6);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c79_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(8);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c7a_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_s32 dst = get_long(dsta);
m68k_incpc(6);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c7b_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 dst = get_long(dsta);
	m68k_divl(opcode, dst, extra, oldpc);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c7c_0)(uae_u32 opcode) /* DIVL */
{
	cpuop_begin();
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 extra = get_iword(2);
{	uae_s32 dst = get_ilong(4);
m68k_incpc(8);
	m68k_divl(opcode, dst, extra, oldpc);
}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c90_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg(regs, dstreg);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; amask = movem_next[amask]; }
}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4c98_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg(regs, dstreg);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; amask = movem_next[amask]; }
	m68k_areg(regs, dstreg) = srca;
}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ca8_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; amask = movem_next[amask]; }
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cb0_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{m68k_incpc(4);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; amask = movem_next[amask]; }
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cb8_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = (uae_s32)(uae_s16)get_iword(4);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; amask = movem_next[amask]; }
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cb9_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = get_ilong(4);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; amask = movem_next[amask]; }
}}}m68k_incpc(8);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cba_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = 2;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_getpc () + 4;
	srca += (uae_s32)(uae_s16)get_iword(4);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; amask = movem_next[amask]; }
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cbb_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = 3;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = (uae_s32)(uae_s16)get_word(srca); srca += 2; amask = movem_next[amask]; }
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cd0_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg(regs, dstreg);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = get_long(srca); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = get_long(srca); srca += 4; amask = movem_next[amask]; }
}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cd8_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg(regs, dstreg);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = get_long(srca); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = get_long(srca); srca += 4; amask = movem_next[amask]; }
	m68k_areg(regs, dstreg) = srca;
}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ce8_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = get_long(srca); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = get_long(srca); srca += 4; amask = movem_next[amask]; }
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cf0_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{m68k_incpc(4);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = get_long(srca); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = get_long(srca); srca += 4; amask = movem_next[amask]; }
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cf8_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = (uae_s32)(uae_s16)get_iword(4);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = get_long(srca); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = get_long(srca); srca += 4; amask = movem_next[amask]; }
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cf9_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = get_ilong(4);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = get_long(srca); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = get_long(srca); srca += 4; amask = movem_next[amask]; }
}}}m68k_incpc(8);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cfa_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = 2;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca = m68k_getpc () + 4;
	srca += (uae_s32)(uae_s16)get_iword(4);
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = get_long(srca); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = get_long(srca); srca += 4; amask = movem_next[amask]; }
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4cfb_0)(uae_u32 opcode) /* MVMEL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = 3;
{	uae_u16 mask = get_iword(2);
	unsigned int dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	while (dmask) { m68k_dreg(regs, movem_index1[dmask]) = get_long(srca); srca += 4; dmask = movem_next[dmask]; }
	while (amask) { m68k_areg(regs, movem_index1[amask]) = get_long(srca); srca += 4; amask = movem_next[amask]; }
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e40_0)(uae_u32 opcode) /* TRAP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 15);
{{	uae_u32 src = srcreg;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	Exception(src+32,0);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e50_0)(uae_u32 opcode) /* LINK */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 offs = get_iword(2);
{	uaecptr olda = m68k_areg(regs, 7) - 4;
	m68k_areg (regs, 7) = olda;
{	uae_s32 src = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) = (m68k_areg(regs, 7));
	m68k_areg(regs, 7) += offs;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(olda,src);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e58_0)(uae_u32 opcode) /* UNLK */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg(regs, srcreg);
	m68k_areg(regs, 7) = src;
{	uaecptr olda = m68k_areg(regs, 7);
{	uae_s32 old = get_long(olda);
	m68k_areg(regs, 7) += 4;
	m68k_areg(regs, srcreg) = (old);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e60_0)(uae_u32 opcode) /* MVR2USP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel901; }
{{	uae_s32 src = m68k_areg(regs, srcreg);
	regs.usp = src;
}}}m68k_incpc(2);
endlabel901: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e68_0)(uae_u32 opcode) /* MVUSP2R */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel902; }
{{	m68k_areg(regs, srcreg) = (regs.usp);
}}}m68k_incpc(2);
endlabel902: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e70_0)(uae_u32 opcode) /* RESET */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel903; }
{	AtariReset();
}}m68k_incpc(2);
endlabel903: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e71_0)(uae_u32 opcode) /* NOP */
{
	cpuop_begin();
#ifndef NOFLAGS
{}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e72_0)(uae_u32 opcode) /* STOP */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel905; }
{{	uae_s16 src = get_iword(2);
	regs.sr = src;
	MakeFromSR();
	m68k_setstopped(1);
}}}m68k_incpc(4);
endlabel905: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e73_0)(uae_u32 opcode) /* RTE */
{
	cpuop_begin();
{if (!regs.s) { Exception(8,0); goto endlabel906; }
{	uae_u16 newsr; uae_u32 newpc; for (;;) {
{	uaecptr sra = m68k_areg(regs, 7);
{	uae_s16 sr = get_word(sra);
	m68k_areg(regs, 7) += 2;
{	uaecptr pca = m68k_areg(regs, 7);
{	uae_s32 pc = get_long(pca);
	m68k_areg(regs, 7) += 4;
{	uaecptr formata = m68k_areg(regs, 7);
{	uae_s16 format = get_word(formata);
	m68k_areg(regs, 7) += 2;
	newsr = sr; newpc = pc;
	if ((format & 0xF000) == 0x0000) { break; }
	else if ((format & 0xF000) == 0x1000) { ; }
	else if ((format & 0xF000) == 0x2000) { m68k_areg(regs, 7) += 4; break; }
	else if ((format & 0xF000) == 0x7000) { m68k_areg(regs, 7) += 52; break; }
	else if ((format & 0xF000) == 0x8000) { m68k_areg(regs, 7) += 50; break; }
	else if ((format & 0xF000) == 0x9000) { m68k_areg(regs, 7) += 12; break; }
	else if ((format & 0xF000) == 0xa000) { m68k_areg(regs, 7) += 24; break; }
	else if ((format & 0xF000) == 0xb000) { m68k_areg(regs, 7) += 84; break; }
	else { Exception(14,0); goto endlabel906; }
	regs.sr = newsr; MakeFromSR();
}
}}}}}}	regs.sr = newsr; MakeFromSR();
	m68k_setpc_rte(newpc);
}}endlabel906: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e74_0)(uae_u32 opcode) /* RTD */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 offs = get_iword(2);
{	uaecptr pca = m68k_areg(regs, 7);
{	uae_s32 pc = get_long(pca);
	m68k_areg(regs, 7) += 4;
	m68k_areg(regs, 7) += offs;
	m68k_setpc_rte(pc);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e75_0)(uae_u32 opcode) /* RTS */
{
	cpuop_begin();
#ifndef NOFLAGS
{	m68k_do_rts();
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e76_0)(uae_u32 opcode) /* TRAPV */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (GET_VFLG) { Exception(7,oldpc); goto endlabel909; }
}endlabel909: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e77_0)(uae_u32 opcode) /* RTR */
{
	cpuop_begin();
{	MakeSR();
{	uaecptr sra = m68k_areg(regs, 7);
{	uae_s16 sr = get_word(sra);
	fixup.flag = 1;
	fixup.reg = 7;
	fixup.value = m68k_areg(regs, 7);
	m68k_areg(regs, 7) += 2;
{	uaecptr pca = m68k_areg(regs, 7);
{	uae_s32 pc = get_long(pca);
	m68k_areg(regs, 7) += 4;
	fixup.flag = 0;
	regs.sr &= 0xFF00; sr &= 0xFF;
	regs.sr |= sr; m68k_setpc(pc);
	MakeFromSR();
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e7a_0)(uae_u32 opcode) /* MOVEC2 */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel911; }
{{	uae_s16 src = get_iword(2);
{	int regno = (src >> 12) & 15;
	uae_u32 *regp = regs.regs + regno;
	if (!m68k_movec2(src & 0xFFF, regp)) goto endlabel911;
}}}}m68k_incpc(4);
endlabel911: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e7b_0)(uae_u32 opcode) /* MOVE2C */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel912; }
{{	uae_s16 src = get_iword(2);
{	int regno = (src >> 12) & 15;
	uae_u32 *regp = regs.regs + regno;
	if (!m68k_move2c(src & 0xFFF, regp)) goto endlabel912;
}}}}m68k_incpc(4);
endlabel912: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4e90_0)(uae_u32 opcode) /* JSR */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_do_jsr(m68k_getpc() + 2, srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ea8_0)(uae_u32 opcode) /* JSR */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
	m68k_do_jsr(m68k_getpc() + 4, srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4eb0_0)(uae_u32 opcode) /* JSR */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
	m68k_do_jsr(m68k_getpc() + 0, srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4eb8_0)(uae_u32 opcode) /* JSR */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
	m68k_do_jsr(m68k_getpc() + 4, srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4eb9_0)(uae_u32 opcode) /* JSR */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
	m68k_do_jsr(m68k_getpc() + 6, srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4eba_0)(uae_u32 opcode) /* JSR */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
	m68k_do_jsr(m68k_getpc() + 4, srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ebb_0)(uae_u32 opcode) /* JSR */
{
	cpuop_begin();
#ifndef NOFLAGS
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
	m68k_do_jsr(m68k_getpc() + 0, srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ed0_0)(uae_u32 opcode) /* JMP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_setpc(srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ee8_0)(uae_u32 opcode) /* JMP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
	m68k_setpc(srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ef0_0)(uae_u32 opcode) /* JMP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
	m68k_setpc(srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ef8_0)(uae_u32 opcode) /* JMP */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
	m68k_setpc(srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4ef9_0)(uae_u32 opcode) /* JMP */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
	m68k_setpc(srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4efa_0)(uae_u32 opcode) /* JMP */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
	m68k_setpc(srca);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_4efb_0)(uae_u32 opcode) /* JMP */
{
	cpuop_begin();
#ifndef NOFLAGS
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
	m68k_setpc(srca);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5000_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5010_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5018_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5020_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5028_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5030_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5038_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5039_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5040_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
#endif

#ifdef PART_5
void REGPARAM2 CPUFUNC(op_5048_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5050_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5058_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5060_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5068_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5070_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5078_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5079_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_ilong(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5080_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5088_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5090_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5098_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50a0_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50a8_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50b0_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50b8_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50b9_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_ilong(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(0) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(0)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel954: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(0) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(0) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(0) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(0) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(0) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(0) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(0) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(0)) { Exception(7,oldpc); goto endlabel962; }
}}endlabel962: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(0)) { Exception(7,oldpc); goto endlabel963; }
}}endlabel963: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_50fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(0)) { Exception(7,oldpc); goto endlabel964; }
}endlabel964: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5100_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5110_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5118_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5120_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5128_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5130_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5138_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5139_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5140_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5148_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5150_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5158_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5160_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5168_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5170_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5178_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5179_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_ilong(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5180_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5188_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5190_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5198_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51a0_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51a8_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51b0_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51b8_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51b9_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta = get_ilong(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(1) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(1)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel992: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(1) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(1) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(1) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(1) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(1) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(1) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(1) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(1)) { Exception(7,oldpc); goto endlabel1000; }
}}endlabel1000: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(1)) { Exception(7,oldpc); goto endlabel1001; }
}}endlabel1001: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_51fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(1)) { Exception(7,oldpc); goto endlabel1002; }
}endlabel1002: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(2) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(2)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1004: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(2) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(2) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(2) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(2) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(2) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(2) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(2) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(2)) { Exception(7,oldpc); goto endlabel1012; }
}}endlabel1012: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(2)) { Exception(7,oldpc); goto endlabel1013; }
}}endlabel1013: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_52fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(2)) { Exception(7,oldpc); goto endlabel1014; }
}endlabel1014: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(3) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(3)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1016: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(3) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(3) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(3) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(3) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(3) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(3) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(3) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(3)) { Exception(7,oldpc); goto endlabel1024; }
}}endlabel1024: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(3)) { Exception(7,oldpc); goto endlabel1025; }
}}endlabel1025: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_53fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(3)) { Exception(7,oldpc); goto endlabel1026; }
}endlabel1026: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(4) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(4)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1028: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(4) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(4) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(4) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(4) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(4) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(4) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(4) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(4)) { Exception(7,oldpc); goto endlabel1036; }
}}endlabel1036: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(4)) { Exception(7,oldpc); goto endlabel1037; }
}}endlabel1037: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_54fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(4)) { Exception(7,oldpc); goto endlabel1038; }
}endlabel1038: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(5) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(5)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1040: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(5) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(5) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(5) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(5) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(5) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(5) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(5) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(5)) { Exception(7,oldpc); goto endlabel1048; }
}}endlabel1048: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(5)) { Exception(7,oldpc); goto endlabel1049; }
}}endlabel1049: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_55fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(5)) { Exception(7,oldpc); goto endlabel1050; }
}endlabel1050: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(6) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(6)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1052: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(6) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(6) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(6) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(6) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(6) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(6) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(6) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(6)) { Exception(7,oldpc); goto endlabel1060; }
}}endlabel1060: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(6)) { Exception(7,oldpc); goto endlabel1061; }
}}endlabel1061: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_56fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(6)) { Exception(7,oldpc); goto endlabel1062; }
}endlabel1062: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(7) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(7)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1064: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(7) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(7) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(7) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(7) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(7) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(7) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(7) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(7)) { Exception(7,oldpc); goto endlabel1072; }
}}endlabel1072: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(7)) { Exception(7,oldpc); goto endlabel1073; }
}}endlabel1073: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_57fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(7)) { Exception(7,oldpc); goto endlabel1074; }
}endlabel1074: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(8) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(8)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1076: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(8) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(8) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(8) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(8) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(8) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(8) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(8) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(8)) { Exception(7,oldpc); goto endlabel1084; }
}}endlabel1084: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(8)) { Exception(7,oldpc); goto endlabel1085; }
}}endlabel1085: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_58fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(8)) { Exception(7,oldpc); goto endlabel1086; }
}endlabel1086: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59c0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(9) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59c8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(9)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1088: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59d0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(9) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59d8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(9) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59e0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(9) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59e8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(9) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59f0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(9) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59f8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(9) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59f9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(9) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59fa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(9)) { Exception(7,oldpc); goto endlabel1096; }
}}endlabel1096: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59fb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(9)) { Exception(7,oldpc); goto endlabel1097; }
}}endlabel1097: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_59fc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(9)) { Exception(7,oldpc); goto endlabel1098; }
}endlabel1098: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ac0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(10) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ac8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(10)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1100: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ad0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(10) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ad8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(10) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ae0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(10) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ae8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(10) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5af0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(10) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5af8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(10) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5af9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(10) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5afa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(10)) { Exception(7,oldpc); goto endlabel1108; }
}}endlabel1108: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5afb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(10)) { Exception(7,oldpc); goto endlabel1109; }
}}endlabel1109: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5afc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(10)) { Exception(7,oldpc); goto endlabel1110; }
}endlabel1110: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bc0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(11) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bc8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(11)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1112: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bd0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(11) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bd8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(11) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5be0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(11) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5be8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(11) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bf0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(11) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bf8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(11) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bf9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(11) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bfa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(11)) { Exception(7,oldpc); goto endlabel1120; }
}}endlabel1120: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bfb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(11)) { Exception(7,oldpc); goto endlabel1121; }
}}endlabel1121: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5bfc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(11)) { Exception(7,oldpc); goto endlabel1122; }
}endlabel1122: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cc0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(12) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cc8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(12)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1124: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cd0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(12) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cd8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(12) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ce0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(12) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ce8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(12) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cf0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(12) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cf8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(12) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cf9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(12) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cfa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(12)) { Exception(7,oldpc); goto endlabel1132; }
}}endlabel1132: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cfb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(12)) { Exception(7,oldpc); goto endlabel1133; }
}}endlabel1133: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5cfc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(12)) { Exception(7,oldpc); goto endlabel1134; }
}endlabel1134: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5dc0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(13) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5dc8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(13)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1136: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5dd0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(13) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5dd8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(13) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5de0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(13) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5de8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(13) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5df0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(13) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5df8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(13) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5df9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(13) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5dfa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(13)) { Exception(7,oldpc); goto endlabel1144; }
}}endlabel1144: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5dfb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(13)) { Exception(7,oldpc); goto endlabel1145; }
}}endlabel1145: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5dfc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(13)) { Exception(7,oldpc); goto endlabel1146; }
}endlabel1146: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ec0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(14) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ec8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(14)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1148: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ed0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(14) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ed8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(14) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ee0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(14) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ee8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(14) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ef0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(14) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ef8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(14) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ef9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(14) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5efa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(14)) { Exception(7,oldpc); goto endlabel1156; }
}}endlabel1156: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5efb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(14)) { Exception(7,oldpc); goto endlabel1157; }
}}endlabel1157: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5efc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(14)) { Exception(7,oldpc); goto endlabel1158; }
}endlabel1158: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5fc0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{{	int val = cctrue(15) ? 0xff : 0;
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5fc8_0)(uae_u32 opcode) /* DBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 offs = get_iword(2);
	if (!cctrue(15)) {
	m68k_dreg(regs, srcreg) = (m68k_dreg(regs, srcreg) & ~0xffff) | (((src-1)) & 0xffff);
		if (src) {
			m68k_incpc((uae_s32)offs + 2);
return;
		}
	}
}}}m68k_incpc(4);
endlabel1160: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5fd0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	int val = cctrue(15) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5fd8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	int val = cctrue(15) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5fe0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
	m68k_areg (regs, srcreg) = srca;
{	int val = cctrue(15) ? 0xff : 0;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5fe8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(15) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ff0_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	int val = cctrue(15) ? 0xff : 0;
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ff8_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	int val = cctrue(15) ? 0xff : 0;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ff9_0)(uae_u32 opcode) /* Scc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uaecptr srca = get_ilong(2);
{	int val = cctrue(15) ? 0xff : 0;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(srca,val);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ffa_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	if (cctrue(15)) { Exception(7,oldpc); goto endlabel1168; }
}}endlabel1168: ;

#endif
	cpuop_end();
}
#endif

#ifdef PART_6
void REGPARAM2 CPUFUNC(op_5ffb_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	if (cctrue(15)) { Exception(7,oldpc); goto endlabel1169; }
}}endlabel1169: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_5ffc_0)(uae_u32 opcode) /* TRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{	uaecptr oldpc = m68k_getpc();
m68k_incpc(2);
	if (cctrue(15)) { Exception(7,oldpc); goto endlabel1170; }
}endlabel1170: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6000_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(0)) goto didnt_jump_6000;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6000:;
}}m68k_incpc(4);
endlabel1171: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6001_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(0)) goto didnt_jump_6001;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6001:;
}}m68k_incpc(2);
endlabel1172: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_60ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(0)) goto didnt_jump_60ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_60ff:;
}}m68k_incpc(6);
endlabel1173: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6100_0)(uae_u32 opcode) /* BSR */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	uae_s32 s = (uae_s32)src + 2;
	m68k_do_bsr(m68k_getpc() + 4, s);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6101_0)(uae_u32 opcode) /* BSR */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	uae_s32 s = (uae_s32)src + 2;
	m68k_do_bsr(m68k_getpc() + 2, s);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_61ff_0)(uae_u32 opcode) /* BSR */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	uae_s32 s = (uae_s32)src + 2;
	m68k_do_bsr(m68k_getpc() + 6, s);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6200_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(2)) goto didnt_jump_6200;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6200:;
}}m68k_incpc(4);
endlabel1177: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6201_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(2)) goto didnt_jump_6201;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6201:;
}}m68k_incpc(2);
endlabel1178: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_62ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(2)) goto didnt_jump_62ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_62ff:;
}}m68k_incpc(6);
endlabel1179: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6300_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(3)) goto didnt_jump_6300;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6300:;
}}m68k_incpc(4);
endlabel1180: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6301_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(3)) goto didnt_jump_6301;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6301:;
}}m68k_incpc(2);
endlabel1181: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_63ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(3)) goto didnt_jump_63ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_63ff:;
}}m68k_incpc(6);
endlabel1182: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6400_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(4)) goto didnt_jump_6400;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6400:;
}}m68k_incpc(4);
endlabel1183: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6401_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(4)) goto didnt_jump_6401;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6401:;
}}m68k_incpc(2);
endlabel1184: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_64ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(4)) goto didnt_jump_64ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_64ff:;
}}m68k_incpc(6);
endlabel1185: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6500_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(5)) goto didnt_jump_6500;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6500:;
}}m68k_incpc(4);
endlabel1186: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6501_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(5)) goto didnt_jump_6501;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6501:;
}}m68k_incpc(2);
endlabel1187: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_65ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(5)) goto didnt_jump_65ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_65ff:;
}}m68k_incpc(6);
endlabel1188: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6600_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(6)) goto didnt_jump_6600;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6600:;
}}m68k_incpc(4);
endlabel1189: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6601_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(6)) goto didnt_jump_6601;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6601:;
}}m68k_incpc(2);
endlabel1190: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_66ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(6)) goto didnt_jump_66ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_66ff:;
}}m68k_incpc(6);
endlabel1191: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6700_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(7)) goto didnt_jump_6700;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6700:;
}}m68k_incpc(4);
endlabel1192: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6701_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(7)) goto didnt_jump_6701;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6701:;
}}m68k_incpc(2);
endlabel1193: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_67ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(7)) goto didnt_jump_67ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_67ff:;
}}m68k_incpc(6);
endlabel1194: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6800_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(8)) goto didnt_jump_6800;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6800:;
}}m68k_incpc(4);
endlabel1195: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6801_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(8)) goto didnt_jump_6801;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6801:;
}}m68k_incpc(2);
endlabel1196: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_68ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(8)) goto didnt_jump_68ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_68ff:;
}}m68k_incpc(6);
endlabel1197: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6900_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(9)) goto didnt_jump_6900;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6900:;
}}m68k_incpc(4);
endlabel1198: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6901_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(9)) goto didnt_jump_6901;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6901:;
}}m68k_incpc(2);
endlabel1199: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_69ff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(9)) goto didnt_jump_69ff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_69ff:;
}}m68k_incpc(6);
endlabel1200: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6a00_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(10)) goto didnt_jump_6a00;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6a00:;
}}m68k_incpc(4);
endlabel1201: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6a01_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(10)) goto didnt_jump_6a01;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6a01:;
}}m68k_incpc(2);
endlabel1202: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6aff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(10)) goto didnt_jump_6aff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6aff:;
}}m68k_incpc(6);
endlabel1203: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6b00_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(11)) goto didnt_jump_6b00;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6b00:;
}}m68k_incpc(4);
endlabel1204: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6b01_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(11)) goto didnt_jump_6b01;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6b01:;
}}m68k_incpc(2);
endlabel1205: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6bff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(11)) goto didnt_jump_6bff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6bff:;
}}m68k_incpc(6);
endlabel1206: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6c00_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(12)) goto didnt_jump_6c00;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6c00:;
}}m68k_incpc(4);
endlabel1207: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6c01_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(12)) goto didnt_jump_6c01;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6c01:;
}}m68k_incpc(2);
endlabel1208: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6cff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(12)) goto didnt_jump_6cff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6cff:;
}}m68k_incpc(6);
endlabel1209: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6d00_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(13)) goto didnt_jump_6d00;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6d00:;
}}m68k_incpc(4);
endlabel1210: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6d01_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(13)) goto didnt_jump_6d01;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6d01:;
}}m68k_incpc(2);
endlabel1211: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6dff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(13)) goto didnt_jump_6dff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6dff:;
}}m68k_incpc(6);
endlabel1212: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6e00_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(14)) goto didnt_jump_6e00;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6e00:;
}}m68k_incpc(4);
endlabel1213: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6e01_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(14)) goto didnt_jump_6e01;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6e01:;
}}m68k_incpc(2);
endlabel1214: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6eff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(14)) goto didnt_jump_6eff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6eff:;
}}m68k_incpc(6);
endlabel1215: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6f00_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 src = get_iword(2);
	if (!cctrue(15)) goto didnt_jump_6f00;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6f00:;
}}m68k_incpc(4);
endlabel1216: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6f01_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue(15)) goto didnt_jump_6f01;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6f01:;
}}m68k_incpc(2);
endlabel1217: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_6fff_0)(uae_u32 opcode) /* Bcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s32 src = get_ilong(2);
	if (!cctrue(15)) goto didnt_jump_6fff;
	m68k_incpc ((uae_s32)src + 2);
return;
didnt_jump_6fff:;
}}m68k_incpc(6);
endlabel1218: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_7000_0)(uae_u32 opcode) /* MOVE */
{
	cpuop_begin();
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_u32 src = srcreg;
{	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_7100_0)(uae_u32 opcode) /* EMULOP_RETURN */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel1220; }
{	m68k_emulop_return();
}}endlabel1220: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_7101_0)(uae_u32 opcode) /* EMULOP */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel1221; }
{
	m68k_emulop(opcode);
}}m68k_incpc(2);
endlabel1221: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_7300_0)(uae_u32 opcode) /* NATFEAT_ID */
{
	cpuop_begin();
#ifndef NOFLAGS
{
	m68k_natfeat_id();
}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_7301_0)(uae_u32 opcode) /* NATFEAT_CALL */
{
	cpuop_begin();
#ifndef NOFLAGS
{
	m68k_natfeat_call();
}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8000_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8010_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8018_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8020_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8028_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8030_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8038_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8039_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_803a_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_803b_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_803c_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8040_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8050_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8058_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8060_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8068_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8070_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8078_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8079_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_807a_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_807b_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_807c_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8080_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8090_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8098_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80a0_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80a8_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80b0_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80b8_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80b9_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80ba_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80bb_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80bc_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src |= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80c0_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(2);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1257; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}endlabel1257: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80d0_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(2);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1258; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1258: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80d8_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(2);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1259; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1259: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80e0_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(2);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1260; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1260: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80e8_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1261; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1261: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80f0_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1262; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}}endlabel1262: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80f8_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1263; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1263: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80f9_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(6);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1264; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1264: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80fa_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1265; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1265: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80fb_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1266; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}}endlabel1266: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_80fc_0)(uae_u32 opcode) /* DIVU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	if (src == 0) { SET_VFLG (0); Exception (5, oldpc); goto endlabel1267; } else {
	uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
	uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
	if (newv > 0xffff) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}endlabel1267: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8100_0)(uae_u32 opcode) /* SBCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	uae_u16 newv_lo = (dst & 0xF) - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = (dst & 0xF0) - (src & 0xF0);
	uae_u16 newv, tmp_newv;
	int bcd = 0;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo & 0xF0) { newv -= 6; bcd = 6; };
	if ((((dst & 0xFF) - (src & 0xFF) - (GET_XFLG ? 1 : 0)) & 0x100) > 0xFF) { newv -= 0x60; }
	SET_CFLG ((((dst & 0xFF) - (src & 0xFF) - bcd - (GET_XFLG ? 1 : 0)) & 0x300) > 0xFF);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	SET_VFLG ((tmp_newv & 0x80) != 0 && (newv & 0x80) == 0);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8108_0)(uae_u32 opcode) /* SBCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
{	uae_u16 newv_lo = (dst & 0xF) - (src & 0xF) - (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = (dst & 0xF0) - (src & 0xF0);
	uae_u16 newv, tmp_newv;
	int bcd = 0;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo & 0xF0) { newv -= 6; bcd = 6; };
	if ((((dst & 0xFF) - (src & 0xFF) - (GET_XFLG ? 1 : 0)) & 0x100) > 0xFF) { newv -= 0x60; }
	SET_CFLG ((((dst & 0xFF) - (src & 0xFF) - bcd - (GET_XFLG ? 1 : 0)) & 0x300) > 0xFF);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	SET_VFLG ((tmp_newv & 0x80) != 0 && (newv & 0x80) == 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8110_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8118_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8120_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8128_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8130_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8138_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8139_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
	src |= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8140_0)(uae_u32 opcode) /* PACK */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uae_u16 val = m68k_dreg(regs, srcreg) + get_iword(2);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & 0xffffff00) | ((val >> 4) & 0xf0) | (val & 0xf);
}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8148_0)(uae_u32 opcode) /* PACK */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uae_u16 val;
	val = (uae_u16)get_byte(m68k_areg(regs, srcreg) - areg_byteinc[srcreg]);
	val = (val | ((uae_u16)get_byte(m68k_areg(regs, srcreg) - 2 * areg_byteinc[srcreg]) << 8)) + get_iword(2);
	m68k_areg(regs, srcreg) -= 2;
	m68k_areg(regs, dstreg) -= areg_byteinc[dstreg];
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(m68k_areg(regs, dstreg),((val >> 4) & 0xf0) | (val & 0xf));
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8150_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8158_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8160_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8168_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8170_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8178_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8179_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s16 dst = get_word(dsta);
	src |= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8180_0)(uae_u32 opcode) /* UNPK */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uae_u16 val = m68k_dreg(regs, srcreg);
	val = (((val << 4) & 0xf00) | (val & 0xf)) + get_iword(2);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & 0xffff0000) | (val & 0xffff);
}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8188_0)(uae_u32 opcode) /* UNPK */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uae_u16 val;
	val = (uae_u16)get_byte(m68k_areg(regs, srcreg) - areg_byteinc[srcreg]);
	val = (((val << 4) & 0xf00) | (val & 0xf)) + get_iword(2);
	m68k_areg(regs, srcreg) -= areg_byteinc[srcreg];
	m68k_areg(regs, dstreg) -= 2;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(m68k_areg(regs, dstreg), val);
}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8190_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_8198_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81a0_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81a8_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81b0_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81b8_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81b9_0)(uae_u32 opcode) /* OR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s32 dst = get_long(dsta);
	src |= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81c0_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(2);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1295; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}endlabel1295: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81d0_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(2);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1296; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1296: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81d8_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(2);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1297; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1297: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81e0_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(2);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1298; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1298: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81e8_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1299; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1299: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81f0_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1300; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}}endlabel1300: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81f8_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1301; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1301: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81f9_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(6);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1302; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1302: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81fa_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1303; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}endlabel1303: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81fb_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1304; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}}}endlabel1304: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_81fc_0)(uae_u32 opcode) /* DIVS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr oldpc = m68k_getpc();
{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
m68k_incpc(4);
	if (src == 0) { SET_VFLG (0); Exception(5,oldpc); goto endlabel1305; } else {
	uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
	uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
	if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) { SET_VFLG (1); SET_NFLG (1); SET_CFLG (0); } else
	{
	if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	optflag_testw ((uae_s16)(newv));
	newv = (newv & 0xffff) | ((uae_u32)rem << 16);
	m68k_dreg(regs, dstreg) = (newv);
	}
	}
}}}endlabel1305: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9000_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9010_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9018_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9020_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9028_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9030_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9038_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9039_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_903a_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_903b_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_903c_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9040_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9048_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9050_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9058_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9060_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9068_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9070_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9078_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9079_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_907a_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_907b_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_907c_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9080_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9088_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9090_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9098_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90a0_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90a8_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90b0_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90b8_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90b9_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90ba_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90bb_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90bc_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90c0_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90c8_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90d0_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90d8_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90e0_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90e8_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90f0_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90f8_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90f9_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90fa_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90fb_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_90fc_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9100_0)(uae_u32 opcode) /* SUBX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = dst - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9108_0)(uae_u32 opcode) /* SUBX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
{	uae_u32 newv = dst - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9110_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9118_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9120_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9128_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9130_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9138_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9139_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_subb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9140_0)(uae_u32 opcode) /* SUBX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = dst - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9148_0)(uae_u32 opcode) /* SUBX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
{	uae_u32 newv = dst - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9150_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9158_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9160_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9168_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9170_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9178_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9179_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_subw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9180_0)(uae_u32 opcode) /* SUBX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = dst - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9188_0)(uae_u32 opcode) /* SUBX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
{	uae_u32 newv = dst - src - (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9190_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_9198_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91a0_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91a8_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91b0_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91b8_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91b9_0)(uae_u32 opcode) /* SUB */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_subl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91c0_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91c8_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91d0_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91d8_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91e0_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91e8_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91f0_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91f8_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91f9_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91fa_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91fb_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_91fc_0)(uae_u32 opcode) /* SUBA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b000_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b010_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b018_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b020_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b028_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b030_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b038_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b039_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b03a_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b03b_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b03c_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}m68k_incpc(4);
	cpuop_end();
}
#endif

#ifdef PART_7
void REGPARAM2 CPUFUNC(op_b040_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b048_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b050_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b058_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b060_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b068_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b070_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b078_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b079_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b07a_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b07b_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b07c_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b080_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b088_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b090_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b098_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0a0_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0a8_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0b0_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0b8_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0b9_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0ba_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0bb_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0bc_0)(uae_u32 opcode) /* CMP */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0c0_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0c8_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0d0_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0d8_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0e0_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0e8_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0f0_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0f8_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0f9_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0fa_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0fb_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b0fc_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b100_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b108_0)(uae_u32 opcode) /* CMPM */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{	optflag_cmpb ((uae_s8)(src), (uae_s8)(dst));
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b110_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b118_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b120_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b128_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b130_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b138_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b139_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
	src ^= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b140_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b148_0)(uae_u32 opcode) /* CMPM */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{	optflag_cmpw ((uae_s16)(src), (uae_s16)(dst));
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b150_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b158_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b160_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b168_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b170_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b178_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b179_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s16 dst = get_word(dsta);
	src ^= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b180_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b188_0)(uae_u32 opcode) /* CMPM */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b190_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b198_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1a0_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1a8_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1b0_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1b8_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1b9_0)(uae_u32 opcode) /* EOR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s32 dst = get_long(dsta);
	src ^= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1c0_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1c8_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1d0_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1d8_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1e0_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1e8_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1f0_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1f8_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1f9_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1fa_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1fb_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_b1fc_0)(uae_u32 opcode) /* CMPA */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	optflag_cmpl ((uae_s32)(src), (uae_s32)(dst));
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c000_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c010_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c018_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c020_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c028_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c030_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c038_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c039_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c03a_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c03b_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c03c_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testb ((uae_s8)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c040_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c050_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c058_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c060_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c068_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c070_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c078_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c079_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c07a_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c07b_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c07c_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testw ((uae_s16)(src));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c080_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c090_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c098_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0a0_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0a8_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0b0_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0b8_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0b9_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0ba_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0bb_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0bc_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	src &= dst;
	optflag_testl ((uae_s32)(src));
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0c0_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0d0_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0d8_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0e0_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0e8_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0f0_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0f8_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0f9_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0fa_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0fb_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c0fc_0)(uae_u32 opcode) /* MULU */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c100_0)(uae_u32 opcode) /* ABCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	uae_u16 newv_lo = (src & 0xF) + (dst & 0xF) + (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = (src & 0xF0) + (dst & 0xF0);
	uae_u16 newv, tmp_newv;
	int cflg;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo > 9) { newv += 6; }
	cflg = (newv & 0x3F0) > 0x90;
	if (cflg) newv += 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	SET_VFLG ((tmp_newv & 0x80) == 0 && (newv & 0x80) != 0);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c108_0)(uae_u32 opcode) /* ABCD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
{	uae_u16 newv_lo = (src & 0xF) + (dst & 0xF) + (GET_XFLG ? 1 : 0);
	uae_u16 newv_hi = (src & 0xF0) + (dst & 0xF0);
	uae_u16 newv, tmp_newv;
	int cflg;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo > 9) { newv += 6; }
	cflg = (newv & 0x3F0) > 0x90;
	if (cflg) newv += 0x60;
	SET_CFLG (cflg);
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	SET_VFLG ((tmp_newv & 0x80) == 0 && (newv & 0x80) != 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c110_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c118_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c120_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c128_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c130_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c138_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c139_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
	src &= dst;
	optflag_testb ((uae_s8)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c140_0)(uae_u32 opcode) /* EXG */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
	m68k_dreg(regs, srcreg) = (dst);
	m68k_dreg(regs, dstreg) = (src);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c148_0)(uae_u32 opcode) /* EXG */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
	m68k_areg(regs, srcreg) = (dst);
	m68k_areg(regs, dstreg) = (src);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c150_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c158_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c160_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c168_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c170_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c178_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c179_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s16 dst = get_word(dsta);
	src &= dst;
	optflag_testw ((uae_s16)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c188_0)(uae_u32 opcode) /* EXG */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
	m68k_dreg(regs, srcreg) = (dst);
	m68k_areg(regs, dstreg) = (src);
}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c190_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c198_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1a0_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1a8_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1b0_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1b8_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1b9_0)(uae_u32 opcode) /* AND */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s32 dst = get_long(dsta);
	src &= dst;
	optflag_testl ((uae_s32)(src));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,src);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1c0_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1d0_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1d8_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1e0_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1e8_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1f0_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1f8_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1f9_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1fa_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1fb_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_c1fc_0)(uae_u32 opcode) /* MULS */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	optflag_testl ((uae_s32)(newv));
	m68k_dreg(regs, dstreg) = (newv);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d000_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d010_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d018_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s8 src = get_byte(srca);
	m68k_areg(regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d020_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d028_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d030_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d038_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d039_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d03a_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d03b_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s8 src = get_byte(srca);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d03c_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte(2);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d040_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d048_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d050_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d058_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d060_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d068_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d070_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d078_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d079_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d07a_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d07b_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d07c_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d080_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d088_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d090_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d098_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0a0_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0a8_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0b0_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0b8_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0b9_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0ba_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0bb_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0bc_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0c0_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0c8_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0d0_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0d8_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s16 src = get_word(srca);
	m68k_areg(regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0e0_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0e8_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0f0_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0f8_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0f9_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0fa_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0fb_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s16 src = get_word(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d0fc_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword(2);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d100_0)(uae_u32 opcode) /* ADDX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uae_s8 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = dst + src + (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d108_0)(uae_u32 opcode) /* ADDX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
{	uae_u32 newv = dst + src + (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d110_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d118_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s8 dst = get_byte(dsta);
	m68k_areg(regs, dstreg) += areg_byteinc[dstreg];
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d120_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d128_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d130_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d138_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d139_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s8 dst = get_byte(dsta);
{{	uae_u32 newv;
	optflag_addb (newv, (uae_s8)(src), (uae_s8)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_byte(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d140_0)(uae_u32 opcode) /* ADDX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uae_s16 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = dst + src + (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d148_0)(uae_u32 opcode) /* ADDX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 2;
{	uae_s16 src = get_word(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
{	uae_u32 newv = dst + src + (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d150_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d158_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s16 dst = get_word(dsta);
	m68k_areg(regs, dstreg) += 2;
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d160_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 2;
{	uae_s16 dst = get_word(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d168_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d170_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d178_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d179_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s16 dst = get_word(dsta);
{{	uae_u32 newv;
	optflag_addw (newv, (uae_s16)(src), (uae_s16)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d180_0)(uae_u32 opcode) /* ADDX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_dreg(regs, dstreg);
{	uae_u32 newv = dst + src + (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d188_0)(uae_u32 opcode) /* ADDX */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	fixup.flag = 1;
	fixup.reg = srcreg;
	fixup.value = m68k_areg(regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
	fixup.flag = 0;
{	uae_u32 newv = dst + src + (GET_XFLG ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY;
	SET_ZFLG (GET_ZFLG & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d190_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d198_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_s32 dst = get_long(dsta);
	m68k_areg(regs, dstreg) += 4;
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1a0_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) - 4;
{	uae_s32 dst = get_long(dsta);
	m68k_areg (regs, dstreg) = dsta;
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1a8_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1b0_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{m68k_incpc(2);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1b8_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1b9_0)(uae_u32 opcode) /* ADD */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uaecptr dsta = get_ilong(2);
{	uae_s32 dst = get_long(dsta);
{{	uae_u32 newv;
	optflag_addl (newv, (uae_s32)(src), (uae_s32)(dst));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_long(dsta,newv);
}}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1c0_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1c8_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg(regs, srcreg);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1d0_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1d8_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg);
{	uae_s32 src = get_long(srca);
	m68k_areg(regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
#endif

#ifdef PART_8
void REGPARAM2 CPUFUNC(op_d1e0_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) - 4;
{	uae_s32 src = get_long(srca);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(2);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1e8_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1f0_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr srca = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1f8_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1f9_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = get_ilong(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1fa_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca = m68k_getpc () + 2;
	srca += (uae_s32)(uae_s16)get_iword(2);
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}m68k_incpc(4);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1fb_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{m68k_incpc(2);
{	uaecptr tmppc = m68k_getpc();
	uaecptr srca = get_disp_ea_020(tmppc, next_iword());
{	uae_s32 src = get_long(srca);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_d1fc_0)(uae_u32 opcode) /* ADDA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = get_ilong(2);
{	uae_s32 dst = m68k_areg(regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg(regs, dstreg) = (newv);
}}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e000_0)(uae_u32 opcode) /* ASR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	uae_u32 sign = (0x80 & val) >> 7;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 8) {
		val = 0xff & (uae_u32)-sign;
		SET_CFLG (sign);
	COPY_CARRY;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
		val |= (0xff << (8 - cnt)) & (uae_u32)-sign;
		val &= 0xff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e008_0)(uae_u32 opcode) /* LSR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 8) {
		SET_CFLG ((cnt == 8) & (val >> 7));
	COPY_CARRY;
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e010_0)(uae_u32 opcode) /* ROXR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG;
	hival <<= (7 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e018_0)(uae_u32 opcode) /* ROR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
{	uae_u32 hival;
	cnt &= 7;
	hival = val << (8 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xff;
	SET_CFLG ((val & 0x80) >> 7);
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e020_0)(uae_u32 opcode) /* ASR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	uae_u32 sign = (0x80 & val) >> 7;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 8) {
		val = 0xff & (uae_u32)-sign;
		SET_CFLG (sign);
	COPY_CARRY;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
		val |= (0xff << (8 - cnt)) & (uae_u32)-sign;
		val &= 0xff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e028_0)(uae_u32 opcode) /* LSR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 8) {
		SET_CFLG ((cnt == 8) & (val >> 7));
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e030_0)(uae_u32 opcode) /* ROXR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 36) cnt -= 36;
	if (cnt >= 18) cnt -= 18;
	if (cnt >= 9) cnt -= 9;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG;
	hival <<= (7 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e038_0)(uae_u32 opcode) /* ROR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 7;
	hival = val << (8 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xff;
	SET_CFLG ((val & 0x80) >> 7);
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e040_0)(uae_u32 opcode) /* ASR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = (0x8000 & val) >> 15;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 16) {
		val = 0xffff & (uae_u32)-sign;
		SET_CFLG (sign);
	COPY_CARRY;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
		val |= (0xffff << (16 - cnt)) & (uae_u32)-sign;
		val &= 0xffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e048_0)(uae_u32 opcode) /* LSR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 16) {
		SET_CFLG ((cnt == 16) & (val >> 15));
	COPY_CARRY;
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e050_0)(uae_u32 opcode) /* ROXR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG;
	hival <<= (15 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e058_0)(uae_u32 opcode) /* ROR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
{	uae_u32 hival;
	cnt &= 15;
	hival = val << (16 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffff;
	SET_CFLG ((val & 0x8000) >> 15);
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e060_0)(uae_u32 opcode) /* ASR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = (0x8000 & val) >> 15;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 16) {
		val = 0xffff & (uae_u32)-sign;
		SET_CFLG (sign);
	COPY_CARRY;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
		val |= (0xffff << (16 - cnt)) & (uae_u32)-sign;
		val &= 0xffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e068_0)(uae_u32 opcode) /* LSR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 16) {
		SET_CFLG ((cnt == 16) & (val >> 15));
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e070_0)(uae_u32 opcode) /* ROXR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 34) cnt -= 34;
	if (cnt >= 17) cnt -= 17;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG;
	hival <<= (15 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e078_0)(uae_u32 opcode) /* ROR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 15;
	hival = val << (16 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffff;
	SET_CFLG ((val & 0x8000) >> 15);
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e080_0)(uae_u32 opcode) /* ASR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 sign = (0x80000000 & val) >> 31;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 32) {
		val = 0xffffffff & (uae_u32)-sign;
		SET_CFLG (sign);
	COPY_CARRY;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
		val |= (0xffffffff << (32 - cnt)) & (uae_u32)-sign;
		val &= 0xffffffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e088_0)(uae_u32 opcode) /* LSR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 32) {
		SET_CFLG ((cnt == 32) & (val >> 31));
	COPY_CARRY;
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e090_0)(uae_u32 opcode) /* ROXR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG;
	hival <<= (31 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e098_0)(uae_u32 opcode) /* ROR */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
{	uae_u32 hival;
	cnt &= 31;
	hival = val << (32 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffffffff;
	SET_CFLG ((val & 0x80000000) >> 31);
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0a0_0)(uae_u32 opcode) /* ASR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	uae_u32 sign = (0x80000000 & val) >> 31;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 32) {
		val = 0xffffffff & (uae_u32)-sign;
		SET_CFLG (sign);
	COPY_CARRY;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
		val |= (0xffffffff << (32 - cnt)) & (uae_u32)-sign;
		val &= 0xffffffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0a8_0)(uae_u32 opcode) /* LSR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 32) {
		SET_CFLG ((cnt == 32) & (val >> 31));
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
	COPY_CARRY;
		val >>= 1;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0b0_0)(uae_u32 opcode) /* ROXR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 33) cnt -= 33;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG;
	hival <<= (31 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0b8_0)(uae_u32 opcode) /* ROR */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 31;
	hival = val << (32 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffffffff;
	SET_CFLG ((val & 0x80000000) >> 31);
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0d0_0)(uae_u32 opcode) /* ASRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	optflag_testw ((uae_s16)(val));
	SET_CFLG (cflg);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0d8_0)(uae_u32 opcode) /* ASRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
	m68k_areg(regs, srcreg) += 2;
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	optflag_testw ((uae_s16)(val));
	SET_CFLG (cflg);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0e0_0)(uae_u32 opcode) /* ASRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) - 2;
{	uae_s16 data = get_word(dataa);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	optflag_testw ((uae_s16)(val));
	SET_CFLG (cflg);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0e8_0)(uae_u32 opcode) /* ASRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	optflag_testw ((uae_s16)(val));
	SET_CFLG (cflg);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0f0_0)(uae_u32 opcode) /* ASRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr dataa = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	optflag_testw ((uae_s16)(val));
	SET_CFLG (cflg);
	COPY_CARRY;
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0f8_0)(uae_u32 opcode) /* ASRW */
{
	cpuop_begin();
{{	uaecptr dataa = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	optflag_testw ((uae_s16)(val));
	SET_CFLG (cflg);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e0f9_0)(uae_u32 opcode) /* ASRW */
{
	cpuop_begin();
{{	uaecptr dataa = get_ilong(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	optflag_testw ((uae_s16)(val));
	SET_CFLG (cflg);
	COPY_CARRY;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e100_0)(uae_u32 opcode) /* ASL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 8) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 8 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else {
		uae_u32 mask = (0xff << (7 - cnt)) & 0xff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80) >> 7);
	COPY_CARRY;
		val <<= 1;
		val &= 0xff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e108_0)(uae_u32 opcode) /* LSL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 8) {
		SET_CFLG (cnt == 8 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80) >> 7);
	COPY_CARRY;
		val <<= 1;
	val &= 0xff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e110_0)(uae_u32 opcode) /* ROXL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (7 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e118_0)(uae_u32 opcode) /* ROL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
{	uae_u32 loval;
	cnt &= 7;
	loval = val >> (8 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xff;
	SET_CFLG (val & 1);
}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e120_0)(uae_u32 opcode) /* ASL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 8) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 8 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xff << (7 - cnt)) & 0xff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80) >> 7);
	COPY_CARRY;
		val <<= 1;
		val &= 0xff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e128_0)(uae_u32 opcode) /* LSL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 8) {
		SET_CFLG (cnt == 8 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80) >> 7);
	COPY_CARRY;
		val <<= 1;
	val &= 0xff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e130_0)(uae_u32 opcode) /* ROXL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 36) cnt -= 36;
	if (cnt >= 18) cnt -= 18;
	if (cnt >= 9) cnt -= 9;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (7 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e138_0)(uae_u32 opcode) /* ROL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg(regs, srcreg);
{	uae_s8 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 7;
	loval = val >> (8 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xff;
	SET_CFLG (val & 1);
}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testb ((uae_s8)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e140_0)(uae_u32 opcode) /* ASL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 16) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 16 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else {
		uae_u32 mask = (0xffff << (15 - cnt)) & 0xffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x8000) >> 15);
	COPY_CARRY;
		val <<= 1;
		val &= 0xffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e148_0)(uae_u32 opcode) /* LSL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 16) {
		SET_CFLG (cnt == 16 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x8000) >> 15);
	COPY_CARRY;
		val <<= 1;
	val &= 0xffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e150_0)(uae_u32 opcode) /* ROXL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (15 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e158_0)(uae_u32 opcode) /* ROL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
{	uae_u32 loval;
	cnt &= 15;
	loval = val >> (16 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffff;
	SET_CFLG (val & 1);
}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e160_0)(uae_u32 opcode) /* ASL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 16) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 16 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xffff << (15 - cnt)) & 0xffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x8000) >> 15);
	COPY_CARRY;
		val <<= 1;
		val &= 0xffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e168_0)(uae_u32 opcode) /* LSL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 16) {
		SET_CFLG (cnt == 16 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x8000) >> 15);
	COPY_CARRY;
		val <<= 1;
	val &= 0xffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e170_0)(uae_u32 opcode) /* ROXL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 34) cnt -= 34;
	if (cnt >= 17) cnt -= 17;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (15 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e178_0)(uae_u32 opcode) /* ROL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg(regs, srcreg);
{	uae_s16 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 15;
	loval = val >> (16 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffff;
	SET_CFLG (val & 1);
}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testw ((uae_s16)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (m68k_dreg(regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e180_0)(uae_u32 opcode) /* ASL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 32) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 32 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else {
		uae_u32 mask = (0xffffffff << (31 - cnt)) & 0xffffffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80000000) >> 31);
	COPY_CARRY;
		val <<= 1;
		val &= 0xffffffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e188_0)(uae_u32 opcode) /* LSL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 32) {
		SET_CFLG (cnt == 32 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80000000) >> 31);
	COPY_CARRY;
		val <<= 1;
	val &= 0xffffffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e190_0)(uae_u32 opcode) /* ROXL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (31 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e198_0)(uae_u32 opcode) /* ROL */
{
	cpuop_begin();
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
{	uae_u32 loval;
	cnt &= 31;
	loval = val >> (32 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffffffff;
	SET_CFLG (val & 1);
}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1a0_0)(uae_u32 opcode) /* ASL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 32) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 32 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xffffffff << (31 - cnt)) & 0xffffffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80000000) >> 31);
	COPY_CARRY;
		val <<= 1;
		val &= 0xffffffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1a8_0)(uae_u32 opcode) /* LSL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 32) {
		SET_CFLG (cnt == 32 ? val & 1 : 0);
	COPY_CARRY;
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80000000) >> 31);
	COPY_CARRY;
		val <<= 1;
	val &= 0xffffffff;
	}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1b0_0)(uae_u32 opcode) /* ROXL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt >= 33) cnt -= 33;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (31 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG);
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1b8_0)(uae_u32 opcode) /* ROL */
{
	cpuop_begin();
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg(regs, srcreg);
{	uae_s32 data = m68k_dreg(regs, dstreg);
{	uae_u32 val = data;
	cnt &= 63;
	CLEAR_CZNV;
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 31;
	loval = val >> (32 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffffffff;
	SET_CFLG (val & 1);
}
	{uae_u32 oldcznv = GET_CZNV & ~(FLAGVAL_Z | FLAGVAL_N);
	optflag_testl ((uae_s32)(val));
	IOR_CZNV (oldcznv);
	}
	m68k_dreg(regs, dstreg) = (val);
}}}}m68k_incpc(2);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1d0_0)(uae_u32 opcode) /* ASLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY;
	SET_VFLG (GET_VFLG | (sign2 != sign));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1d8_0)(uae_u32 opcode) /* ASLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
	m68k_areg(regs, srcreg) += 2;
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY;
	SET_VFLG (GET_VFLG | (sign2 != sign));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1e0_0)(uae_u32 opcode) /* ASLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) - 2;
{	uae_s16 data = get_word(dataa);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY;
	SET_VFLG (GET_VFLG | (sign2 != sign));
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1e8_0)(uae_u32 opcode) /* ASLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY;
	SET_VFLG (GET_VFLG | (sign2 != sign));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1f0_0)(uae_u32 opcode) /* ASLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr dataa = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY;
	SET_VFLG (GET_VFLG | (sign2 != sign));
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1f8_0)(uae_u32 opcode) /* ASLW */
{
	cpuop_begin();
{{	uaecptr dataa = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY;
	SET_VFLG (GET_VFLG | (sign2 != sign));
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e1f9_0)(uae_u32 opcode) /* ASLW */
{
	cpuop_begin();
{{	uaecptr dataa = get_ilong(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY;
	SET_VFLG (GET_VFLG | (sign2 != sign));
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e2d0_0)(uae_u32 opcode) /* LSRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e2d8_0)(uae_u32 opcode) /* LSRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
	m68k_areg(regs, srcreg) += 2;
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e2e0_0)(uae_u32 opcode) /* LSRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) - 2;
{	uae_s16 data = get_word(dataa);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e2e8_0)(uae_u32 opcode) /* LSRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e2f0_0)(uae_u32 opcode) /* LSRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr dataa = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e2f8_0)(uae_u32 opcode) /* LSRW */
{
	cpuop_begin();
{{	uaecptr dataa = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e2f9_0)(uae_u32 opcode) /* LSRW */
{
	cpuop_begin();
{{	uaecptr dataa = get_ilong(2);
{	uae_s16 data = get_word(dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e3d0_0)(uae_u32 opcode) /* LSLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e3d8_0)(uae_u32 opcode) /* LSLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e3e0_0)(uae_u32 opcode) /* LSLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) - 2;
{	uae_s16 data = get_word(dataa);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e3e8_0)(uae_u32 opcode) /* LSLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e3f0_0)(uae_u32 opcode) /* LSLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr dataa = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e3f8_0)(uae_u32 opcode) /* LSLW */
{
	cpuop_begin();
{{	uaecptr dataa = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e3f9_0)(uae_u32 opcode) /* LSLW */
{
	cpuop_begin();
{{	uaecptr dataa = get_ilong(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e4d0_0)(uae_u32 opcode) /* ROXRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e4d8_0)(uae_u32 opcode) /* ROXRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e4e0_0)(uae_u32 opcode) /* ROXRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) - 2;
{	uae_s16 data = get_word(dataa);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e4e8_0)(uae_u32 opcode) /* ROXRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e4f0_0)(uae_u32 opcode) /* ROXRW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr dataa = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e4f8_0)(uae_u32 opcode) /* ROXRW */
{
	cpuop_begin();
{{	uaecptr dataa = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e4f9_0)(uae_u32 opcode) /* ROXRW */
{
	cpuop_begin();
{{	uaecptr dataa = get_ilong(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
	COPY_CARRY;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e5d0_0)(uae_u32 opcode) /* ROXLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG) val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e5d8_0)(uae_u32 opcode) /* ROXLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG) val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e5e0_0)(uae_u32 opcode) /* ROXLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) - 2;
{	uae_s16 data = get_word(dataa);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG) val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e5e8_0)(uae_u32 opcode) /* ROXLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG) val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e5f0_0)(uae_u32 opcode) /* ROXLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr dataa = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG) val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e5f8_0)(uae_u32 opcode) /* ROXLW */
{
	cpuop_begin();
{{	uaecptr dataa = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG) val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e5f9_0)(uae_u32 opcode) /* ROXLW */
{
	cpuop_begin();
{{	uaecptr dataa = get_ilong(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG) val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
	COPY_CARRY;
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e6d0_0)(uae_u32 opcode) /* RORW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e6d8_0)(uae_u32 opcode) /* RORW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e6e0_0)(uae_u32 opcode) /* RORW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) - 2;
{	uae_s16 data = get_word(dataa);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e6e8_0)(uae_u32 opcode) /* RORW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e6f0_0)(uae_u32 opcode) /* RORW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr dataa = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e6f8_0)(uae_u32 opcode) /* RORW */
{
	cpuop_begin();
{{	uaecptr dataa = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e6f9_0)(uae_u32 opcode) /* RORW */
{
	cpuop_begin();
{{	uaecptr dataa = get_ilong(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e7d0_0)(uae_u32 opcode) /* ROLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e7d8_0)(uae_u32 opcode) /* ROLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg);
{	uae_s16 data = get_word(dataa);
	m68k_areg(regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e7e0_0)(uae_u32 opcode) /* ROLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) - 2;
{	uae_s16 data = get_word(dataa);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
m68k_incpc(2);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e7e8_0)(uae_u32 opcode) /* ROLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa = m68k_areg(regs, srcreg) + (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e7f0_0)(uae_u32 opcode) /* ROLW */
{
	cpuop_begin();
	uae_u32 srcreg = (opcode & 7);
{{m68k_incpc(2);
{	uaecptr dataa = get_disp_ea_020(m68k_areg(regs, srcreg), next_iword());
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e7f8_0)(uae_u32 opcode) /* ROLW */
{
	cpuop_begin();
{{	uaecptr dataa = (uae_s32)(uae_s16)get_iword(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
m68k_incpc(4);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e7f9_0)(uae_u32 opcode) /* ROLW */
{
	cpuop_begin();
{{	uaecptr dataa = get_ilong(2);
{	uae_s16 data = get_word(dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	optflag_testw ((uae_s16)(val));
SET_CFLG (carry >> 15);
m68k_incpc(6);
regs.fault_pc = m68k_getpc ();
	put_word(dataa,val);
}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8c0_0)(uae_u32 opcode) /* BFTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8d0_0)(uae_u32 opcode) /* BFTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8e8_0)(uae_u32 opcode) /* BFTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8f0_0)(uae_u32 opcode) /* BFTST */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8f8_0)(uae_u32 opcode) /* BFTST */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8f9_0)(uae_u32 opcode) /* BFTST */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8fa_0)(uae_u32 opcode) /* BFTST */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e8fb_0)(uae_u32 opcode) /* BFTST */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e9c0_0)(uae_u32 opcode) /* BFEXTU */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e9d0_0)(uae_u32 opcode) /* BFEXTU */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e9e8_0)(uae_u32 opcode) /* BFEXTU */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e9f0_0)(uae_u32 opcode) /* BFEXTU */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e9f8_0)(uae_u32 opcode) /* BFEXTU */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e9f9_0)(uae_u32 opcode) /* BFEXTU */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e9fa_0)(uae_u32 opcode) /* BFEXTU */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_e9fb_0)(uae_u32 opcode) /* BFEXTU */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eac0_0)(uae_u32 opcode) /* BFCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	tmp = bdata[0] | (tmp << (32 - width));
	m68k_dreg(regs, dstreg) = (tmp >> offset) | (tmp << (32 - offset));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ead0_0)(uae_u32 opcode) /* BFCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eae8_0)(uae_u32 opcode) /* BFCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eaf0_0)(uae_u32 opcode) /* BFCHG */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eaf8_0)(uae_u32 opcode) /* BFCHG */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eaf9_0)(uae_u32 opcode) /* BFCHG */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ebc0_0)(uae_u32 opcode) /* BFEXTS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ebd0_0)(uae_u32 opcode) /* BFEXTS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ebe8_0)(uae_u32 opcode) /* BFEXTS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ebf0_0)(uae_u32 opcode) /* BFEXTS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ebf8_0)(uae_u32 opcode) /* BFEXTS */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ebf9_0)(uae_u32 opcode) /* BFEXTS */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ebfa_0)(uae_u32 opcode) /* BFEXTS */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ebfb_0)(uae_u32 opcode) /* BFEXTS */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg(regs, (extra >> 12) & 7) = tmp;
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ecc0_0)(uae_u32 opcode) /* BFCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	tmp = bdata[0] | (tmp << (32 - width));
	m68k_dreg(regs, dstreg) = (tmp >> offset) | (tmp << (32 - offset));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ecd0_0)(uae_u32 opcode) /* BFCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ece8_0)(uae_u32 opcode) /* BFCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ecf0_0)(uae_u32 opcode) /* BFCLR */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ecf8_0)(uae_u32 opcode) /* BFCLR */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ecf9_0)(uae_u32 opcode) /* BFCLR */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_edc0_0)(uae_u32 opcode) /* BFFFO */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width-1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg(regs, (extra >> 12) & 7) = offset;
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_edd0_0)(uae_u32 opcode) /* BFFFO */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width-1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg(regs, (extra >> 12) & 7) = offset;
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_ede8_0)(uae_u32 opcode) /* BFFFO */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width-1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg(regs, (extra >> 12) & 7) = offset;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_edf0_0)(uae_u32 opcode) /* BFFFO */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width-1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg(regs, (extra >> 12) & 7) = offset;
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_edf8_0)(uae_u32 opcode) /* BFFFO */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width-1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg(regs, (extra >> 12) & 7) = offset;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_edf9_0)(uae_u32 opcode) /* BFFFO */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width-1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg(regs, (extra >> 12) & 7) = offset;
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_edfa_0)(uae_u32 opcode) /* BFFFO */
{
	cpuop_begin();
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_getpc () + 4;
	dsta += (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width-1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg(regs, (extra >> 12) & 7) = offset;
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_edfb_0)(uae_u32 opcode) /* BFFFO */
{
	cpuop_begin();
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr tmppc = m68k_getpc();
	uaecptr dsta = get_disp_ea_020(tmppc, next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width-1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg(regs, (extra >> 12) & 7) = offset;
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eec0_0)(uae_u32 opcode) /* BFSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	tmp = bdata[0] | (tmp << (32 - width));
	m68k_dreg(regs, dstreg) = (tmp >> offset) | (tmp << (32 - offset));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eed0_0)(uae_u32 opcode) /* BFSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eee8_0)(uae_u32 opcode) /* BFSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eef0_0)(uae_u32 opcode) /* BFSET */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eef8_0)(uae_u32 opcode) /* BFSET */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eef9_0)(uae_u32 opcode) /* BFSET */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_efc0_0)(uae_u32 opcode) /* BFINS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg(regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG_ALWAYS (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	tmp = bdata[0] | (tmp << (32 - width));
	m68k_dreg(regs, dstreg) = (tmp >> offset) | (tmp << (32 - offset));
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_efd0_0)(uae_u32 opcode) /* BFINS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg(regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG_ALWAYS (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(4);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_efe8_0)(uae_u32 opcode) /* BFINS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = m68k_areg(regs, dstreg) + (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg(regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG_ALWAYS (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eff0_0)(uae_u32 opcode) /* BFINS */
{
	cpuop_begin();
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
{m68k_incpc(4);
{	uaecptr dsta = get_disp_ea_020(m68k_areg(regs, dstreg), next_iword());
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg(regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG_ALWAYS (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}}	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eff8_0)(uae_u32 opcode) /* BFINS */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = (uae_s32)(uae_s16)get_iword(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg(regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG_ALWAYS (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(6);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_eff9_0)(uae_u32 opcode) /* BFINS */
{
	cpuop_begin();
{{	uae_s16 extra = get_iword(2);
{	uaecptr dsta = get_ilong(4);
{	uae_u32 bdata[2];	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = get_bitfield(dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg(regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG_ALWAYS (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	put_bitfield(dsta, bdata, tmp, offset, width);
}}}}m68k_incpc(8);
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f200_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f208_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f210_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f218_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f220_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f228_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f230_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f238_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f239_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f23a_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f23b_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f23c_0)(uae_u32 opcode) /* FPP */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_arithmetic(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f240_0)(uae_u32 opcode) /* FScc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_scc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f248_0)(uae_u32 opcode) /* FDBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_dbcc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f250_0)(uae_u32 opcode) /* FScc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_scc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f258_0)(uae_u32 opcode) /* FScc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_scc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f260_0)(uae_u32 opcode) /* FScc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_scc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f268_0)(uae_u32 opcode) /* FScc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_scc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f270_0)(uae_u32 opcode) /* FScc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_scc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f278_0)(uae_u32 opcode) /* FScc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_scc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f279_0)(uae_u32 opcode) /* FScc */
{
	cpuop_begin();
#ifndef NOFLAGS
{{	uae_s16 extra = get_iword(2);
m68k_incpc(4);
	fpuop_scc(opcode, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f27a_0)(uae_u32 opcode) /* FTRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{m68k_incpc(2);
{	uaecptr oldpc = m68k_getpc();
	uae_u16 extra = get_iword(0);
{	uae_s16 dummy = get_iword(2);
m68k_incpc(4);
	fpuop_trapcc(opcode, oldpc, extra);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f27b_0)(uae_u32 opcode) /* FTRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{m68k_incpc(2);
{	uaecptr oldpc = m68k_getpc();
	uae_u16 extra = get_iword(0);
{	uae_s32 dummy = get_ilong(2);
m68k_incpc(6);
	fpuop_trapcc(opcode, oldpc, extra);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f27c_0)(uae_u32 opcode) /* FTRAPcc */
{
	cpuop_begin();
#ifndef NOFLAGS
{m68k_incpc(2);
{	uaecptr oldpc = m68k_getpc();
	uae_u16 extra = get_iword(0);
m68k_incpc(2);
	fpuop_trapcc(opcode, oldpc, extra);
}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f280_0)(uae_u32 opcode) /* FBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 63);
{m68k_incpc(2);
{	uaecptr pc = m68k_getpc();
{	uae_s16 extra = get_iword(0);
m68k_incpc(2);
	fpuop_bcc(opcode, pc, extra);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f2c0_0)(uae_u32 opcode) /* FBcc */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 63);
{m68k_incpc(2);
{	uaecptr pc = m68k_getpc();
{	uae_s32 extra = get_ilong(0);
m68k_incpc(4);
	fpuop_bcc(opcode, pc, extra);
}}}
#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f310_0)(uae_u32 opcode) /* FSAVE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel1831; }
{m68k_incpc(2);
	fpuop_save(opcode);
}}endlabel1831: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f320_0)(uae_u32 opcode) /* FSAVE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel1832; }
{m68k_incpc(2);
	fpuop_save(opcode);
}}endlabel1832: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f328_0)(uae_u32 opcode) /* FSAVE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel1833; }
{m68k_incpc(2);
	fpuop_save(opcode);
}}endlabel1833: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f330_0)(uae_u32 opcode) /* FSAVE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel1834; }
{m68k_incpc(2);
	fpuop_save(opcode);
}}endlabel1834: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f338_0)(uae_u32 opcode) /* FSAVE */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel1835; }
{m68k_incpc(2);
	fpuop_save(opcode);
}}endlabel1835: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f339_0)(uae_u32 opcode) /* FSAVE */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel1836; }
{m68k_incpc(2);
	fpuop_save(opcode);
}}endlabel1836: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f350_0)(uae_u32 opcode) /* FRESTORE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel1837; }
{m68k_incpc(2);
	fpuop_restore(opcode);
}}endlabel1837: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f358_0)(uae_u32 opcode) /* FRESTORE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel1838; }
{m68k_incpc(2);
	fpuop_restore(opcode);
}}endlabel1838: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f368_0)(uae_u32 opcode) /* FRESTORE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel1839; }
{m68k_incpc(2);
	fpuop_restore(opcode);
}}endlabel1839: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f370_0)(uae_u32 opcode) /* FRESTORE */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception(8,0); goto endlabel1840; }
{m68k_incpc(2);
	fpuop_restore(opcode);
}}endlabel1840: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f378_0)(uae_u32 opcode) /* FRESTORE */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel1841; }
{m68k_incpc(2);
	fpuop_restore(opcode);
}}endlabel1841: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f379_0)(uae_u32 opcode) /* FRESTORE */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel1842; }
{m68k_incpc(2);
	fpuop_restore(opcode);
}}endlabel1842: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f37a_0)(uae_u32 opcode) /* FRESTORE */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel1843; }
{m68k_incpc(2);
	fpuop_restore(opcode);
}}endlabel1843: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f37b_0)(uae_u32 opcode) /* FRESTORE */
{
	cpuop_begin();
#ifndef NOFLAGS
{if (!regs.s) { Exception(8,0); goto endlabel1844; }
{m68k_incpc(2);
	fpuop_restore(opcode);
}}endlabel1844: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f408_0)(uae_u32 opcode) /* CINVL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel1845; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1845: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f410_0)(uae_u32 opcode) /* CINVP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel1846; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1846: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f418_0)(uae_u32 opcode) /* CINVA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1847; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1847: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f419_0)(uae_u32 opcode) /* CINVA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1848; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1848: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f41a_0)(uae_u32 opcode) /* CINVA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1849; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1849: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f41b_0)(uae_u32 opcode) /* CINVA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1850; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1850: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f41c_0)(uae_u32 opcode) /* CINVA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1851; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1851: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f41d_0)(uae_u32 opcode) /* CINVA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1852; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1852: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f41e_0)(uae_u32 opcode) /* CINVA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1853; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1853: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f41f_0)(uae_u32 opcode) /* CINVA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1854; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1854: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f428_0)(uae_u32 opcode) /* CPUSHL */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel1855; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1855: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f430_0)(uae_u32 opcode) /* CPUSHP */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel1856; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1856: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f438_0)(uae_u32 opcode) /* CPUSHA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1857; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1857: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f439_0)(uae_u32 opcode) /* CPUSHA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1858; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1858: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f43a_0)(uae_u32 opcode) /* CPUSHA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1859; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1859: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f43b_0)(uae_u32 opcode) /* CPUSHA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1860; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1860: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f43c_0)(uae_u32 opcode) /* CPUSHA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1861; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1861: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f43d_0)(uae_u32 opcode) /* CPUSHA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1862; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1862: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f43e_0)(uae_u32 opcode) /* CPUSHA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1863; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1863: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f43f_0)(uae_u32 opcode) /* CPUSHA */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception(8,0); goto endlabel1864; }
{	flush_internals();
}}m68k_incpc(2);
endlabel1864: ;

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f500_0)(uae_u32 opcode) /* MMUOP */
{
	cpuop_begin();
	uae_u32 srcreg = (uae_s32)(uae_s8)((opcode >> 3) & 255);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception(8,0); goto endlabel1865; }
{{	uae_u32 extra = srcreg;
m68k_incpc(2);
	mmu_op(opcode,extra);
}}}endlabel1865: ;
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f600_0)(uae_u32 opcode) /* MOVE16 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr memsa = m68k_areg(regs, srcreg);
{	uaecptr memda = get_ilong(2);
	memsa &= ~15;
	memda &= ~15;
	put_long(memda, get_long(memsa));
	put_long(memda+4, get_long(memsa+4));
	put_long(memda+8, get_long(memsa+8));
	put_long(memda+12, get_long(memsa+12));
	m68k_areg(regs, srcreg) += 16;
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f608_0)(uae_u32 opcode) /* MOVE16 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uaecptr memsa = get_ilong(2);
{	uaecptr memda = m68k_areg(regs, dstreg);
	memsa &= ~15;
	memda &= ~15;
	put_long(memda, get_long(memsa));
	put_long(memda+4, get_long(memsa+4));
	put_long(memda+8, get_long(memsa+8));
	put_long(memda+12, get_long(memsa+12));
	m68k_areg(regs, dstreg) += 16;
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f610_0)(uae_u32 opcode) /* MOVE16 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr memsa = m68k_areg(regs, srcreg);
{	uaecptr memda = get_ilong(2);
	memsa &= ~15;
	memda &= ~15;
	put_long(memda, get_long(memsa));
	put_long(memda+4, get_long(memsa+4));
	put_long(memda+8, get_long(memsa+8));
	put_long(memda+12, get_long(memsa+12));
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f618_0)(uae_u32 opcode) /* MOVE16 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 dstreg = opcode & 7;
{{	uaecptr memsa = get_ilong(2);
{	uaecptr memda = m68k_areg(regs, dstreg);
	memsa &= ~15;
	memda &= ~15;
	put_long(memda, get_long(memsa));
	put_long(memda+4, get_long(memsa+4));
	put_long(memda+8, get_long(memsa+8));
	put_long(memda+12, get_long(memsa+12));
}}}m68k_incpc(6);

#endif
	cpuop_end();
}
void REGPARAM2 CPUFUNC(op_f620_0)(uae_u32 opcode) /* MOVE16 */
{
	cpuop_begin();
#ifndef NOFLAGS
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = 0;
{	uaecptr mems = m68k_areg(regs, srcreg) & ~15, memd;
	dstreg = (get_iword(2) >> 12) & 7;
	memd = m68k_areg(regs, dstreg) & ~15;
	put_long(memd, get_long(mems));
	put_long(memd+4, get_long(mems+4));
	put_long(memd+8, get_long(mems+8));
	put_long(memd+12, get_long(mems+12));
	if (srcreg != dstreg)
	m68k_areg(regs, srcreg) += 16;
	m68k_areg(regs, dstreg) += 16;
}m68k_incpc(4);

#endif
	cpuop_end();
}
#endif

