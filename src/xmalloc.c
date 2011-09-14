/*
 * Copyright (C) Tildeslash Ltd. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 *
 * You must obey the GNU Affero General Public License in all respects
 * for all of the code used other than OpenSSL.  
 */

#include "config.h"

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif


#include "monit.h"


/**
 *  Memory allocation routines - Makes the program die "nicely" if
 *  request for more memory fails. Copied from the fetchmail code,
 *  extended and massaged a bit to suite the monit code and coding
 *  style.
 *
 *  @file
 */


/* ---------------------------------------------------------------- Public */


void *xmalloc(size_t n) {
  
    void *p = malloc(n);

/* Some malloc's don't return a valid pointer if you malloc(0), so check
   for that only if necessary. */

#if ! HAVE_MALLOC
    if ( n == 0) {

      LogError("%s: succeeded a broken malloc 0\n", prog);
      exit(1);

    }
#endif

    if ( p == NULL ) {
      
      LogError("%s: malloc failed -- %s\n", prog, STRERROR);
      exit(1);
      
    }
    
    return p;

}

void *xcalloc(size_t count, size_t nbytes) {
  
    void *p = calloc(count, nbytes);
    if ( p == NULL ) {
      
      LogError("%s: malloc failed -- %s\n", prog, STRERROR);
      exit(1);
      
    }
    
    return p;

}


char *xstrdup(const char *s) {
  
  char *p;

  ASSERT(s);
  
  p = xmalloc(strlen(s) + 1);
  strcpy(p, s);
  
  return p;
  
}


char *xstrndup(const char *s, size_t l) {

  char *t;

  ASSERT(s);
  
  t = xmalloc(l + 1);
  strncpy(t, s, l);
  t[l] = 0;

  return t;
  
}


void *xresize(void *p, size_t nbytes) {

  if (p == 0) {
    
    return xmalloc(nbytes);

  }

  p= realloc(p, nbytes);
  if(p == NULL) {
    
    LogError("%s: realloc failed -- %s\n", prog, STRERROR);
    exit(1);
    
  }
  
  return p;
  
}
 

#if ! HAVE_MALLOC
#undef malloc

void *malloc (size_t);

void *rpl_malloc (size_t __size)
{   
  if (__size == 0) {
    __size++; 
  }
  return malloc(__size);
}
#endif