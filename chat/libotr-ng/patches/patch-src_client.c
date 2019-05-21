$NetBSD$

time_t is a Machine-Dependent variable (signed int) and doing
comaprisons against uint32_t is not wise, for example the comparison
check raises a warning in other i386 platforms (where sizeof(time_t)
may be 4 and not 8) with Wsign-compare flag during compile. This may
lead to undesirable consequences.

NOTE: NetBSD/i386 does not suffer from this issue since time_t is
64 bit across all NetBSD platforms since 6.0.

XXX: Discuss this with the upstream people.

--- src/client.c.orig	2019-04-08 16:59:34.000000000 +0000
+++ src/client.c
@@ -563,7 +563,7 @@ INTERNAL void otrng_client_expire_sessio
   const list_element_s *el = NULL;
   otrng_conversation_s *conv = NULL;
   time_t now;
-  uint32_t expiration_time;
+  time_t expiration_time;
 
   now = time(NULL);
 
