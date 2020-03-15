$NetBSD$

This patch exists because goldilocks_word_t gets redefined in i386 as
uint32_t instead of uint64_t which causes variables to be of the
unsigned long type in i386.

XXX: This is not the proper fix, probably discuss with upstream on fix.

--- src/client_profile.c.orig	2020-03-15 20:47:13.690767455 +0000
+++ src/client_profile.c
@@ -533,12 +533,12 @@ tstatic otrng_result client_profile_sign
 
     printf("client pub key");
   for (int i = 0; i < 8; i++) {
-    printf("0x%lx, ", client_profile->long_term_pub_key->x->limb[i]);
+    printf("0x%lx, ", (unsigned long) client_profile->long_term_pub_key->x->limb[i]);
   }
 
     printf("keypair pub key");
   for (int j = 0; j < 8; j++) {
-    printf("0x%lx, ", keypair->pub->x->limb[j]);
+    printf("0x%lx, ", (unsigned long) keypair->pub->x->limb[j]);
   }
 
   if (!client_profile_body_serialize_into(&body, &bodylen, client_profile)) {
