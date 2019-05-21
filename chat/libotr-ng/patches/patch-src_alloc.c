$NetBSD$

"%zu" should be used for size_t variables and not "%lu".

XXX: Discuss this with upstream people.

--- src/alloc.c.orig	2019-04-08 16:59:34.000000000 +0000
+++ src/alloc.c
@@ -39,7 +39,7 @@ INTERNAL /*@only@*/ /*@notnull@*/ void *
     if (oom_handler != NULL) {
       oom_handler();
     }
-    fprintf(stderr, "fatal: memory exhausted (xmalloc of %lu bytes).\n", size);
+    fprintf(stderr, "fatal: memory exhausted (xmalloc of %zu bytes).\n", size);
     exit(EXIT_FAILURE);
   }
 
@@ -59,7 +59,7 @@ otrng_xrealloc(/*@only@*/ /*@null@*/ voi
     if (oom_handler != NULL) {
       oom_handler();
     }
-    fprintf(stderr, "fatal: memory exhausted (xrealloc of %lu bytes).\n", size);
+    fprintf(stderr, "fatal: memory exhausted (xrealloc of %zu bytes).\n", size);
     exit(EXIT_FAILURE);
   }
 
