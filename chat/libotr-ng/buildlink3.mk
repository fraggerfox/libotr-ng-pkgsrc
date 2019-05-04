# $NetBSD$

BUILDLINK_TREE+=	libotr-ng

.if !defined(LIBOTR_NG_BUILDLINK3_MK)
LIBOTR_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libotr-ng+=	libotr-ng>=0.0.0
BUILDLINK_ABI_DEPENDS.libotr-ng+=	libotr-ng>=0.0.0
#BUILDLINK_PKGSRCDIR.libotr-ng?=	../../chat/libotr-ng
BUILDLINK_PKGSRCDIR.libotr-ng?=		../../wip/libotr-ng

.include "../../chat/libotr/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
#.include "../../security/libgoldilocks/buildlink3.mk"
.include "../../wip/libgoldilocks/buildlink3.mk"
.endif # LIBOTR_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libotr-ng
