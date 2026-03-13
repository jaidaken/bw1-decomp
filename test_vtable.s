	.text
	.def	@feat.00;
	.scl	3;
	.type	0;
	.endef
	.globl	@feat.00
.set @feat.00, 1
	.intel_syntax noprefix
	.file	"test_vtable.c"
	.def	@Test_VtablePushRet1@4;
	.scl	2;
	.type	32;
	.endef
	.globl	@Test_VtablePushRet1@4          # -- Begin function @Test_VtablePushRet1@4
	.p2align	4
@Test_VtablePushRet1@4:                 # @"\01@Test_VtablePushRet1@4"
# %bb.0:
	#APP

	mov	eax, dword ptr [ecx]
	push	0
	call	dword ptr [eax + 12]

	#NO_APP
	mov	eax, 1
	ret
                                        # -- End function
	.def	@Test_VtablePush0xa3Ret1@4;
	.scl	2;
	.type	32;
	.endef
	.globl	@Test_VtablePush0xa3Ret1@4      # -- Begin function @Test_VtablePush0xa3Ret1@4
	.p2align	4
@Test_VtablePush0xa3Ret1@4:             # @"\01@Test_VtablePush0xa3Ret1@4"
# %bb.0:
	#APP

	mov	eax, dword ptr [ecx]
	push	163
	call	dword ptr [eax + 2280]

	#NO_APP
	mov	eax, 1
	ret
                                        # -- End function
	.def	@Test_VtablePushVoid@4;
	.scl	2;
	.type	32;
	.endef
	.globl	@Test_VtablePushVoid@4          # -- Begin function @Test_VtablePushVoid@4
	.p2align	4
@Test_VtablePushVoid@4:                 # @"\01@Test_VtablePushVoid@4"
# %bb.0:
	#APP

	mov	eax, dword ptr [ecx]
	push	163
	call	dword ptr [eax + 2280]

	#NO_APP
	ret
                                        # -- End function
	.def	@Test_VtableNegSbbNeg@4;
	.scl	2;
	.type	32;
	.endef
	.globl	@Test_VtableNegSbbNeg@4         # -- Begin function @Test_VtableNegSbbNeg@4
	.p2align	4
@Test_VtableNegSbbNeg@4:                # @"\01@Test_VtableNegSbbNeg@4"
# %bb.0:
	#APP

	mov	eax, dword ptr [ecx]
	call	dword ptr [eax + 72]
	neg	eax
	sbb	eax, eax
	neg	eax

	#NO_APP
	ret
                                        # -- End function
	.def	@Test_VtableNegSbbInc@12;
	.scl	2;
	.type	32;
	.endef
	.globl	@Test_VtableNegSbbInc@12        # -- Begin function @Test_VtableNegSbbInc@12
	.p2align	4
@Test_VtableNegSbbInc@12:               # @"\01@Test_VtableNegSbbInc@12"
# %bb.0:
	#APP

	mov	eax, dword ptr [ecx]
	call	dword ptr [eax + 2188]
	neg	eax
	sbb	eax, eax
	inc	eax

	#NO_APP
	ret	4
                                        # -- End function
	.def	@Test_VtableXorRet@4;
	.scl	2;
	.type	32;
	.endef
	.globl	@Test_VtableXorRet@4            # -- Begin function @Test_VtableXorRet@4
	.p2align	4
@Test_VtableXorRet@4:                   # @"\01@Test_VtableXorRet@4"
# %bb.0:
	#APP

	mov	eax, dword ptr [ecx]
	call	dword ptr [eax + 780]

	#NO_APP
	xor	eax, eax
	ret
                                        # -- End function
	.def	@Test_ForwardFsubr@12;
	.scl	2;
	.type	32;
	.endef
	.globl	@Test_ForwardFsubr@12           # -- Begin function @Test_ForwardFsubr@12
	.p2align	4
@Test_ForwardFsubr@12:                  # @"\01@Test_ForwardFsubr@12"
# %bb.0:
	mov	eax, dword ptr [esp + 4]
	#APP

	push	eax
	call	_TestTarget_float
	fsubr	dword ptr [_rdata_float1p0]

	#NO_APP
	ret	4
                                        # -- End function
	.def	@Test_TwoParamForward@16;
	.scl	2;
	.type	32;
	.endef
	.globl	@Test_TwoParamForward@16        # -- Begin function @Test_TwoParamForward@16
	.p2align	4
@Test_TwoParamForward@16:               # @"\01@Test_TwoParamForward@16"
# %bb.0:
	#APP

	mov	eax, dword ptr [esp + 8]
	mov	edx, dword ptr [esp + 4]
	push	eax
	push	edx
	call	_TestTarget_twoarg

	#NO_APP
	ret	8
                                        # -- End function
	.addrsig
