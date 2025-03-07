/***************************************************************************
 *   Copyright (C) 2007 Ryan Schultz, PCSX-df Team, PCSX team              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02111-1307 USA.           *
 ***************************************************************************/

#ifndef __R3000A_H__
#define __R3000A_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "psxcommon.h"
#include "psxmem.h"
#include "psxcounters.h"
#include "psxbios.h"

enum {
	R3000ACPU_NOTIFY_CACHE_ISOLATED = 0,
	R3000ACPU_NOTIFY_CACHE_UNISOLATED = 1,
	R3000ACPU_NOTIFY_DMA3_EXE_LOAD = 2
};

typedef struct {
	int  (*Init)();
	void (*Reset)();
	void (*Execute)();		/* executes up to a break */
	void (*ExecuteBlock)();	/* executes up to a jump */
	void (*Clear)(u32 Addr, u32 Size);
	void (*Notify)(int note, void *data);
	void (*ApplyConfig)();
	void (*Shutdown)();
} R3000Acpu;

extern R3000Acpu *psxCpu;
extern R3000Acpu psxInt;
extern R3000Acpu psxRec;

typedef union {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	struct { u8 h3, h2, h, l; } b;
	struct { s8 h3, h2, h, l; } sb;
	struct { u16 h, l; } w;
	struct { s16 h, l; } sw;
#else
	struct { u8 l, h, h2, h3; } b;
	struct { u16 l, h; } w;
	struct { s8 l, h, h2, h3; } sb;
	struct { s16 l, h; } sw;
#endif
} PAIR;

typedef union {
	struct {
		u32   r0, at, v0, v1, a0, a1, a2, a3,
						t0, t1, t2, t3, t4, t5, t6, t7,
						s0, s1, s2, s3, s4, s5, s6, s7,
						t8, t9, k0, k1, gp, sp, s8, ra, lo, hi;
	} n;
	u32 r[34]; /* Lo, Hi in r[32] and r[33] */
	PAIR p[34];
} psxGPRRegs;

typedef union {
	struct {
		u32	Index,     Random,    EntryLo0,  EntryLo1,
						Context,   PageMask,  Wired,     Reserved0,
						BadVAddr,  Count,     EntryHi,   Compare,
						Status,    Cause,     EPC,       PRid,
						Config,    LLAddr,    WatchLO,   WatchHI,
						XContext,  Reserved1, Reserved2, Reserved3,
						Reserved4, Reserved5, ECC,       CacheErr,
						TagLo,     TagHi,     ErrorEPC,  Reserved6;
	} n;
	u32 r[32];
	PAIR p[32];
} psxCP0Regs;

typedef struct {
	short x, y;
} SVector2D;

typedef struct {
	short z, pad;
} SVector2Dz;

typedef struct {
	short x, y, z, pad;
} SVector3D;

typedef struct {
	short x, y, z, pad;
} LVector3D;

typedef struct {
	unsigned char r, g, b, c;
} CBGR;

typedef struct {
	short m11, m12, m13, m21, m22, m23, m31, m32, m33, pad;
} SMatrix3D;

typedef union {
	struct {
		SVector3D     v0, v1, v2;
		CBGR          rgb;
		s32          otz;
		s32          ir0, ir1, ir2, ir3;
		SVector2D     sxy0, sxy1, sxy2, sxyp;
		SVector2Dz    sz0, sz1, sz2, sz3;
		CBGR          rgb0, rgb1, rgb2;
		s32          reserved;
		s32          mac0, mac1, mac2, mac3;
		u32 irgb, orgb;
		s32          lzcs, lzcr;
	} n;
	u32 r[32];
	PAIR p[32];
} psxCP2Data;

typedef union {
	struct {
		SMatrix3D rMatrix;
		s32      trX, trY, trZ;
		SMatrix3D lMatrix;
		s32      rbk, gbk, bbk;
		SMatrix3D cMatrix;
		s32      rfc, gfc, bfc;
		s32      ofx, ofy;
		s32      h;
		s32      dqa, dqb;
		s32      zsf3, zsf4;
		s32      flag;
	} n;
	u32 r[32];
	PAIR p[32];
} psxCP2Ctrl;

enum {
	PSXINT_SIO = 0,
	PSXINT_CDR,
	PSXINT_CDREAD,
	PSXINT_GPUDMA,
	PSXINT_MDECOUTDMA,
	PSXINT_SPUDMA,
	PSXINT_GPUBUSY,
	PSXINT_MDECINDMA,
	PSXINT_GPUOTCDMA,
	PSXINT_CDRDMA,
	PSXINT_NEWDRC_CHECK,
	PSXINT_RCNT,
	PSXINT_CDRLID,
	PSXINT_CDRPLAY_OLD,	/* unused */
	PSXINT_SPU_UPDATE,
	PSXINT_COUNT
};

typedef struct psxCP2Regs {
	psxCP2Data CP2D; 	/* Cop2 data registers */
	psxCP2Ctrl CP2C; 	/* Cop2 control registers */
} psxCP2Regs;

typedef struct {
	psxGPRRegs GPR;		/* General Purpose Registers */
	psxCP0Regs CP0;		/* Coprocessor0 Registers */
	union {
		struct {
			psxCP2Data CP2D; 	/* Cop2 data registers */
			psxCP2Ctrl CP2C; 	/* Cop2 control registers */
		};
		psxCP2Regs CP2;
	};
    u32 pc;				/* Program counter */
    u32 code;			/* The instruction */
	u32 cycle;
	u32 interrupt;
	struct { u32 sCycle, cycle; } intCycle[32];
	u32 gteBusyCycle;
	u32 muldivBusyCycle;
	u32 subCycle;		/* interpreter cycle counting */
	u32 subCycleStep;
	// warning: changing anything in psxRegisters requires update of all
	// asm in libpcsxcore/new_dynarec/
} psxRegisters;

extern psxRegisters psxRegs;

/* new_dynarec stuff */
extern u32 event_cycles[PSXINT_COUNT];
extern u32 next_interupt;

void new_dyna_before_save(void);
void new_dyna_after_save(void);
void new_dyna_freeze(void *f, int mode);

#define new_dyna_set_event_abs(e, abs) { \
	u32 abs_ = abs; \
	s32 di_ = next_interupt - abs_; \
	event_cycles[e] = abs_; \
	if (di_ > 0) { \
		/*printf("%u: next_interupt %u -> %u\n", psxRegs.cycle, next_interupt, abs_);*/ \
		next_interupt = abs_; \
	} \
}

#define new_dyna_set_event(e, c) \
	new_dyna_set_event_abs(e, psxRegs.cycle + (c))

int  psxInit();
void psxReset();
void psxShutdown();
void psxException(u32 code, u32 bd);
void psxBranchTest();
void psxExecuteBios();
void psxJumpTest();

#ifdef __cplusplus
}
#endif
#endif
