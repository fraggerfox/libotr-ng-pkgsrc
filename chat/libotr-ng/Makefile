# $NetBSD$

DISTNAME=	libotr-ng-0.0.0.20190923
CATEGORIES=	chat security
MASTER_SITES=	${MASTER_SITE_GITHUB:=otrv4/}
GITHUB_TAG=	9381935a0ee1d223540ad74fc550d51b71c678ff
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://otr.im/
COMMENT=	Library providing implementation of OTR with support for \
		version 4
LICENSE=	gnu-lgpl-v2.1

DEPENDS=	glib2>=2.18:../../devel/glib2 \
#		libgoldilocks>=0.0.0:../../security/libgoldilocks \
		libgoldilocks>=0.0.0:../../wip/libgoldilocks \
		libgcrypt>=1.8.0:../../secuirty/libgcrypt \
		libotr>=4.0.0:../../chat/libotr \
		libsodium>=1.0.0:../../security/libsodium

USE_TOOLS+=	autoconf automake gmake m4 pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} autoreconf -vif

.include "../../chat/libotr/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
#.include "../../security/libgoldilocks/buildlink3.mk"
.include "../../wip/libgoldilocks/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
