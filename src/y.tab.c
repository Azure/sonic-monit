#include <config.h>
/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 26 "src/p.y" /* yacc.c:339  */


/*
 * DESCRIPTION
 *   Simple context-free grammar for parsing the control file.
 *
 */

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif

#ifdef HAVE_PWD_H
#include <pwd.h>
#endif

#ifdef HAVE_GRP_H
#include <grp.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_TIME_H
#include <time.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_ASM_PARAM_H
#include <asm/param.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#endif

#ifdef HAVE_NETINET_IN_SYSTM_H
#include <netinet/in_systm.h>
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#ifdef HAVE_NETINET_IP_H
#include <netinet/ip.h>
#endif

#ifdef HAVE_NETINET_IP_ICMP_H
#include <netinet/ip_icmp.h>
#endif

#ifdef HAVE_REGEX_H
#include <regex.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "net.h"
#include "monit.h"
#include "protocol.h"
#include "engine.h"
#include "alert.h"
#include "ProcessTree.h"
#include "device.h"
#include "processor.h"

// libmonit
#include "io/File.h"
#include "util/Str.h"
#include "thread/Thread.h"


/* ------------------------------------------------------------- Definitions */


struct IHavePrecedence {
        boolean_t daemon;
        boolean_t logfile;
        boolean_t pidfile;
};


struct myrate {
        unsigned count;
        unsigned cycles;
};


/* yacc interface */
void  yyerror(const char *,...);
void  yyerror2(const char *,...);
void  yywarning(const char *,...);
void  yywarning2(const char *,...);

/* lexer interface */
int yylex(void);
extern FILE *yyin;
extern int lineno;
extern int arglineno;
extern char *yytext;
extern char *argyytext;
extern char *currentfile;
extern char *argcurrentfile;
extern int buffer_stack_ptr;

/* Local variables */
static int cfg_errflag = 0;
static Service_T tail = NULL;
static Service_T current = NULL;
static Request_T urlrequest = NULL;
static command_t command = NULL;
static command_t command1 = NULL;
static command_t command2 = NULL;
static Service_T depend_list = NULL;
static struct myuid uidset;
static struct mygid gidset;
static struct mypid pidset;
static struct mypid ppidset;
static struct myfsflag fsflagset;
static struct mynonexist nonexistset;
static struct mystatus statusset;
static struct myperm permset;
static struct mysize sizeset;
static struct myuptime uptimeset;
static struct mylinkstatus linkstatusset;
static struct mylinkspeed linkspeedset;
static struct mylinksaturation linksaturationset;
static struct mybandwidth bandwidthset;
static struct mymatch matchset;
static struct myicmp icmpset;
static struct mymail mailset;
static struct SslOptions_T sslset;
static struct myport portset;
static struct mymailserver mailserverset;
static struct mymmonit mmonitset;
static struct myfilesystem filesystemset;
static struct myresource resourceset;
static struct mychecksum checksumset;
static struct mytimestamp timestampset;
static struct myactionrate actionrateset;
static struct IHavePrecedence ihp = {false, false, false};
static struct myrate rate = {1, 1};
static struct myrate rate1 = {1, 1};
static struct myrate rate2 = {1, 1};
static char * htpasswd_file = NULL;
static unsigned repeat = 0;
static unsigned repeat1 = 0;
static unsigned repeat2 = 0;
static Digest_Type digesttype = Digest_Cleartext;

#define BITMAP_MAX (sizeof(long long) * 8)


/* -------------------------------------------------------------- Prototypes */

static void  preparse();
static void  postparse();
static boolean_t _parseOutgoingAddress(const char *ip, Outgoing_T *outgoing);
static void  addmail(char *, Mail_T, Mail_T *);
static Service_T createservice(Service_Type, char *, char *, State_Type (*)(Service_T));
static void  addservice(Service_T);
static void  adddependant(char *);
static void  addservicegroup(char *);
static void  addport(Port_T *, Port_T);
static void  addhttpheader(Port_T, const char *);
static void  addresource(Resource_T);
static void  addtimestamp(Timestamp_T);
static void  addactionrate(ActionRate_T);
static void  addsize(Size_T);
static void  adduptime(Uptime_T);
static void  addpid(Pid_T);
static void  addppid(Pid_T);
static void  addfsflag(Fsflag_T);
static void  addnonexist(Nonexist_T);
static void  addlinkstatus(Service_T, LinkStatus_T);
static void  addlinkspeed(Service_T, LinkSpeed_T);
static void  addlinksaturation(Service_T, LinkSaturation_T);
static void  addbandwidth(Bandwidth_T *, Bandwidth_T);
static void  addfilesystem(Filesystem_T);
static void  addicmp(Icmp_T);
static void  addgeneric(Port_T, char*, char*);
static void  addcommand(int, unsigned);
static void  addargument(char *);
static void  addmmonit(Mmonit_T);
static void  addmailserver(MailServer_T);
static boolean_t addcredentials(char *, char *, Digest_Type, boolean_t);
#ifdef HAVE_LIBPAM
static void  addpamauth(char *, int);
#endif
static void  addhtpasswdentry(char *, char *, Digest_Type);
static uid_t get_uid(char *, uid_t);
static gid_t get_gid(char *, gid_t);
static void  addchecksum(Checksum_T);
static void  addperm(Perm_T);
static void  addmatch(Match_T, int, int);
static void  addmatchpath(Match_T, Action_Type);
static void  addstatus(Status_T);
static Uid_T adduid(Uid_T);
static Gid_T addgid(Gid_T);
static void  addeuid(uid_t);
static void  addegid(gid_t);
static void  addeventaction(EventAction_T *, Action_Type, Action_Type);
static void  prepare_urlrequest(URL_T U);
static void  seturlrequest(int, char *);
static void  setlogfile(char *);
static void  setpidfile(char *);
static void  reset_sslset();
static void  reset_mailset();
static void  reset_mailserverset();
static void  reset_mmonitset();
static void  reset_portset();
static void  reset_resourceset();
static void  reset_timestampset();
static void  reset_actionrateset();
static void  reset_sizeset();
static void  reset_uptimeset();
static void  reset_pidset();
static void  reset_ppidset();
static void  reset_fsflagset();
static void  reset_nonexistset();
static void  reset_linkstatusset();
static void  reset_linkspeedset();
static void  reset_linksaturationset();
static void  reset_bandwidthset();
static void  reset_checksumset();
static void  reset_permset();
static void  reset_uidset();
static void  reset_gidset();
static void  reset_statusset();
static void  reset_filesystemset();
static void  reset_icmpset();
static void  reset_rateset(struct myrate *);
static void  check_name(char *);
static int   check_perm(int);
static void  check_exec(char *);
static int   cleanup_hash_string(char *);
static void  check_depend();
static void  setsyslog(char *);
static command_t copycommand(command_t);
static int verifyMaxForward(int);


#line 346 "src/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    THEN = 260,
    OR = 261,
    FAILED = 262,
    SET = 263,
    LOGFILE = 264,
    FACILITY = 265,
    DAEMON = 266,
    SYSLOG = 267,
    MAILSERVER = 268,
    HTTPD = 269,
    ALLOW = 270,
    REJECTOPT = 271,
    ADDRESS = 272,
    INIT = 273,
    TERMINAL = 274,
    BATCH = 275,
    READONLY = 276,
    CLEARTEXT = 277,
    MD5HASH = 278,
    SHA1HASH = 279,
    CRYPT = 280,
    DELAY = 281,
    PEMFILE = 282,
    ENABLE = 283,
    DISABLE = 284,
    SSL = 285,
    CLIENTPEMFILE = 286,
    ALLOWSELFCERTIFICATION = 287,
    SELFSIGNED = 288,
    VERIFY = 289,
    CERTIFICATE = 290,
    CACERTIFICATEFILE = 291,
    CACERTIFICATEPATH = 292,
    VALID = 293,
    INTERFACE = 294,
    LINK = 295,
    PACKET = 296,
    BYTEIN = 297,
    BYTEOUT = 298,
    PACKETIN = 299,
    PACKETOUT = 300,
    SPEED = 301,
    SATURATION = 302,
    UPLOAD = 303,
    DOWNLOAD = 304,
    TOTAL = 305,
    IDFILE = 306,
    STATEFILE = 307,
    SEND = 308,
    EXPECT = 309,
    CYCLE = 310,
    COUNT = 311,
    REMINDER = 312,
    REPEAT = 313,
    LIMITS = 314,
    SENDEXPECTBUFFER = 315,
    EXPECTBUFFER = 316,
    FILECONTENTBUFFER = 317,
    HTTPCONTENTBUFFER = 318,
    PROGRAMOUTPUT = 319,
    NETWORKTIMEOUT = 320,
    PROGRAMTIMEOUT = 321,
    STARTTIMEOUT = 322,
    STOPTIMEOUT = 323,
    RESTARTTIMEOUT = 324,
    PIDFILE = 325,
    START = 326,
    STOP = 327,
    PATHTOK = 328,
    HOST = 329,
    HOSTNAME = 330,
    PORT = 331,
    IPV4 = 332,
    IPV6 = 333,
    TYPE = 334,
    UDP = 335,
    TCP = 336,
    TCPSSL = 337,
    PROTOCOL = 338,
    CONNECTION = 339,
    ALERT = 340,
    NOALERT = 341,
    MAILFORMAT = 342,
    UNIXSOCKET = 343,
    SIGNATURE = 344,
    TIMEOUT = 345,
    RETRY = 346,
    RESTART = 347,
    CHECKSUM = 348,
    EVERY = 349,
    NOTEVERY = 350,
    DEFAULT = 351,
    HTTP = 352,
    HTTPS = 353,
    APACHESTATUS = 354,
    FTP = 355,
    SMTP = 356,
    SMTPS = 357,
    POP = 358,
    POPS = 359,
    IMAP = 360,
    IMAPS = 361,
    CLAMAV = 362,
    NNTP = 363,
    NTP3 = 364,
    MYSQL = 365,
    DNS = 366,
    WEBSOCKET = 367,
    SSH = 368,
    DWP = 369,
    LDAP2 = 370,
    LDAP3 = 371,
    RDATE = 372,
    RSYNC = 373,
    TNS = 374,
    PGSQL = 375,
    POSTFIXPOLICY = 376,
    SIP = 377,
    LMTP = 378,
    GPS = 379,
    RADIUS = 380,
    MEMCACHE = 381,
    REDIS = 382,
    MONGODB = 383,
    SIEVE = 384,
    STRING = 385,
    PATH = 386,
    MAILADDR = 387,
    MAILFROM = 388,
    MAILSENDER = 389,
    MAILREPLYTO = 390,
    MAILSUBJECT = 391,
    MAILBODY = 392,
    SERVICENAME = 393,
    STRINGNAME = 394,
    NUMBER = 395,
    PERCENT = 396,
    LOGLIMIT = 397,
    CLOSELIMIT = 398,
    DNSLIMIT = 399,
    KEEPALIVELIMIT = 400,
    REPLYLIMIT = 401,
    REQUESTLIMIT = 402,
    STARTLIMIT = 403,
    WAITLIMIT = 404,
    GRACEFULLIMIT = 405,
    CLEANUPLIMIT = 406,
    REAL = 407,
    CHECKPROC = 408,
    CHECKFILESYS = 409,
    CHECKFILE = 410,
    CHECKDIR = 411,
    CHECKHOST = 412,
    CHECKSYSTEM = 413,
    CHECKFIFO = 414,
    CHECKPROGRAM = 415,
    CHECKNET = 416,
    THREADS = 417,
    CHILDREN = 418,
    STATUS = 419,
    ORIGIN = 420,
    VERSIONOPT = 421,
    RESOURCE = 422,
    MEMORY = 423,
    TOTALMEMORY = 424,
    LOADAVG1 = 425,
    LOADAVG5 = 426,
    LOADAVG15 = 427,
    SWAP = 428,
    MODE = 429,
    ACTIVE = 430,
    PASSIVE = 431,
    MANUAL = 432,
    ONREBOOT = 433,
    NOSTART = 434,
    LASTSTATE = 435,
    CPU = 436,
    TOTALCPU = 437,
    CPUUSER = 438,
    CPUSYSTEM = 439,
    CPUWAIT = 440,
    GROUP = 441,
    REQUEST = 442,
    DEPENDS = 443,
    BASEDIR = 444,
    SLOT = 445,
    EVENTQUEUE = 446,
    SECRET = 447,
    HOSTHEADER = 448,
    UID = 449,
    EUID = 450,
    GID = 451,
    MMONIT = 452,
    INSTANCE = 453,
    USERNAME = 454,
    PASSWORD = 455,
    TIMESTAMP = 456,
    CHANGED = 457,
    MILLISECOND = 458,
    SECOND = 459,
    MINUTE = 460,
    HOUR = 461,
    DAY = 462,
    MONTH = 463,
    SSLAUTO = 464,
    SSLV2 = 465,
    SSLV3 = 466,
    TLSV1 = 467,
    TLSV11 = 468,
    TLSV12 = 469,
    CERTMD5 = 470,
    AUTO = 471,
    BYTE = 472,
    KILOBYTE = 473,
    MEGABYTE = 474,
    GIGABYTE = 475,
    INODE = 476,
    SPACE = 477,
    TFREE = 478,
    PERMISSION = 479,
    SIZE = 480,
    MATCH = 481,
    NOT = 482,
    IGNORE = 483,
    ACTION = 484,
    UPTIME = 485,
    EXEC = 486,
    UNMONITOR = 487,
    PING = 488,
    PING4 = 489,
    PING6 = 490,
    ICMP = 491,
    ICMPECHO = 492,
    NONEXIST = 493,
    EXIST = 494,
    INVALID = 495,
    DATA = 496,
    RECOVERED = 497,
    PASSED = 498,
    SUCCEEDED = 499,
    URL = 500,
    CONTENT = 501,
    PID = 502,
    PPID = 503,
    FSFLAG = 504,
    REGISTER = 505,
    CREDENTIALS = 506,
    URLOBJECT = 507,
    ADDRESSOBJECT = 508,
    TARGET = 509,
    TIMESPEC = 510,
    HTTPHEADER = 511,
    MAXFORWARD = 512,
    FIPS = 513,
    GREATER = 514,
    GREATEROREQUAL = 515,
    LESS = 516,
    LESSOREQUAL = 517,
    EQUAL = 518,
    NOTEQUAL = 519
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define THEN 260
#define OR 261
#define FAILED 262
#define SET 263
#define LOGFILE 264
#define FACILITY 265
#define DAEMON 266
#define SYSLOG 267
#define MAILSERVER 268
#define HTTPD 269
#define ALLOW 270
#define REJECTOPT 271
#define ADDRESS 272
#define INIT 273
#define TERMINAL 274
#define BATCH 275
#define READONLY 276
#define CLEARTEXT 277
#define MD5HASH 278
#define SHA1HASH 279
#define CRYPT 280
#define DELAY 281
#define PEMFILE 282
#define ENABLE 283
#define DISABLE 284
#define SSL 285
#define CLIENTPEMFILE 286
#define ALLOWSELFCERTIFICATION 287
#define SELFSIGNED 288
#define VERIFY 289
#define CERTIFICATE 290
#define CACERTIFICATEFILE 291
#define CACERTIFICATEPATH 292
#define VALID 293
#define INTERFACE 294
#define LINK 295
#define PACKET 296
#define BYTEIN 297
#define BYTEOUT 298
#define PACKETIN 299
#define PACKETOUT 300
#define SPEED 301
#define SATURATION 302
#define UPLOAD 303
#define DOWNLOAD 304
#define TOTAL 305
#define IDFILE 306
#define STATEFILE 307
#define SEND 308
#define EXPECT 309
#define CYCLE 310
#define COUNT 311
#define REMINDER 312
#define REPEAT 313
#define LIMITS 314
#define SENDEXPECTBUFFER 315
#define EXPECTBUFFER 316
#define FILECONTENTBUFFER 317
#define HTTPCONTENTBUFFER 318
#define PROGRAMOUTPUT 319
#define NETWORKTIMEOUT 320
#define PROGRAMTIMEOUT 321
#define STARTTIMEOUT 322
#define STOPTIMEOUT 323
#define RESTARTTIMEOUT 324
#define PIDFILE 325
#define START 326
#define STOP 327
#define PATHTOK 328
#define HOST 329
#define HOSTNAME 330
#define PORT 331
#define IPV4 332
#define IPV6 333
#define TYPE 334
#define UDP 335
#define TCP 336
#define TCPSSL 337
#define PROTOCOL 338
#define CONNECTION 339
#define ALERT 340
#define NOALERT 341
#define MAILFORMAT 342
#define UNIXSOCKET 343
#define SIGNATURE 344
#define TIMEOUT 345
#define RETRY 346
#define RESTART 347
#define CHECKSUM 348
#define EVERY 349
#define NOTEVERY 350
#define DEFAULT 351
#define HTTP 352
#define HTTPS 353
#define APACHESTATUS 354
#define FTP 355
#define SMTP 356
#define SMTPS 357
#define POP 358
#define POPS 359
#define IMAP 360
#define IMAPS 361
#define CLAMAV 362
#define NNTP 363
#define NTP3 364
#define MYSQL 365
#define DNS 366
#define WEBSOCKET 367
#define SSH 368
#define DWP 369
#define LDAP2 370
#define LDAP3 371
#define RDATE 372
#define RSYNC 373
#define TNS 374
#define PGSQL 375
#define POSTFIXPOLICY 376
#define SIP 377
#define LMTP 378
#define GPS 379
#define RADIUS 380
#define MEMCACHE 381
#define REDIS 382
#define MONGODB 383
#define SIEVE 384
#define STRING 385
#define PATH 386
#define MAILADDR 387
#define MAILFROM 388
#define MAILSENDER 389
#define MAILREPLYTO 390
#define MAILSUBJECT 391
#define MAILBODY 392
#define SERVICENAME 393
#define STRINGNAME 394
#define NUMBER 395
#define PERCENT 396
#define LOGLIMIT 397
#define CLOSELIMIT 398
#define DNSLIMIT 399
#define KEEPALIVELIMIT 400
#define REPLYLIMIT 401
#define REQUESTLIMIT 402
#define STARTLIMIT 403
#define WAITLIMIT 404
#define GRACEFULLIMIT 405
#define CLEANUPLIMIT 406
#define REAL 407
#define CHECKPROC 408
#define CHECKFILESYS 409
#define CHECKFILE 410
#define CHECKDIR 411
#define CHECKHOST 412
#define CHECKSYSTEM 413
#define CHECKFIFO 414
#define CHECKPROGRAM 415
#define CHECKNET 416
#define THREADS 417
#define CHILDREN 418
#define STATUS 419
#define ORIGIN 420
#define VERSIONOPT 421
#define RESOURCE 422
#define MEMORY 423
#define TOTALMEMORY 424
#define LOADAVG1 425
#define LOADAVG5 426
#define LOADAVG15 427
#define SWAP 428
#define MODE 429
#define ACTIVE 430
#define PASSIVE 431
#define MANUAL 432
#define ONREBOOT 433
#define NOSTART 434
#define LASTSTATE 435
#define CPU 436
#define TOTALCPU 437
#define CPUUSER 438
#define CPUSYSTEM 439
#define CPUWAIT 440
#define GROUP 441
#define REQUEST 442
#define DEPENDS 443
#define BASEDIR 444
#define SLOT 445
#define EVENTQUEUE 446
#define SECRET 447
#define HOSTHEADER 448
#define UID 449
#define EUID 450
#define GID 451
#define MMONIT 452
#define INSTANCE 453
#define USERNAME 454
#define PASSWORD 455
#define TIMESTAMP 456
#define CHANGED 457
#define MILLISECOND 458
#define SECOND 459
#define MINUTE 460
#define HOUR 461
#define DAY 462
#define MONTH 463
#define SSLAUTO 464
#define SSLV2 465
#define SSLV3 466
#define TLSV1 467
#define TLSV11 468
#define TLSV12 469
#define CERTMD5 470
#define AUTO 471
#define BYTE 472
#define KILOBYTE 473
#define MEGABYTE 474
#define GIGABYTE 475
#define INODE 476
#define SPACE 477
#define TFREE 478
#define PERMISSION 479
#define SIZE 480
#define MATCH 481
#define NOT 482
#define IGNORE 483
#define ACTION 484
#define UPTIME 485
#define EXEC 486
#define UNMONITOR 487
#define PING 488
#define PING4 489
#define PING6 490
#define ICMP 491
#define ICMPECHO 492
#define NONEXIST 493
#define EXIST 494
#define INVALID 495
#define DATA 496
#define RECOVERED 497
#define PASSED 498
#define SUCCEEDED 499
#define URL 500
#define CONTENT 501
#define PID 502
#define PPID 503
#define FSFLAG 504
#define REGISTER 505
#define CREDENTIALS 506
#define URLOBJECT 507
#define ADDRESSOBJECT 508
#define TARGET 509
#define TIMESPEC 510
#define HTTPHEADER 511
#define MAXFORWARD 512
#define FIPS 513
#define GREATER 514
#define GREATEROREQUAL 515
#define LESS 516
#define LESSOREQUAL 517
#define EQUAL 518
#define NOTEQUAL 519

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 306 "src/p.y" /* yacc.c:355  */

        URL_T url;
        Address_T address;
        float real;
        int   number;
        char *string;

#line 922 "src/y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 937 "src/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  271
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  232
/* YYNRULES -- Number of rules.  */
#define YYNRULES  741
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1346

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   519

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   267,     2,
       2,     2,     2,     2,   268,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   269,     2,   270,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   265,     2,   266,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   356,   356,   357,   360,   361,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   393,   394,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   420,   421,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   444,   445,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   466,   467,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   487,   488,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   506,   507,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   527,   528,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   545,   546,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   566,   567,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   583,   587,   590,
     596,   606,   611,   612,   615,   620,   623,   626,   631,   637,
     640,   641,   644,   647,   650,   653,   656,   659,   662,   665,
     668,   671,   674,   677,   680,   683,   688,   693,   701,   704,
     709,   712,   716,   722,   727,   732,   740,   743,   744,   747,
     753,   754,   757,   760,   761,   762,   763,   766,   767,   772,
     789,   792,   795,   796,   799,   803,   807,   811,   815,   818,
     828,   840,   852,   858,   859,   862,   876,   883,   892,   893,
     896,   900,   904,   908,   916,   924,   928,   934,   943,   950,
     965,   966,   969,   978,   989,   990,   993,   996,   999,  1000,
    1001,  1002,  1005,  1008,  1009,  1012,  1013,  1014,  1015,  1016,
    1017,  1020,  1023,  1036,  1037,  1040,  1041,  1042,  1045,  1046,
    1049,  1050,  1053,  1059,  1065,  1068,  1073,  1074,  1077,  1078,
    1081,  1086,  1091,  1098,  1103,  1106,  1114,  1118,  1122,  1126,
    1130,  1130,  1137,  1137,  1144,  1144,  1151,  1151,  1158,  1165,
    1166,  1169,  1175,  1176,  1179,  1182,  1185,  1192,  1201,  1206,
    1209,  1214,  1219,  1224,  1232,  1238,  1253,  1258,  1265,  1274,
    1277,  1282,  1285,  1291,  1294,  1299,  1300,  1303,  1304,  1307,
    1310,  1315,  1319,  1323,  1326,  1331,  1334,  1339,  1344,  1347,
    1352,  1361,  1362,  1365,  1366,  1367,  1368,  1369,  1370,  1371,
    1372,  1373,  1374,  1375,  1378,  1385,  1386,  1389,  1390,  1391,
    1392,  1393,  1394,  1397,  1403,  1404,  1407,  1408,  1409,  1410,
    1411,  1414,  1420,  1425,  1430,  1437,  1438,  1441,  1442,  1443,
    1444,  1447,  1450,  1455,  1460,  1466,  1469,  1474,  1477,  1481,
    1486,  1487,  1490,  1491,  1494,  1499,  1502,  1505,  1508,  1511,
    1514,  1517,  1522,  1525,  1530,  1533,  1536,  1539,  1542,  1545,
    1548,  1551,  1555,  1558,  1561,  1566,  1569,  1572,  1577,  1580,
    1583,  1586,  1589,  1592,  1595,  1598,  1601,  1604,  1607,  1612,
    1620,  1630,  1631,  1634,  1637,  1640,  1643,  1648,  1649,  1652,
    1655,  1660,  1661,  1664,  1672,  1677,  1680,  1685,  1690,  1691,
    1694,  1697,  1702,  1703,  1706,  1709,  1712,  1713,  1714,  1715,
    1716,  1719,  1725,  1731,  1736,  1742,  1743,  1748,  1753,  1754,
    1757,  1762,  1763,  1766,  1769,  1772,  1775,  1779,  1783,  1787,
    1791,  1795,  1799,  1803,  1807,  1811,  1817,  1824,  1830,  1836,
    1843,  1848,  1853,  1858,  1863,  1866,  1871,  1874,  1879,  1882,
    1887,  1890,  1895,  1898,  1903,  1908,  1913,  1919,  1927,  1933,
    1934,  1937,  1941,  1944,  1948,  1953,  1956,  1959,  1960,  1963,
    1964,  1965,  1966,  1967,  1968,  1969,  1970,  1971,  1972,  1973,
    1974,  1975,  1976,  1977,  1978,  1979,  1980,  1981,  1982,  1983,
    1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,  1994,  1995,
    1998,  1999,  2002,  2003,  2004,  2005,  2008,  2012,  2016,  2022,
    2025,  2028,  2034,  2037,  2041,  2046,  2053,  2056,  2057,  2060,
    2063,  2070,  2079,  2085,  2086,  2089,  2090,  2091,  2092,  2093,
    2096,  2102,  2103,  2106,  2107,  2108,  2109,  2112,  2117,  2124,
    2131,  2132,  2133,  2134,  2137,  2142,  2147,  2152,  2159,  2164,
    2171,  2178,  2185,  2192,  2193,  2194,  2197,  2198,  2201,  2207,
    2214,  2215,  2216,  2217,  2218,  2219,  2220,  2221,  2224,  2225,
    2226,  2227,  2228,  2229,  2232,  2233,  2234,  2236,  2237,  2239,
    2242,  2245,  2253,  2256,  2259,  2263,  2266,  2269,  2272,  2277,
    2288,  2299,  2309,  2321,  2322,  2327,  2334,  2335,  2340,  2347,
    2350,  2353,  2356,  2361,  2365,  2372,  2378,  2379,  2380,  2383,
    2390,  2397,  2404,  2413,  2422,  2429,  2438,  2447,  2453,  2454,
    2455,  2456,  2457,  2460,  2465,  2472,  2480,  2487,  2495,  2503,
    2510,  2516,  2523,  2531,  2534,  2540,  2546,  2553,  2559,  2566,
    2572,  2579,  2585,  2592,  2598,  2603,  2611,  2619,  2627,  2635,
    2643,  2651,  2661,  2669,  2677,  2685,  2693,  2701,  2711,  2714,
    2715,  2716
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "THEN", "OR", "FAILED",
  "SET", "LOGFILE", "FACILITY", "DAEMON", "SYSLOG", "MAILSERVER", "HTTPD",
  "ALLOW", "REJECTOPT", "ADDRESS", "INIT", "TERMINAL", "BATCH", "READONLY",
  "CLEARTEXT", "MD5HASH", "SHA1HASH", "CRYPT", "DELAY", "PEMFILE",
  "ENABLE", "DISABLE", "SSL", "CLIENTPEMFILE", "ALLOWSELFCERTIFICATION",
  "SELFSIGNED", "VERIFY", "CERTIFICATE", "CACERTIFICATEFILE",
  "CACERTIFICATEPATH", "VALID", "INTERFACE", "LINK", "PACKET", "BYTEIN",
  "BYTEOUT", "PACKETIN", "PACKETOUT", "SPEED", "SATURATION", "UPLOAD",
  "DOWNLOAD", "TOTAL", "IDFILE", "STATEFILE", "SEND", "EXPECT", "CYCLE",
  "COUNT", "REMINDER", "REPEAT", "LIMITS", "SENDEXPECTBUFFER",
  "EXPECTBUFFER", "FILECONTENTBUFFER", "HTTPCONTENTBUFFER",
  "PROGRAMOUTPUT", "NETWORKTIMEOUT", "PROGRAMTIMEOUT", "STARTTIMEOUT",
  "STOPTIMEOUT", "RESTARTTIMEOUT", "PIDFILE", "START", "STOP", "PATHTOK",
  "HOST", "HOSTNAME", "PORT", "IPV4", "IPV6", "TYPE", "UDP", "TCP",
  "TCPSSL", "PROTOCOL", "CONNECTION", "ALERT", "NOALERT", "MAILFORMAT",
  "UNIXSOCKET", "SIGNATURE", "TIMEOUT", "RETRY", "RESTART", "CHECKSUM",
  "EVERY", "NOTEVERY", "DEFAULT", "HTTP", "HTTPS", "APACHESTATUS", "FTP",
  "SMTP", "SMTPS", "POP", "POPS", "IMAP", "IMAPS", "CLAMAV", "NNTP",
  "NTP3", "MYSQL", "DNS", "WEBSOCKET", "SSH", "DWP", "LDAP2", "LDAP3",
  "RDATE", "RSYNC", "TNS", "PGSQL", "POSTFIXPOLICY", "SIP", "LMTP", "GPS",
  "RADIUS", "MEMCACHE", "REDIS", "MONGODB", "SIEVE", "STRING", "PATH",
  "MAILADDR", "MAILFROM", "MAILSENDER", "MAILREPLYTO", "MAILSUBJECT",
  "MAILBODY", "SERVICENAME", "STRINGNAME", "NUMBER", "PERCENT", "LOGLIMIT",
  "CLOSELIMIT", "DNSLIMIT", "KEEPALIVELIMIT", "REPLYLIMIT", "REQUESTLIMIT",
  "STARTLIMIT", "WAITLIMIT", "GRACEFULLIMIT", "CLEANUPLIMIT", "REAL",
  "CHECKPROC", "CHECKFILESYS", "CHECKFILE", "CHECKDIR", "CHECKHOST",
  "CHECKSYSTEM", "CHECKFIFO", "CHECKPROGRAM", "CHECKNET", "THREADS",
  "CHILDREN", "STATUS", "ORIGIN", "VERSIONOPT", "RESOURCE", "MEMORY",
  "TOTALMEMORY", "LOADAVG1", "LOADAVG5", "LOADAVG15", "SWAP", "MODE",
  "ACTIVE", "PASSIVE", "MANUAL", "ONREBOOT", "NOSTART", "LASTSTATE", "CPU",
  "TOTALCPU", "CPUUSER", "CPUSYSTEM", "CPUWAIT", "GROUP", "REQUEST",
  "DEPENDS", "BASEDIR", "SLOT", "EVENTQUEUE", "SECRET", "HOSTHEADER",
  "UID", "EUID", "GID", "MMONIT", "INSTANCE", "USERNAME", "PASSWORD",
  "TIMESTAMP", "CHANGED", "MILLISECOND", "SECOND", "MINUTE", "HOUR", "DAY",
  "MONTH", "SSLAUTO", "SSLV2", "SSLV3", "TLSV1", "TLSV11", "TLSV12",
  "CERTMD5", "AUTO", "BYTE", "KILOBYTE", "MEGABYTE", "GIGABYTE", "INODE",
  "SPACE", "TFREE", "PERMISSION", "SIZE", "MATCH", "NOT", "IGNORE",
  "ACTION", "UPTIME", "EXEC", "UNMONITOR", "PING", "PING4", "PING6",
  "ICMP", "ICMPECHO", "NONEXIST", "EXIST", "INVALID", "DATA", "RECOVERED",
  "PASSED", "SUCCEEDED", "URL", "CONTENT", "PID", "PPID", "FSFLAG",
  "REGISTER", "CREDENTIALS", "URLOBJECT", "ADDRESSOBJECT", "TARGET",
  "TIMESPEC", "HTTPHEADER", "MAXFORWARD", "FIPS", "GREATER",
  "GREATEROREQUAL", "LESS", "LESSOREQUAL", "EQUAL", "NOTEQUAL", "'{'",
  "'}'", "':'", "'@'", "'['", "']'", "$accept", "cfgfile",
  "statement_list", "statement", "optproclist", "optproc", "optfilelist",
  "optfile", "optfilesyslist", "optfilesys", "optdirlist", "optdir",
  "opthostlist", "opthost", "optnetlist", "optnet", "optsystemlist",
  "optsystem", "optfifolist", "optfifo", "optprogramlist", "optprogram",
  "setalert", "setdaemon", "setterminal", "startdelay", "setinit",
  "setonreboot", "setexpectbuffer", "setlimits", "limitlist", "limit",
  "setfips", "setlog", "seteventqueue", "setidfile", "setstatefile",
  "setpid", "setmmonits", "mmonitlist", "mmonit", "mmonitoptlist",
  "mmonitopt", "credentials", "setssl", "ssl", "ssloptionlist",
  "ssloption", "sslexpire", "expireoperator", "sslchecksum",
  "checksumoperator", "sslversion", "certmd5", "setmailservers",
  "setmailformat", "mailserverlist", "mailserver", "mailserveroptlist",
  "mailserveropt", "sethttpd", "httpdlist", "httpdoption", "sslserver",
  "optssllist", "optssl", "sslenable", "ssldisable", "httpdport",
  "httpdsocket", "signature", "sigenable", "sigdisable", "bindaddress",
  "pemfile", "clientpemfile", "allowselfcert", "allow", "$@1", "$@2",
  "$@3", "$@4", "allowuserlist", "allowuser", "readonly", "checkproc",
  "checkfile", "checkfilesys", "checkdir", "checkhost", "checknet",
  "checksystem", "checkfifo", "checkprogram", "start", "stop", "restart",
  "argumentlist", "useroptionlist", "argument", "useroption", "username",
  "password", "hostname", "connection", "connectionoptlist",
  "connectionopt", "connectionurl", "connectionurloptlist",
  "connectionurlopt", "connectionunix", "connectionuxoptlist",
  "connectionuxopt", "icmp", "icmpoptlist", "icmpopt", "host", "port",
  "unixsocket", "ip", "type", "typeoptlist", "typeopt", "outgoing",
  "protocol", "sendexpect", "websocketlist", "websocket", "smtplist",
  "smtp", "mysqllist", "mysql", "target", "maxforward", "siplist", "sip",
  "httplist", "http", "status", "request", "responsesum", "hostheader",
  "httpheaderlist", "secret", "radiuslist", "radius", "apache_stat_list",
  "apache_stat", "exist", "pid", "ppid", "uptime", "icmpcount", "icmpsize",
  "icmptimeout", "icmpoutgoing", "stoptimeout", "starttimeout",
  "restarttimeout", "programtimeout", "nettimeout", "connectiontimeout",
  "retry", "actionrate", "urloption", "urloperator", "alert", "alertmail",
  "noalertmail", "eventoptionlist", "eventoption", "formatlist",
  "formatoptionlist", "formatoption", "every", "mode", "onreboot", "group",
  "depend", "dependlist", "dependant", "statusvalue", "resourceprocess",
  "resourceprocesslist", "resourceprocessopt", "resourcesystem",
  "resourcesystemlist", "resourcesystemopt", "resourcecpuproc",
  "resourcecpu", "resourcecpuid", "resourcemem", "resourceswap",
  "resourcethreads", "resourcechild", "resourceload", "resourceloadavg",
  "value", "timestamp", "operator", "time", "totaltime", "currenttime",
  "repeat", "action", "action1", "action2", "rateXcycles", "rateXYcycles",
  "rate1", "rate2", "recovery", "checksum", "hashtype", "inode", "space",
  "fsflag", "unit", "permission", "match", "matchflagnot", "size", "uid",
  "euid", "gid", "linkstatus", "linkspeed", "linksaturation", "upload",
  "download", "icmptype", "reminder", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   123,   125,    58,    64,    91,
      93
};
# endif

#define YYPACT_NINF -640

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-640)))

#define YYTABLE_NINF -674

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     639,    30,   -20,    -7,    -2,    40,   113,   117,   148,   151,
     156,   323,   639,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,    82,   -37,   217,  -640,  -640,   332,  -109,    29,   237,
     121,   251,   288,   280,   163,    81,   183,   186,  -640,   -58,
       4,   378,   393,   407,   470,  -640,   423,   434,   140,  -640,
    -640,   842,   298,  1036,  1123,  1134,  1178,  1189,  1123,  1208,
     502,  -640,   402,   453,   -33,  -640,  1087,  -640,  -640,  -640,
    -640,  -640,   543,  -640,  -640,   533,  -640,  -640,  -640,   409,
     418,  -640,   186,   322,   295,   312,  1006,   525,   454,   476,
     435,   463,   501,   510,   457,   515,   487,   524,   531,   174,
     487,   487,   540,   487,   -93,   408,   626,   179,   547,   569,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,   -45,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,    56,  -139,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,    52,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,    45,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
      54,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   360,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  1146,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   -35,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   560,   693,  -640,   554,   400,
     571,  -640,   646,     3,   594,    25,    38,   593,   589,   609,
     620,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,    59,   137,  -640,  -640,  -640,  -640,  -640,   493,
     498,  -640,  -640,    18,  -640,   586,  -640,   232,   322,   491,
    -640,   533,  1006,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   273,  -640,   647,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,   219,  -640,
    -640,  -640,   103,   714,   615,   615,   615,   615,  -640,  -640,
    -640,   615,   615,   396,   565,   615,  1221,  -640,  -640,  -640,
    -640,  -640,  -640,   615,   433,   471,  -640,   489,   764,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,   569,
    -640,   566,  1006,   525,   114,   615,   102,   615,   565,   388,
     599,  -640,   388,   608,   -92,  -171,   631,   658,  -100,   -47,
     804,   615,   615,   615,   668,   810,   615,  -640,  -640,  -640,
    -640,  1164,  -640,  -640,   615,  -640,  -640,  -640,   615,   684,
    -640,   713,  -640,   591,   769,   136,   771,  -640,  -640,  -640,
    -640,  -640,  -640,   777,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   708,   793,  -640,   800,   819,   821,   681,   805,
     824,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   297,   297,   698,   700,   733,   735,   760,   762,
    -640,  -640,   766,   768,   773,   775,   776,   778,   780,   799,
     801,  -640,  -640,  -640,  -640,  -640,  -640,   832,   892,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,   244,   765,   950,  -640,
     989,   927,   309,   338,   -21,  -640,  -640,  -640,   942,   943,
     349,   355,   361,   823,   997,  -640,   937,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,   939,   944,   155,   155,   155,   155,
     945,   945,   945,   951,    -5,  -640,  -640,  -640,  1077,   155,
     952,   139,  -640,   953,   231,  -640,   954,   281,  -640,  -640,
    -640,  1006,   840,  -640,  -640,  -640,   957,   990,   960,   945,
     945,   945,  1008,   963,  -640,  -640,   623,   638,   641,   659,
     945,   615,   160,   615,   155,  -640,  -640,  -640,  1026,   945,
     969,   970,   973,   615,   615,   945,   155,  -640,  1109,   155,
     978,   945,  -640,   400,  -640,    22,  -640,  -640,  -640,  -640,
    -640,  -640,   993,   994,  1003,  1004,  1005,  1098,  1023,  1027,
    -640,  -640,  -640,  -640,  -640,  1028,   720,   808,  1033,  1034,
     770,   980,   996,  1017,  1050,  1051,  1053,  1056,  1058,  1059,
    -640,   962,  -640,   950,   525,  -640,   964,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   945,   945,   945,   945,   945,
     945,  -640,  1061,  -640,   605,  1119,  -640,  -640,  -640,  -640,
     315,   456,  1062,  1071,  1211,  1216,  1218,   734,  -640,  1158,
     293,  -640,  1021,  -640,  1029,  -640,  1030,  -640,   931,   950,
     945,   -24,   734,  1222,  1227,  1233,   945,   543,   945,   945,
     945,   945,  -640,  -640,  -640,  -640,  1234,   254,    26,  1099,
     155,   495,   105,   105,   105,  1011,  -640,  1236,  1102,    -8,
      -3,  1105,  1111,  1251,   514,   293,  1116,   945,  1253,    75,
     999,   999,  -640,  1129,  1005,  1005,  1005,  1098,  -640,  1005,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,   543,   543,   543,   543,   669,   685,   712,
     722,   741,  -640,   525,  -640,  -640,  1260,  1261,  1262,  1263,
    1264,  1266,    50,  -640,    93,  1147,  1148,   817,  1308,  1136,
    1142,  -640,  -640,  -640,  -640,  -640,  -640,  1280,  1282,  -640,
    -640,  -640,  -640,  -640,  -640,   293,   293,   293,  -640,  -640,
    -640,  -640,  -640,   945,  -640,  -640,  -640,  -640,  -640,   487,
    -640,  -640,  1284,  -640,  -640,  -640,   950,   525,  1285,  1159,
    1286,   945,   293,   293,   293,  1287,   945,  1290,  1291,  1293,
    1294,   293,    26,  1165,  1300,   945,   596,   945,   945,  1177,
    1170,  1173,  1181,  -640,  -640,  -640,  -640,  -640,  1318,  1319,
    1320,  -640,   105,   293,   945,  1122,  1122,  1122,  1122,   203,
     235,   293,  -640,  -640,  1284,  -640,  1323,   293,  -640,  1209,
    1210,  -640,  1005,  1005,  1005,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   293,   293,   293,   293,   293,   293,    46,   388,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  1333,  1212,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  1336,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   912,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,   -23,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  1139,  -640,   293,    73,  -640,  -640,  1284,
    1339,   201,  1343,  -640,   525,  -640,   293,   945,   293,  1345,
    -640,  1284,  -640,   293,  1346,   293,   293,   293,   293,  -640,
    1348,   945,   293,  1349,   945,   945,  1350,  1352,  -640,  -640,
    1154,  -640,   293,   293,   293,  1354,  1284,  1355,  -640,   945,
     945,   945,   945,   258,   310,   419,   552,  1284,  -640,   293,
    -640,  -640,  -640,  1284,  1284,  1284,  1284,  1284,  1284,  1103,
    1235,   293,  -640,   293,   655,   306,   306,  1237,   615,   615,
     615,   615,   615,   615,   615,   615,   615,   615,  -640,  -640,
     912,  -640,   642,   642,   642,  1239,  1240,  1231,  1241,   -23,
    -640,  -190,  1182,  -640,  1284,  -640,  -640,  -640,   293,  1279,
      28,  -640,   662,  -640,  1284,  1373,  1284,   293,  -640,  -640,
     293,  -640,  -640,  -640,  -640,   293,  1375,  1284,   293,  1376,
    1380,   293,   293,  -640,  1284,  1284,  1284,   293,  -640,   293,
    1383,  1392,  1393,  1394,   750,  -640,  -640,  -640,   945,   750,
     945,   750,   945,   750,   945,  -640,  1284,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  1247,  -640,  1284,  1284,  -640,  -640,
    -640,  1249,   615,  1269,  1265,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  1356,  1357,  1358,  1359,  1360,  1361,
    1362,  1363,  1364,  1365,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,   304,  1367,  -640,  -640,
    -640,  1271,  -640,  -640,  -640,  1284,   171,  -640,   945,   945,
     945,  -640,   293,  -640,  1284,  1284,  1284,   293,  -640,  1284,
     293,   293,  1284,  1284,  -640,  -640,  -640,  1284,  1284,   293,
     293,   293,   293,   945,  1489,   945,  1490,   945,  1501,   945,
    1503,  -640,  1302,  -640,  -640,  -640,  1370,  -640,  -640,    84,
    1371,  1372,  1377,  1378,  1379,  1381,  1384,  1385,  1386,  1387,
    -640,  -640,  -640,  -640,  -640,  -640,  1456,  -640,  -640,  1509,
    1510,  1511,  1284,  -640,  -640,  -640,  1284,  -640,  1284,  1284,
    -640,  -640,  -640,  -640,  1284,  1284,  1284,  1284,  1512,   293,
    1516,   293,  1518,   293,  1519,   293,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,   293,   293,   293,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   293,  1284,   293,  1284,   293,  1284,   293,  1284,
    -640,  -640,  -640,  -640,  1284,  -640,  1284,  -640,  1284,  -640,
    1284,  -640,  -640,  -640,  -640,  -640
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     6,     8,     9,    20,    22,    19,
      21,    23,    10,    11,    17,    18,    16,    12,     7,    13,
      14,    15,    33,    56,    76,    94,   111,   126,   143,   157,
     174,     0,     0,     0,   283,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,   578,
       0,     0,     0,     0,     0,   345,     0,     0,     0,     1,
       5,    24,    25,    26,    27,    28,    32,    29,    30,    31,
     218,   217,   192,   274,   532,   270,   282,   191,   242,   223,
     224,   200,   698,   225,   545,     0,   195,   196,   197,     0,
       0,   230,   226,   237,     0,     0,     0,   739,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,    36,    37,    45,    46,    47,    38,    39,    40,
      44,    48,    49,   578,   544,    50,    51,    52,    53,    54,
      55,    41,    42,    43,   713,   713,    57,    58,    59,    60,
      61,    63,    65,    64,    72,    73,    74,    75,    62,    69,
      66,    71,    70,    67,    68,     0,    77,    78,    79,    80,
      81,    83,    82,    87,    88,    89,    90,    91,    92,    93,
      84,    85,    86,     0,    95,    96,    97,    98,    99,   101,
     103,   102,   107,   108,   109,   110,   100,   104,   105,   106,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,     0,   127,   128,   129,   130,
     136,   140,   137,   138,   139,   141,   142,   131,   132,   133,
     134,   135,     0,   144,   145,   146,   147,   156,   148,   149,
     150,   151,   152,   153,   154,   155,   158,   159,   160,   161,
     162,   164,   166,   165,   170,   171,   172,   173,   163,   167,
     168,   169,     0,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,     0,   190,     0,   272,
       0,   271,   368,     0,     0,     0,     0,     0,     0,     0,
       0,   284,   285,   293,   293,   289,   290,   286,   304,   305,
     287,   288,     0,     0,   699,   700,   701,   702,   198,     0,
       0,   584,   585,     0,   580,   220,   222,   229,   237,     0,
     227,     0,     0,   562,   550,   551,   564,   565,   572,   570,
     553,   574,   552,   573,   569,   576,   558,   560,   575,   566,
     571,   549,   577,   556,   559,   563,   561,   555,   554,   567,
     568,   557,     0,   547,     0,   187,   334,   335,   336,   337,
     340,   339,   338,   341,   342,   346,   359,   360,   530,   355,
     343,   344,   411,     0,   640,   640,   640,   640,   633,   634,
     635,   640,   640,     0,     0,   640,   673,   603,   605,   606,
     607,   608,   609,   640,   526,   524,   546,   528,     0,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   599,   596,
     597,     0,     0,   739,   686,   640,   686,   640,   714,     0,
       0,   714,     0,     0,     0,     0,   640,   640,     0,   411,
       0,   640,   640,   640,     0,     0,   640,   623,   620,   621,
     622,   673,   611,   616,   640,   614,   615,   613,   640,     0,
     219,     0,   274,   240,     0,     0,     0,   265,   260,   261,
     262,   263,   264,     0,   266,   278,   279,   280,   281,   275,
     276,   277,     0,     0,   268,     0,     0,     0,   328,   316,
       0,   310,   299,   307,   301,   309,   298,   300,   302,   303,
     306,   308,   292,   291,     0,     0,     0,     0,     0,     0,
     239,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   201,   582,   583,   269,   581,     0,     0,   231,
     233,   234,   235,   236,   228,   238,     0,     0,   578,   548,
     740,     0,     0,     0,   530,   356,   357,   347,     0,     0,
       0,     0,     0,     0,     0,   394,     0,   647,   641,   642,
     643,   644,   645,   646,     0,     0,     0,     0,     0,     0,
     673,   673,   673,     0,     0,   604,   674,   675,     0,     0,
       0,   526,   349,     0,   524,   351,     0,   528,   353,   586,
     598,     0,     0,   541,   687,   688,     0,     0,     0,   673,
     673,   673,     0,     0,   539,   540,     0,     0,     0,     0,
     673,   640,     0,   640,     0,   405,   405,   405,     0,   673,
       0,     0,     0,   640,   640,   673,     0,   612,     0,     0,
       0,   673,   193,   273,   242,   258,   366,   365,   367,   267,
     533,   369,   317,   318,   319,     0,     0,   332,     0,     0,
     313,   294,   295,   296,   297,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,   579,   578,   739,   741,     0,   361,   363,   362,
     364,   358,   348,   412,   414,   673,   673,   673,   673,   673,
     673,   385,     0,   371,   673,     0,   630,   631,   637,   636,
     698,   698,     0,     0,     0,     0,     0,   648,   671,     0,
       0,   632,     0,   350,     0,   352,     0,   354,     0,   578,
     673,   673,   648,     0,     0,     0,   673,   698,   673,   673,
     673,   673,   708,   707,   712,   711,     0,     0,   637,     0,
       0,   698,   673,   673,   673,     0,   405,     0,     0,   698,
     698,     0,     0,     0,   698,     0,     0,   673,     0,     0,
     258,   258,   259,     0,     0,     0,     0,   332,   331,   321,
     329,   333,   315,   311,   312,   249,   246,   247,   244,   245,
     250,   251,   248,   698,   698,   698,   698,     0,     0,     0,
       0,     0,   232,   739,   188,   531,     0,     0,     0,     0,
       0,     0,   673,   413,   673,     0,     0,     0,     0,     0,
       0,   395,   396,   397,   398,   399,   400,     0,     0,   625,
     624,   627,   626,   617,   618,     0,     0,     0,   649,   650,
     651,   652,   653,   673,   672,   666,   667,   662,   665,     0,
     668,   669,   679,   527,   525,   529,   578,   739,     0,     0,
       0,   673,     0,     0,     0,     0,   673,     0,     0,     0,
       0,     0,   637,     0,     0,   673,   698,   673,   673,     0,
       0,     0,     0,   406,   407,   408,   409,   410,     0,     0,
       0,   738,   673,     0,   673,   657,   657,   657,   657,   698,
     698,     0,   629,   628,   679,   619,     0,     0,   241,     0,
       0,   255,   323,   325,   327,   314,   330,   202,   203,   204,
     205,   206,   207,   208,   209,   212,   213,   210,   211,   214,
     215,   189,     0,     0,     0,     0,     0,     0,     0,     0,
     390,   392,   391,   386,   388,   389,   387,     0,     0,   415,
     416,   381,   383,   382,   372,   373,   374,   379,   375,   376,
     378,   380,   377,     0,   459,   460,   419,   417,   420,   426,
     482,   482,     0,   429,   467,   467,   443,   444,   432,   433,
     434,   440,   441,   471,   427,     0,   448,   428,   435,   436,
     449,   451,   452,   453,   442,   478,   454,   455,   498,   457,
     450,   437,   445,     0,   535,     0,     0,   517,   518,   679,
       0,   659,     0,   602,   739,   542,     0,   673,     0,     0,
     639,   679,   716,     0,     0,     0,     0,     0,     0,   697,
       0,   673,     0,     0,   673,   673,     0,     0,   523,   520,
       0,   521,     0,     0,     0,     0,   679,     0,   658,   673,
     673,   673,   673,     0,     0,     0,     0,   679,   610,     0,
     601,   256,   257,   679,   679,   679,   679,   679,   679,   253,
       0,     0,   424,     0,   418,   430,   431,     0,   640,   640,
     640,   640,   640,   640,   640,   640,   640,   640,   503,   504,
     425,   501,   446,   447,   438,     0,     0,     0,     0,   458,
     461,   439,   456,   534,   679,   537,   536,   516,     0,     0,
     659,   663,     0,   543,   679,     0,   679,     0,   704,   685,
       0,   706,   705,   710,   709,     0,     0,   679,     0,     0,
       0,     0,     0,   522,   679,   679,   679,     0,   723,     0,
       0,     0,     0,     0,     0,   654,   655,   656,   673,     0,
     673,     0,   673,     0,   673,   724,   679,   717,   718,   719,
     720,   721,   722,   254,     0,   538,   679,   679,   422,   423,
     421,     0,   640,     0,     0,   495,   484,   485,   483,   488,
     486,   487,   489,   505,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   502,   469,   470,   468,   473,   474,
     472,   465,   463,   466,   464,   462,     0,     0,   480,   481,
     479,     0,   500,   499,   393,   679,     0,   664,   676,   676,
     676,   703,     0,   683,   679,   679,   679,     0,   689,   679,
       0,     0,   679,   679,   402,   403,   404,   679,   679,     0,
       0,     0,     0,   673,     0,   673,     0,   673,     0,   673,
       0,   600,     0,   384,   370,   493,     0,   492,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     476,   475,   477,   497,   519,   660,     0,   677,   678,     0,
       0,     0,   679,   638,   715,   691,   679,   690,   679,   679,
     694,   693,   401,   725,   679,   679,   679,   679,     0,     0,
       0,     0,     0,     0,     0,     0,   252,   491,   496,   490,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     661,     0,     0,     0,   684,   692,   696,   695,   729,   726,
     735,   732,     0,   679,     0,   679,     0,   679,     0,   679,
     670,   680,   681,   682,   679,   730,   679,   727,   679,   736,
     679,   733,   731,   728,   737,   734
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -640,  -640,  -640,  1517,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    1428,  -640,  -640,  1203,  -640,  -314,   898,  -640,   729,  -640,
    -310,   227,  -326,  -325,  -640,  -640,  -640,  1450,  1073,  -640,
    -640,  -640,  -640,  -640,  1232,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,   204,  -639,   772,  -640,  -640,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  1066,  1074,  1110,  -117,  -395,  -370,
    -508,  -538,  -357,  -640,  1462,  -640,  -640,  1463,  -640,  -640,
    -640,  -640,  -640,  -640,  -518,  -640,  -640,  -640,  -640,  -640,
     736,  -640,  -640,  -640,   737,   738,  -640,   455,   578,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,   584,  -640,  -640,  -640,
    -640,  -640,  -640,  -640,  -640,  -640,  -640,   466,   556,  -640,
    -640,  1470,  -640,  -640,  -640,  -640,   965,   967,   966,  1007,
    -640,  -266,  -255,  1366,   746,  -421,  1374,  1551,  -640,  -309,
    -344,  -136,  1223,  -304,  1382,  1390,  1398,  1406,  1414,  -640,
    1137,  -640,  -640,  -640,  1161,  -640,  -640,  1104,  -640,  -640,
    -640,  -220,  -640,  -640,  -640,  -202,  -640,   206,   -16,  -371,
     836,  -563,   111,   459,  -320,  -465,  -290,  -200,  -191,  -451,
    -184,  -376,  -640,  1135,  -640,  -640,  -640,  -146,   145,  -640,
    1405,  -640,   705,  -640,   749,  -640,  -640,  -640,  -640,  -640,
    -640,  -418
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    71,   130,    72,   156,    73,   176,
      74,   194,    75,   211,    76,   226,    77,   243,    78,   256,
      79,   273,    14,    15,    16,   287,    17,    18,    19,    20,
     313,   522,    21,    22,    23,    24,    25,    26,    27,   102,
     103,   327,   529,   330,    28,   475,   312,   511,   931,  1154,
     476,   763,   477,   478,    29,    30,    84,    85,   289,   479,
      31,    86,   301,   302,   502,   651,   303,   304,   305,   306,
     307,   308,   309,   310,   652,   653,   654,   311,   646,   764,
     765,   766,   769,   770,   772,    32,    33,    34,    35,    36,
      37,    38,    39,    40,   131,   132,   133,   378,   544,   379,
     546,   480,   481,   484,   134,   804,   944,   135,   802,   933,
     136,   694,   811,   217,   742,   873,   554,   693,   555,   945,
     812,  1064,  1160,   947,   813,   814,  1089,  1090,  1082,  1187,
    1084,  1190,  1198,  1199,  1091,  1200,  1065,  1168,  1169,  1170,
    1171,  1172,  1249,  1202,  1092,  1203,  1080,  1081,   137,   138,
     139,   140,   874,   875,   876,   877,   585,   582,   588,   547,
     292,   815,   816,   141,   936,   606,   142,   143,   144,   362,
     363,   107,   323,   324,   145,   146,   147,   148,   149,   419,
     420,   284,   150,   396,   397,   255,   451,   452,   398,   453,
     454,   399,   456,   400,   401,   402,   403,   700,   168,   564,
     833,  1138,  1039,  1101,   841,   842,  1331,   576,   577,   578,
    1269,  1003,   169,   597,   187,   188,   189,   318,   170,   171,
     430,   172,   151,   152,   153,   237,   238,   239,   240,   241,
     746,   365
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     628,   532,   533,   404,   405,   593,   407,   423,   545,   581,
     584,   608,   587,   530,   565,   566,   567,   531,   539,   526,
     568,   569,   455,   537,   573,   485,   486,   548,   487,   104,
     849,  -673,   579,   885,   545,   545,   681,   545,   887,    41,
     457,    42,   104,    43,    44,   760,   761,   408,    45,    46,
     708,  1085,   434,   600,   598,   492,   603,   290,   206,   434,
      47,   439,   268,   424,  1196,   612,   614,  1197,   494,   541,
     620,   621,   622,   681,   108,   626,   681,   109,   610,   681,
     463,    48,    49,   629,  1059,   928,  1099,   630,   431,    50,
     504,    51,   505,   506,    80,   507,   508,    83,   743,   744,
      52,   599,   550,    82,   552,   383,   504,   432,   505,   506,
     938,   507,   508,   592,   493,    53,   574,    54,    60,   704,
     705,   706,   869,   463,   600,   594,   595,   495,   928,   458,
     906,    61,   596,   488,   489,   709,    62,   594,   595,   635,
     809,   810,  1086,  1087,   835,   836,   805,   806,   723,   724,
     725,   319,    96,   320,   321,   322,    88,   117,   837,   736,
      89,   870,   409,  1095,  1088,   838,   574,   459,   747,   105,
     939,   940,   807,   542,   753,   543,   808,   548,    63,   118,
     758,   382,   421,   809,   810,   383,   615,   616,   617,   618,
     574,   549,   383,   539,   383,   871,   383,   512,   553,   513,
     514,   515,   516,   517,   518,   519,   520,   106,    55,   314,
     315,   316,   317,    81,   314,   315,   316,   317,   190,   207,
     422,    56,   542,   269,   543,   509,  1265,    57,   882,   580,
     110,   455,   526,   574,   796,   797,   798,   799,   800,   801,
     737,   509,   740,   817,  1043,   574,   425,   438,   539,   457,
     414,    64,   751,   752,   435,    65,   794,   425,   426,  1099,
      97,    98,   463,   906,   906,   906,   636,   464,   637,   848,
     850,   490,   394,   436,   437,   855,  1045,   857,   858,   859,
     860,   427,   718,   428,   525,   762,    66,   864,    58,    67,
     894,   878,   879,   880,    68,   698,   929,   550,   551,   552,
     738,   154,   429,   599,   839,   840,   896,   699,   550,   541,
     552,  1266,   699,   333,   383,   334,   335,   336,   337,   338,
     339,   583,   528,    69,   648,   510,   600,   601,   649,   650,
     872,   376,   377,   542,   782,   543,   384,   385,   596,   929,
    1298,   898,   386,   387,   388,   389,   390,    83,   553,   376,
     377,   937,    87,   953,  1299,   391,   392,   340,   415,   416,
     997,   998,   999,   341,   835,   836,   342,   440,    90,   120,
     121,   586,    99,   100,   539,   921,   393,   319,   837,   320,
     321,   322,  1000,    53,   122,   838,    91,  1010,  1011,  1012,
     123,    92,   124,   125,   862,   542,  1019,   543,  1134,  1161,
    1009,   394,   674,   521,   395,  1014,   699,   441,   442,   443,
     444,  1020,    94,   542,  1023,   543,  1026,  1027,  1036,    93,
     314,   315,   316,   317,  1078,   542,  1047,   543,    95,  1005,
     463,  1035,  1050,  1037,  1260,   464,  1261,   343,   101,   677,
     344,   467,   468,   469,   470,   471,   472,   473,   474,   678,
    1139,   111,   314,   315,   316,   317,   819,  1053,  1054,  1055,
    1056,  1057,  1058,  1135,  1136,  1137,   112,   345,   679,   346,
    1162,   347,   126,   286,   348,   542,   127,   543,   680,   685,
     113,  1140,  1142,  1144,   128,   687,   129,   114,   930,   686,
     941,   689,   932,  1163,   943,   688,   115,   349,   350,  1164,
     383,   690,   351,   352,   353,   465,   466,   116,  1060,   354,
     672,   355,   285,   356,   357,  1135,  1136,  1137,  1048,   358,
     359,   360,   361,   580,   839,   840,   155,  1166,  1166,   288,
    1094,  1096,   314,   315,   316,   317,   934,   793,   950,   538,
     325,  1104,  1078,  1106,  1185,  1185,  1188,   935,  1109,   951,
    1111,  1112,  1113,  1114,   820,   822,  1105,  1117,   326,  1141,
     331,   583,   445,   376,   377,   368,   369,  1124,  1125,  1126,
    1116,  1233,   329,  1119,  1120,  1165,  1235,   332,  1237,   586,
    1239,   856,   364,   847,  1146,   366,  1103,   374,  1130,  1131,
    1132,  1133,   681,   370,   371,   868,  1156,   821,  1157,   465,
     466,   376,   377,   886,   888,  1079,  1100,   367,   893,   467,
     468,   469,   470,   471,   472,   473,   474,   376,   377,   376,
     377,   496,   497,  1097,  1135,  1136,  1137,   542,   160,   543,
     198,   545,   372,  1205,   260,  1108,   867,   907,   908,   909,
     910,   373,  1214,   570,   571,  1215,   375,     1,   500,   501,
    1216,   604,   605,  1219,   380,   892,  1222,  1223,   805,   806,
    1128,   381,  1227,   410,  1228,   542,   319,   543,   320,   321,
     322,  1145,   406,   314,   315,   316,   317,  1147,  1148,  1149,
    1150,  1151,  1152,   542,   807,   543,   417,  1234,   808,  1236,
     460,  1238,  1143,  1240,   462,   809,   810,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,   418,  1167,  1167,
    1004,   482,   314,   315,   316,   317,   623,   624,  1204,   461,
    1025,   483,  1001,  1079,   491,  1186,  1186,  1189,  1211,   498,
    1213,   314,   315,   316,   317,   776,   777,  1024,  1158,  1159,
     499,  1218,   535,  1044,  1046,   574,   523,  1272,  1224,  1225,
    1226,   524,  1276,   728,   729,  1278,  1279,  1135,  1136,  1137,
     314,   315,   316,   317,  1284,  1285,  1286,  1287,   730,   731,
    1241,   732,   733,   701,   702,   703,   527,   173,   191,   208,
    1243,  1244,  1288,   270,  1290,   711,  1292,   540,  1294,   734,
     735,  1246,     2,     3,     4,     5,     6,     7,     8,     9,
      10,   411,   412,   413,   572,   333,   556,   334,   335,   336,
     337,   338,   339,   314,   315,   316,   317,   557,   739,   589,
     741,   174,   192,   209,  1323,   607,  1325,   271,  1327,  1264,
    1329,   591,   754,   557,   609,   756,   778,   779,  1273,  1274,
    1275,   465,   466,  1277,   619,   119,  1280,  1281,   631,   340,
     625,  1282,  1283,   632,   611,   341,   634,  1334,   342,  1336,
     557,  1338,   635,  1340,   467,   468,   469,   470,   471,   472,
     473,   474,   911,   912,   558,   559,   560,   561,   562,   563,
     333,   613,   334,   335,   336,   337,   338,   339,   913,   914,
     558,   559,   560,   561,   562,   563,  1314,   956,   957,   958,
    1315,   638,  1316,  1317,  1208,  1209,  1210,   639,  1318,  1319,
    1320,  1321,   640,   120,   121,   915,   916,   558,   559,   560,
     561,   562,   563,   641,   340,   917,   918,    53,   122,   343,
     341,   642,   344,   342,   123,  -320,   124,   125,   828,   829,
     830,   831,   832,   863,   919,   920,   866,  1335,   645,  1337,
     643,  1339,   644,  1341,   647,  1135,  1136,  1137,  1342,   345,
    1343,   346,  1344,   347,  1345,   655,   348,   656,   902,   903,
     904,   333,   670,   334,   335,   336,   337,   338,   339,   467,
     468,   469,   470,   471,   472,  1067,   474,   899,   900,   349,
     350,  1330,  1330,  1330,   351,   352,   353,  1040,  1041,  1042,
     657,   354,   658,   355,   343,   356,   357,   344,  1267,  1267,
    1267,   358,   359,   360,   361,   340,   126,  1268,  1268,  1268,
     127,   341,  1332,  1333,   342,  1270,  1271,   659,   128,   660,
     129,   673,   671,   661,   345,   662,   346,   104,   347,   175,
     663,   348,   664,   665,   675,   666,   333,   667,   334,   335,
     336,   337,   338,   339,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,   349,   350,   668,   676,   669,   351,
     352,   353,   683,   692,   684,   691,   354,   695,   355,   696,
     356,   357,   710,   721,   697,   574,   358,   359,   360,   361,
     340,   707,   712,   714,   716,   343,   341,   720,   344,   342,
     722,   726,   293,   727,   294,   745,   719,   120,   121,   748,
     749,   465,   466,   750,   755,   295,   296,   297,   757,   771,
     783,    53,   122,  -322,  -324,   345,   193,   346,   123,   347,
     124,   125,   348,  -326,   767,   768,   784,   210,   157,   177,
     195,   212,   227,   244,   257,   274,   158,   178,   196,   213,
     228,   245,   258,   275,   773,   349,   350,   785,   774,   775,
     351,   352,   353,   298,   780,   781,   792,   354,   795,   355,
     343,   356,   357,   344,   818,   299,   300,   358,   359,   360,
     361,   225,   159,   179,   197,   214,   229,   246,   259,   276,
     786,   787,   242,   788,   120,   121,   789,   846,   790,   791,
     345,   803,   346,   823,   347,   120,   121,   348,    53,   122,
     126,   272,   824,   834,   127,   123,   825,   124,   125,    53,
     122,   826,   128,   827,   129,   843,   123,   852,   124,   125,
     349,   350,   853,   844,   845,   351,   352,   353,   854,   861,
     865,   883,   354,   884,   355,   889,   356,   357,   881,   120,
     121,   890,   358,   359,   360,   361,   891,   895,   897,   901,
     120,   121,   762,    53,   122,   922,   923,   924,   925,   926,
     123,   927,   124,   125,    53,   122,   993,   954,   955,   120,
     121,   123,   994,   124,   125,   995,   383,   996,  1002,  1007,
    1006,  1008,  1013,    53,   122,  1015,  1016,   126,  1017,  1018,
     123,   127,   124,   125,   574,  1022,  1021,  1028,   126,   128,
    1029,   129,   127,  1030,   386,   387,   388,   389,   390,   446,
     128,  1031,   129,  1032,  1033,  1034,  1038,   447,  1049,   448,
     449,   450,   386,   387,   388,   389,   390,   446,  1061,  1051,
    1052,  1063,  1062,  1093,  1098,   447,  1102,   448,   449,   450,
    1107,  1110,   126,  1115,  1118,  1121,   127,  1122,  1123,  1127,
    1129,   574,  1153,   126,   128,  1155,   129,   127,  1173,  1191,
    1192,  1193,  1194,  1206,  1201,   128,   395,   129,  1212,  1245,
    1217,  1220,   126,   384,   385,  1221,   127,  1242,  1229,   386,
     387,   388,   389,   390,   128,  1248,   129,  1230,  1231,  1232,
    1247,  1263,   391,   392,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   980,   981,   982,   983,   984,
     985,   986,   987,   988,   989,   990,   991,   992,   161,   180,
     199,   218,   230,   248,   261,   277,   162,   181,   200,   219,
     231,   249,   262,   278,   163,   182,   201,   220,   232,   250,
     263,   279,   164,   183,   202,   221,   233,   251,   264,   280,
     165,   184,   203,   222,   234,   252,   265,   281,   166,   185,
     204,   223,   235,   253,   266,   282,   167,   186,   205,   224,
     236,   254,   267,   283,  1289,  1291,  1250,  1251,  1252,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1293,  1262,  1295,  1296,
    1297,  1310,  1300,  1301,  1311,  1312,  1313,  1322,  1302,  1303,
    1304,  1324,  1305,  1326,  1328,  1306,  1307,  1308,  1309,    70,
     328,   534,   759,   942,   291,   633,   503,   215,   216,   905,
     946,   948,   949,  1083,  1195,  1066,  1184,   247,   713,   715,
     952,   682,    59,   717,   536,   627,   590,   575,   851,  1207,
     433,   602
};

static const yytype_uint16 yycheck[] =
{
     451,   327,   327,   120,   121,   423,   123,   143,   378,   404,
     405,   432,   407,   327,   385,   386,   387,   327,   362,   323,
     391,   392,   242,   332,   395,    22,    23,    74,    25,    87,
      54,     5,   403,    41,   404,   405,   544,   407,    41,     9,
     242,    11,    87,    13,    14,    23,    24,   140,    18,    19,
      55,    74,     7,   224,   425,    30,   427,    90,    74,     7,
      30,     7,    78,     7,   254,   436,   437,   257,    30,    90,
     441,   442,   443,   581,    70,   446,   584,    73,   249,   587,
      30,    51,    52,   454,    38,    35,    58,   458,   227,    59,
      31,    61,    33,    34,    12,    36,    37,   130,   616,   617,
      70,   201,   194,   140,   196,   140,    31,   246,    33,    34,
      17,    36,    37,   422,    89,    85,   140,    87,   138,   570,
     571,   572,    17,    30,   224,    23,    24,    89,    35,   164,
     769,   138,   224,   130,   131,   140,   138,    23,    24,    93,
      90,    91,   165,   166,    71,    72,    53,    54,   599,   600,
     601,   133,    71,   135,   136,   137,   265,    17,    85,   610,
     131,    56,   255,    90,   187,    92,   140,   202,   619,   227,
      77,    78,    79,   194,   625,   196,    83,    74,   138,    39,
     631,     7,   227,    90,    91,   140,   233,   234,   235,   236,
     140,    88,   140,   537,   140,    90,   140,    60,   245,    62,
      63,    64,    65,    66,    67,    68,    69,   265,   178,   217,
     218,   219,   220,   131,   217,   218,   219,   220,    73,    74,
     265,   191,   194,    78,   196,   166,    55,   197,   746,    90,
     226,   451,   536,   140,   685,   686,   687,   688,   689,   690,
     611,   166,   613,   694,    41,   140,   201,   202,   592,   451,
      71,   138,   623,   624,   202,   138,   674,   201,   202,    58,
     179,   180,    30,   902,   903,   904,   130,    35,   132,   720,
     721,   268,   227,   221,   222,   726,    41,   728,   729,   730,
     731,   225,   591,   227,   266,   263,   138,   738,   258,   138,
     755,   742,   743,   744,   138,   140,   246,   194,   195,   196,
     140,     3,   246,   201,   231,   232,   757,   152,   194,    90,
     196,   140,   152,    40,   140,    42,    43,    44,    45,    46,
      47,    90,    90,     0,    27,   266,   224,   225,    31,    32,
     225,   130,   131,   194,   660,   196,   162,   163,   224,   246,
     256,   266,   168,   169,   170,   171,   172,   130,   245,   130,
     131,   802,    20,   804,   270,   181,   182,    84,   179,   180,
     825,   826,   827,    90,    71,    72,    93,     7,   131,    71,
      72,    90,   189,   190,   718,   793,   202,   133,    85,   135,
     136,   137,   833,    85,    86,    92,   265,   852,   853,   854,
      92,   140,    94,    95,   140,   194,   861,   196,   140,    93,
     851,   227,   538,   266,   230,   856,   152,    47,    48,    49,
      50,   862,   132,   194,   865,   196,   867,   868,   883,   131,
     217,   218,   219,   220,   962,   194,   891,   196,   265,   847,
      30,   882,   897,   884,   130,    35,   132,   164,   252,   130,
     167,   209,   210,   211,   212,   213,   214,   215,   216,   140,
     140,    73,   217,   218,   219,   220,   141,   922,   923,   924,
     925,   926,   927,   205,   206,   207,    73,   194,   130,   196,
     164,   198,   174,    71,   201,   194,   178,   196,   140,   130,
      73,  1044,  1045,  1046,   186,   130,   188,    17,   802,   140,
     804,   130,   802,   187,   804,   140,    73,   224,   225,   193,
     140,   140,   229,   230,   231,   199,   200,    73,   929,   236,
     266,   238,    10,   240,   241,   205,   206,   207,   894,   246,
     247,   248,   249,    90,   231,   232,   228,  1065,  1066,    76,
     995,   996,   217,   218,   219,   220,   802,   673,   804,   266,
     131,  1006,  1080,  1008,  1082,  1083,  1084,   802,  1013,   804,
    1015,  1016,  1017,  1018,   700,   701,  1007,  1022,   140,   140,
     265,    90,   202,   130,   131,   130,   131,  1032,  1033,  1034,
    1021,  1134,   250,  1024,  1025,   269,  1139,   265,  1141,    90,
    1143,   727,    57,   719,  1049,   131,  1004,   130,  1039,  1040,
    1041,  1042,  1100,   130,   131,   741,  1061,   141,  1063,   199,
     200,   130,   131,   749,   750,   962,  1001,   131,   754,   209,
     210,   211,   212,   213,   214,   215,   216,   130,   131,   130,
     131,    28,    29,   999,   205,   206,   207,   194,    72,   196,
      74,  1001,   131,  1098,    78,  1011,   141,   783,   784,   785,
     786,   131,  1107,   247,   248,  1110,   131,     8,    28,    29,
    1115,   263,   264,  1118,   130,   141,  1121,  1122,    53,    54,
    1036,   130,  1127,   255,  1129,   194,   133,   196,   135,   136,
     137,  1047,   132,   217,   218,   219,   220,  1053,  1054,  1055,
    1056,  1057,  1058,   194,    79,   196,   139,  1138,    83,  1140,
     130,  1142,   140,  1144,   140,    90,    91,  1068,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,   138,  1065,  1066,
     846,   140,   217,   218,   219,   220,    48,    49,  1094,    26,
     866,    75,   839,  1080,   130,  1082,  1083,  1084,  1104,   140,
    1106,   217,   218,   219,   220,    15,    16,   141,  1064,  1064,
     131,  1117,   251,   889,   890,   140,   253,  1212,  1124,  1125,
    1126,   253,  1217,   130,   131,  1220,  1221,   205,   206,   207,
     217,   218,   219,   220,  1229,  1230,  1231,  1232,   130,   131,
    1146,   130,   131,   567,   568,   569,   190,    72,    73,    74,
    1156,  1157,  1233,    78,  1235,   579,  1237,   140,  1239,   130,
     131,  1162,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   175,   176,   177,   239,    40,    92,    42,    43,    44,
      45,    46,    47,   217,   218,   219,   220,   202,   612,    55,
     614,    72,    73,    74,  1289,   226,  1291,    78,  1293,  1205,
    1295,   265,   626,   202,   226,   629,    28,    29,  1214,  1215,
    1216,   199,   200,  1219,    40,     3,  1222,  1223,   164,    84,
      40,  1227,  1228,   140,   223,    90,   265,  1322,    93,  1324,
     202,  1326,    93,  1328,   209,   210,   211,   212,   213,   214,
     215,   216,   203,   204,   259,   260,   261,   262,   263,   264,
      40,   223,    42,    43,    44,    45,    46,    47,   203,   204,
     259,   260,   261,   262,   263,   264,  1272,    80,    81,    82,
    1276,   130,  1278,  1279,   242,   243,   244,   130,  1284,  1285,
    1286,  1287,   204,    71,    72,   203,   204,   259,   260,   261,
     262,   263,   264,   130,    84,   203,   204,    85,    86,   164,
      90,   131,   167,    93,    92,   130,    94,    95,   204,   205,
     206,   207,   208,   737,   203,   204,   740,  1323,   267,  1325,
     131,  1327,   131,  1329,   130,   205,   206,   207,  1334,   194,
    1336,   196,  1338,   198,  1340,   267,   201,   267,   764,   765,
     766,    40,   140,    42,    43,    44,    45,    46,    47,   209,
     210,   211,   212,   213,   214,    73,   216,   760,   761,   224,
     225,  1311,  1312,  1313,   229,   230,   231,   886,   887,   888,
     267,   236,   267,   238,   164,   240,   241,   167,  1208,  1209,
    1210,   246,   247,   248,   249,    84,   174,  1208,  1209,  1210,
     178,    90,  1312,  1313,    93,  1209,  1210,   267,   186,   267,
     188,   266,   140,   267,   194,   267,   196,    87,   198,     3,
     267,   201,   267,   267,    55,   267,    40,   267,    42,    43,
      44,    45,    46,    47,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   224,   225,   267,   140,   267,   229,
     230,   231,   130,    76,   131,   252,   236,   140,   238,   140,
     240,   241,     5,    93,   140,   140,   246,   247,   248,   249,
      84,   140,   140,   140,   140,   164,    90,   140,   167,    93,
     140,    93,    15,   140,    17,    79,   266,    71,    72,   140,
     140,   199,   200,   140,     5,    28,    29,    30,   140,    21,
     140,    85,    86,   130,   130,   194,     3,   196,    92,   198,
      94,    95,   201,   130,   130,   130,   140,     3,    72,    73,
      74,    75,    76,    77,    78,    79,    72,    73,    74,    75,
      76,    77,    78,    79,   131,   224,   225,   140,   131,   131,
     229,   230,   231,    76,   131,   131,   204,   236,   204,   238,
     164,   240,   241,   167,    55,    88,    89,   246,   247,   248,
     249,     3,    72,    73,    74,    75,    76,    77,    78,    79,
     140,   140,     3,   140,    71,    72,   140,   266,   140,   140,
     194,   140,   196,   141,   198,    71,    72,   201,    85,    86,
     174,     3,   141,    55,   178,    92,     5,    94,    95,    85,
      86,     5,   186,     5,   188,   204,    92,     5,    94,    95,
     224,   225,     5,   204,   204,   229,   230,   231,     5,     5,
     141,     5,   236,   141,   238,   140,   240,   241,   237,    71,
      72,   140,   246,   247,   248,   249,     5,   141,     5,   130,
      71,    72,   263,    85,    86,     5,     5,     5,     5,     5,
      92,     5,    94,    95,    85,    86,   140,   130,   130,    71,
      72,    92,   140,    94,    95,     5,   140,     5,     4,   130,
       5,     5,     5,    85,    86,     5,     5,   174,     5,     5,
      92,   178,    94,    95,   140,     5,   141,   130,   174,   186,
     140,   188,   178,   140,   168,   169,   170,   171,   172,   173,
     186,   140,   188,     5,     5,     5,   204,   181,     5,   183,
     184,   185,   168,   169,   170,   171,   172,   173,     5,   130,
     130,     5,   130,   204,     5,   181,     3,   183,   184,   185,
       5,     5,   174,     5,     5,     5,   178,     5,   204,     5,
       5,   140,   259,   174,   186,   130,   188,   178,   131,   130,
     130,   140,   131,    94,   192,   186,   230,   188,     5,   130,
       5,     5,   174,   162,   163,     5,   178,   140,     5,   168,
     169,   170,   171,   172,   186,   130,   188,     5,     5,     5,
     131,   130,   181,   182,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    72,    73,
      74,    75,    76,    77,    78,    79,    72,    73,    74,    75,
      76,    77,    78,    79,    72,    73,    74,    75,    76,    77,
      78,    79,    72,    73,    74,    75,    76,    77,    78,    79,
      72,    73,    74,    75,    76,    77,    78,    79,    72,    73,
      74,    75,    76,    77,    78,    79,    72,    73,    74,    75,
      76,    77,    78,    79,     5,     5,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,     5,   140,     5,   207,
     140,    55,   141,   141,     5,     5,     5,     5,   141,   141,
     141,     5,   141,     5,     5,   141,   141,   141,   141,    12,
     102,   328,   634,   804,    84,   462,   304,    75,    75,   767,
     804,   804,   804,   965,  1089,   961,  1080,    77,   581,   584,
     804,   544,     1,   587,   331,   451,   419,   396,   722,  1100,
     155,   426
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     8,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   272,   273,   274,   293,   294,   295,   297,   298,   299,
     300,   303,   304,   305,   306,   307,   308,   309,   315,   325,
     326,   331,   356,   357,   358,   359,   360,   361,   362,   363,
     364,     9,    11,    13,    14,    18,    19,    30,    51,    52,
      59,    61,    70,    85,    87,   178,   191,   197,   258,   438,
     138,   138,   138,   138,   138,   138,   138,   138,   138,     0,
     274,   275,   277,   279,   281,   283,   285,   287,   289,   291,
      12,   131,   140,   130,   327,   328,   332,    20,   265,   131,
     131,   265,   140,   131,   132,   265,    71,   179,   180,   189,
     190,   252,   310,   311,    87,   227,   265,   442,    70,    73,
     226,    73,    73,    73,    17,    73,    73,    17,    39,     3,
      71,    72,    86,    92,    94,    95,   174,   178,   186,   188,
     276,   365,   366,   367,   375,   378,   381,   419,   420,   421,
     422,   434,   437,   438,   439,   445,   446,   447,   448,   449,
     453,   493,   494,   495,     3,   228,   278,   365,   366,   367,
     419,   434,   437,   445,   446,   447,   448,   449,   469,   483,
     489,   490,   492,   493,   495,     3,   280,   365,   366,   367,
     434,   437,   445,   446,   447,   448,   449,   485,   486,   487,
     489,   493,   495,     3,   282,   365,   366,   367,   419,   434,
     437,   445,   446,   447,   448,   449,   469,   489,   493,   495,
       3,   284,   365,   366,   367,   375,   378,   384,   434,   437,
     445,   446,   447,   448,   449,     3,   286,   365,   366,   367,
     434,   437,   445,   446,   447,   448,   449,   496,   497,   498,
     499,   500,     3,   288,   365,   366,   367,   422,   434,   437,
     445,   446,   447,   448,   449,   456,   290,   365,   366,   367,
     419,   434,   437,   445,   446,   447,   448,   449,   469,   489,
     493,   495,     3,   292,   365,   366,   367,   434,   437,   445,
     446,   447,   448,   449,   452,    10,    71,   296,    76,   329,
      90,   328,   431,    15,    17,    28,    29,    30,    76,    88,
      89,   333,   334,   337,   338,   339,   340,   341,   342,   343,
     344,   348,   317,   301,   217,   218,   219,   220,   488,   133,
     135,   136,   137,   443,   444,   131,   140,   312,   311,   250,
     314,   265,   265,    40,    42,    43,    44,    45,    46,    47,
      84,    90,    93,   164,   167,   194,   196,   198,   201,   224,
     225,   229,   230,   231,   236,   238,   240,   241,   246,   247,
     248,   249,   440,   441,    57,   502,   131,   131,   130,   131,
     130,   131,   131,   131,   130,   131,   130,   131,   368,   370,
     130,   130,     7,   140,   162,   163,   168,   169,   170,   171,
     172,   181,   182,   202,   227,   230,   454,   455,   459,   462,
     464,   465,   466,   467,   368,   368,   132,   368,   140,   255,
     255,   175,   176,   177,    71,   179,   180,   139,   138,   450,
     451,   227,   265,   442,     7,   201,   202,   225,   227,   246,
     491,   227,   246,   491,     7,   202,   221,   222,   202,     7,
       7,    47,    48,    49,    50,   202,   173,   181,   183,   184,
     185,   457,   458,   460,   461,   462,   463,   466,   164,   202,
     130,    26,   140,    30,    35,   199,   200,   209,   210,   211,
     212,   213,   214,   215,   216,   316,   321,   323,   324,   330,
     372,   373,   140,    75,   374,    22,    23,    25,   130,   131,
     268,   130,    30,    89,    30,    89,    28,    29,   140,   131,
      28,    29,   335,   335,    31,    33,    34,    36,    37,   166,
     266,   318,    60,    62,    63,    64,    65,    66,    67,    68,
      69,   266,   302,   253,   253,   266,   444,   190,    90,   313,
     316,   321,   323,   324,   314,   251,   443,   440,   266,   441,
     140,    90,   194,   196,   369,   370,   371,   430,    74,    88,
     194,   195,   196,   245,   387,   389,    92,   202,   259,   260,
     261,   262,   263,   264,   470,   470,   470,   470,   470,   470,
     247,   248,   239,   470,   140,   455,   478,   479,   480,   470,
      90,   369,   428,    90,   369,   427,    90,   369,   429,    55,
     451,   265,   440,   502,    23,    24,   224,   484,   470,   201,
     224,   225,   484,   470,   263,   264,   436,   226,   436,   226,
     249,   223,   470,   223,   470,   233,   234,   235,   236,    40,
     470,   470,   470,    48,    49,    40,   470,   458,   480,   470,
     470,   164,   140,   329,   265,    93,   130,   132,   130,   130,
     204,   130,   131,   131,   131,   267,   349,   130,    27,    31,
      32,   336,   345,   346,   347,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     140,   140,   266,   266,   442,    55,   140,   130,   140,   130,
     140,   371,   430,   130,   131,   130,   140,   130,   140,   130,
     140,   252,    76,   388,   382,   140,   140,   140,   140,   152,
     468,   468,   468,   468,   480,   480,   480,   140,    55,   140,
       5,   468,   140,   428,   140,   427,   140,   429,   440,   266,
     140,    93,   140,   480,   480,   480,    93,   140,   130,   131,
     130,   131,   130,   131,   130,   131,   480,   470,   140,   468,
     470,   468,   385,   385,   385,    79,   501,   480,   140,   140,
     140,   470,   470,   480,   468,     5,   468,   140,   480,   317,
      23,    24,   263,   322,   350,   351,   352,   130,   130,   353,
     354,    21,   355,   131,   131,   131,    15,    16,    28,    29,
     131,   131,   323,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   204,   442,   502,   204,   480,   480,   480,   480,
     480,   480,   379,   140,   376,    53,    54,    79,    83,    90,
      91,   383,   391,   395,   396,   432,   433,   480,    55,   141,
     488,   141,   488,   141,   141,     5,     5,     5,   204,   205,
     206,   207,   208,   471,    55,    71,    72,    85,    92,   231,
     232,   475,   476,   204,   204,   204,   266,   442,   480,    54,
     480,   471,     5,     5,     5,   480,   488,   480,   480,   480,
     480,     5,   140,   468,   480,   141,   468,   141,   488,    17,
      56,    90,   225,   386,   423,   424,   425,   426,   480,   480,
     480,   237,   385,     5,   141,    41,   488,    41,   488,   140,
     140,     5,   141,   488,   476,   141,   480,     5,   266,   322,
     322,   130,   353,   353,   353,   355,   354,   488,   488,   488,
     488,   203,   204,   203,   204,   203,   204,   203,   204,   203,
     204,   502,     5,     5,     5,     5,     5,     5,    35,   246,
     316,   319,   321,   380,   432,   433,   435,   480,    17,    77,
      78,   316,   319,   321,   377,   390,   391,   394,   395,   396,
     432,   433,   435,   480,   130,   130,    80,    81,    82,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   140,   140,     5,     5,   476,   476,   476,
     480,   368,     4,   482,   442,   502,     5,   130,     5,   480,
     476,   476,   476,     5,   480,     5,     5,     5,     5,   476,
     480,   141,     5,   480,   141,   488,   480,   480,   130,   140,
     140,   140,     5,     5,     5,   480,   476,   480,   204,   473,
     473,   473,   473,    41,   488,    41,   488,   476,   482,     5,
     476,   130,   130,   476,   476,   476,   476,   476,   476,    38,
     436,     5,   130,     5,   392,   407,   407,    73,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   372,   373,
     417,   418,   399,   399,   401,    74,   165,   166,   187,   397,
     398,   405,   415,   204,   476,    90,   476,   482,     5,    58,
     369,   474,     3,   502,   476,   480,   476,     5,   482,   476,
       5,   476,   476,   476,   476,     5,   480,   476,     5,   480,
     480,     5,     5,   204,   476,   476,   476,     5,   482,     5,
     480,   480,   480,   480,   140,   205,   206,   207,   472,   140,
     472,   140,   472,   140,   472,   482,   476,   482,   482,   482,
     482,   482,   482,   259,   320,   130,   476,   476,   323,   324,
     393,    93,   164,   187,   193,   269,   372,   373,   408,   409,
     410,   411,   412,   131,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   418,   372,   373,   400,   372,   373,
     402,   130,   130,   140,   131,   398,   254,   257,   403,   404,
     406,   192,   414,   416,   482,   476,    94,   474,   242,   243,
     244,   482,     5,   482,   476,   476,   476,     5,   482,   476,
       5,     5,   476,   476,   482,   482,   482,   476,   476,     5,
       5,     5,     5,   472,   480,   472,   480,   472,   480,   472,
     480,   482,   140,   482,   482,   130,   470,   131,   130,   413,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     130,   132,   140,   130,   482,    55,   140,   478,   479,   481,
     481,   481,   476,   482,   482,   482,   476,   482,   476,   476,
     482,   482,   482,   482,   476,   476,   476,   476,   480,     5,
     480,     5,   480,     5,   480,     5,   207,   140,   256,   270,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
      55,     5,     5,     5,   482,   482,   482,   482,   482,   482,
     482,   482,     5,   476,     5,   476,     5,   476,     5,   476,
     475,   477,   477,   477,   476,   482,   476,   482,   476,   482,
     476,   482,   482,   482,   482,   482
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   271,   272,   272,   273,   273,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   275,   275,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   277,   277,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   279,   279,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   281,   281,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   283,   283,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   287,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   289,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   291,   291,   292,   292,   292,   292,
     292,   292,   292,   292,   292,   292,   292,   293,   293,   293,
     294,   295,   296,   296,   297,   298,   298,   298,   299,   300,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   303,   304,   304,   304,
     305,   305,   305,   306,   307,   308,   309,   310,   310,   311,
     312,   312,   313,   313,   313,   313,   313,   314,   314,   315,
     316,   316,   317,   317,   318,   318,   318,   318,   318,   318,
     318,   318,   319,   320,   320,   321,   321,   321,   322,   322,
     323,   323,   323,   323,   323,   323,   323,   324,   325,   326,
     327,   327,   328,   328,   329,   329,   330,   330,   330,   330,
     330,   330,   331,   332,   332,   333,   333,   333,   333,   333,
     333,   334,   334,   335,   335,   336,   336,   336,   337,   337,
     338,   338,   339,   340,   341,   341,   342,   342,   343,   343,
     344,   345,   346,   347,   348,   348,   348,   348,   348,   348,
     349,   348,   350,   348,   351,   348,   352,   348,   348,   353,
     353,   354,   355,   355,   356,   356,   356,   356,   357,   358,
     358,   359,   360,   361,   361,   362,   363,   364,   364,   365,
     365,   366,   366,   367,   367,   368,   368,   369,   369,   370,
     370,   371,   371,   371,   371,   372,   372,   373,   374,   374,
     375,   376,   376,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   378,   379,   379,   380,   380,   380,
     380,   380,   380,   381,   382,   382,   383,   383,   383,   383,
     383,   384,   384,   384,   384,   385,   385,   386,   386,   386,
     386,   387,   387,   388,   389,   390,   390,   391,   391,   391,
     392,   392,   393,   393,   394,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   396,
     396,   397,   397,   398,   398,   398,   398,   399,   399,   400,
     400,   401,   401,   402,   402,   403,   403,   404,   405,   405,
     406,   406,   407,   407,   408,   408,   408,   408,   408,   408,
     408,   409,   410,   411,   412,   413,   413,   414,   415,   415,
     416,   417,   417,   418,   418,   418,   418,   418,   418,   418,
     418,   418,   418,   418,   418,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   427,   428,   428,   429,   429,
     430,   430,   431,   431,   432,   433,   434,   434,   435,   436,
     436,   437,   437,   437,   437,   438,   439,   440,   440,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   442,   442,
     443,   443,   444,   444,   444,   444,   445,   445,   445,   446,
     446,   446,   447,   447,   447,   448,   449,   450,   450,   451,
     452,   452,   453,   454,   454,   455,   455,   455,   455,   455,
     456,   457,   457,   458,   458,   458,   458,   459,   459,   460,
     461,   461,   461,   461,   462,   462,   462,   462,   463,   463,
     464,   465,   466,   467,   467,   467,   468,   468,   469,   469,
     470,   470,   470,   470,   470,   470,   470,   470,   471,   471,
     471,   471,   471,   471,   472,   472,   472,   473,   473,   474,
     474,   474,   475,   475,   475,   475,   475,   475,   475,   476,
     477,   478,   479,   480,   480,   480,   481,   481,   481,   482,
     482,   482,   482,   483,   483,   483,   484,   484,   484,   485,
     485,   485,   485,   486,   486,   486,   486,   487,   488,   488,
     488,   488,   488,   489,   489,   490,   490,   490,   490,   490,
     490,   490,   490,   491,   491,   492,   492,   493,   493,   494,
     494,   495,   495,   496,   497,   498,   499,   499,   499,   499,
     499,   499,   500,   500,   500,   500,   500,   500,   501,   502,
     502,   502
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     7,     8,
       4,     3,     0,     3,     2,     3,     3,     3,     4,     5,
       0,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     2,     3,     3,     5,
       4,     6,     4,     3,     3,     3,     3,     2,     3,     2,
       0,     2,     3,     1,     1,     1,     1,     0,     2,     5,
       1,     4,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     0,     1,     4,     5,     5,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     5,     5,
       1,     2,     2,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     0,     2,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     5,     4,     2,     3,     3,     3,
       0,     4,     0,     5,     0,     5,     0,     5,     2,     1,
       2,     1,     0,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     4,     5,     6,     3,
       4,     3,     4,     3,     4,     1,     2,     1,     2,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     0,     2,
       9,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     9,     0,     2,     1,     1,     1,
       1,     1,     1,     8,     0,     2,     1,     1,     1,     1,
       1,     9,     8,     8,     8,     0,     2,     1,     1,     1,
       1,     0,     2,     2,     2,     1,     1,     2,     3,     2,
       0,     2,     1,     1,     2,     3,     2,     2,     2,     2,
       3,     3,     2,     2,     2,     2,     2,     2,     3,     3,
       2,     2,     2,     2,     2,     2,     3,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     2,     3,     2,
       2,     1,     2,     2,     2,     2,     2,     0,     2,     1,
       1,     0,     2,     1,     1,     2,     2,     2,     0,     2,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     2,     2,     0,     2,     2,     0,     2,
       1,     1,     2,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     7,     6,     6,     9,
       2,     2,     3,     2,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     3,     2,     7,     7,     3,     1,
       1,     3,     6,     7,     1,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     2,     2,     2,     1,     1,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     1,
       8,     6,     6,     1,     2,     1,     1,     1,     1,     1,
       6,     1,     2,     1,     1,     1,     1,     4,     4,     4,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       3,     3,     3,     1,     1,     1,     1,     1,     9,     6,
       0,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       3,     4,     1,     3,     4,     1,     1,     1,     1,     1,
       1,     2,     3,     0,     1,     1,     0,     1,     1,     0,
       6,     6,     6,     8,    10,     7,     0,     1,     1,     8,
       9,     9,    10,     9,     9,    10,    10,     6,     0,     1,
       1,     1,     1,     8,     7,     7,     7,     4,     4,     7,
       7,     4,     4,     0,     1,     9,     6,     8,     8,     8,
       8,     8,     8,     7,     7,     9,    10,    11,    12,    10,
      11,    12,    10,    11,    12,    10,    11,    12,     2,     0,
       2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 187:
#line 583 "src/p.y" /* yacc.c:1646  */
    {
                   mailset.events = Event_All;
                    addmail((yyvsp[-2].string), &mailset, &Run.maillist);
                  }
#line 3128 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 587 "src/p.y" /* yacc.c:1646  */
    {
                    addmail((yyvsp[-5].string), &mailset, &Run.maillist);
                  }
#line 3136 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 590 "src/p.y" /* yacc.c:1646  */
    {
                   mailset.events = ~mailset.events;
                   addmail((yyvsp[-6].string), &mailset, &Run.maillist);
                  }
#line 3145 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 596 "src/p.y" /* yacc.c:1646  */
    {
                    if (! (Run.flags & Run_Daemon) || ihp.daemon) {
                      ihp.daemon     = true;
                      Run.flags      |= Run_Daemon;
                      Run.polltime   = (yyvsp[-1].number);
                      Run.startdelay = (yyvsp[0].number);
                    }
                  }
#line 3158 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 606 "src/p.y" /* yacc.c:1646  */
    {
                        Run.flags |= Run_Batch;
                  }
#line 3166 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 611 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = START_DELAY; }
#line 3172 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 612 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[0].number); }
#line 3178 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 615 "src/p.y" /* yacc.c:1646  */
    {
                        Run.flags |= Run_Foreground;
                  }
#line 3186 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 620 "src/p.y" /* yacc.c:1646  */
    {
                        Run.onreboot = Onreboot_Start;
                  }
#line 3194 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 623 "src/p.y" /* yacc.c:1646  */
    {
                        Run.onreboot = Onreboot_Nostart;
                  }
#line 3202 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 626 "src/p.y" /* yacc.c:1646  */
    {
                        Run.onreboot = Onreboot_Laststate;
                  }
#line 3210 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 631 "src/p.y" /* yacc.c:1646  */
    {
                        // Note: deprecated (replaced by "set limits" statement's "sendExpectBuffer" option)
                        Run.limits.sendExpectBuffer = (yyvsp[-1].number) * (yyvsp[0].number);
                  }
#line 3219 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 644 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.sendExpectBuffer = (yyvsp[-1].number) * (yyvsp[0].number);
                  }
#line 3227 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 647 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.fileContentBuffer = (yyvsp[-1].number) * (yyvsp[0].number);
                  }
#line 3235 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 650 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.httpContentBuffer = (yyvsp[-1].number) * (yyvsp[0].number);
                  }
#line 3243 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 653 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.programOutput = (yyvsp[-1].number) * (yyvsp[0].number);
                  }
#line 3251 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 656 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.networkTimeout = (yyvsp[-1].number);
                  }
#line 3259 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 659 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.networkTimeout = (yyvsp[-1].number) * 1000;
                  }
#line 3267 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 662 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.programTimeout = (yyvsp[-1].number);
                  }
#line 3275 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 665 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.programTimeout = (yyvsp[-1].number) * 1000;
                  }
#line 3283 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 668 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.stopTimeout = (yyvsp[-1].number);
                  }
#line 3291 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 671 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.stopTimeout = (yyvsp[-1].number) * 1000;
                  }
#line 3299 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 674 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.startTimeout = (yyvsp[-1].number);
                  }
#line 3307 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 677 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.startTimeout = (yyvsp[-1].number) * 1000;
                  }
#line 3315 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 680 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.restartTimeout = (yyvsp[-1].number);
                  }
#line 3323 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 683 "src/p.y" /* yacc.c:1646  */
    {
                        Run.limits.restartTimeout = (yyvsp[-1].number) * 1000;
                  }
#line 3331 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 688 "src/p.y" /* yacc.c:1646  */
    {
                        Run.flags |= Run_FipsEnabled;
                  }
#line 3339 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 693 "src/p.y" /* yacc.c:1646  */
    {
                   if (! Run.files.log || ihp.logfile) {
                     ihp.logfile = true;
                     setlogfile((yyvsp[0].string));
                     Run.flags &= ~Run_UseSyslog;
                     Run.flags |= Run_Log;
                   }
                  }
#line 3352 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 701 "src/p.y" /* yacc.c:1646  */
    {
                    setsyslog(NULL);
                  }
#line 3360 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 704 "src/p.y" /* yacc.c:1646  */
    {
                    setsyslog((yyvsp[0].string)); FREE((yyvsp[0].string));
                  }
#line 3368 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 709 "src/p.y" /* yacc.c:1646  */
    {
                    Run.eventlist_dir = (yyvsp[0].string);
                  }
#line 3376 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 712 "src/p.y" /* yacc.c:1646  */
    {
                    Run.eventlist_dir = (yyvsp[-2].string);
                    Run.eventlist_slots = (yyvsp[0].number);
                  }
#line 3385 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 716 "src/p.y" /* yacc.c:1646  */
    {
                    Run.eventlist_dir = Str_dup(MYEVENTLISTBASE);
                    Run.eventlist_slots = (yyvsp[0].number);
                  }
#line 3394 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 722 "src/p.y" /* yacc.c:1646  */
    {
                    Run.files.id = (yyvsp[0].string);
                  }
#line 3402 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 727 "src/p.y" /* yacc.c:1646  */
    {
                    Run.files.state = (yyvsp[0].string);
                  }
#line 3410 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 732 "src/p.y" /* yacc.c:1646  */
    {
                   if (! Run.files.pid || ihp.pidfile) {
                     ihp.pidfile = true;
                     setpidfile((yyvsp[0].string));
                   }
                 }
#line 3421 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 747 "src/p.y" /* yacc.c:1646  */
    {
                        mmonitset.url = (yyvsp[-1].url);
                        addmmonit(&mmonitset);
                  }
#line 3430 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 757 "src/p.y" /* yacc.c:1646  */
    {
                        mmonitset.timeout = (yyvsp[-1].number) * 1000; // net timeout is in milliseconds internally
                  }
#line 3438 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 767 "src/p.y" /* yacc.c:1646  */
    {
                    Run.flags &= ~Run_MmonitCredentials;
                  }
#line 3446 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 772 "src/p.y" /* yacc.c:1646  */
    {
                        Run.ssl.flags = SSL_Enabled;
                        Run.ssl.verify = sslset.verify;
                        Run.ssl.allowSelfSigned = sslset.allowSelfSigned;
                        Run.ssl.version = sslset.version;
                        Run.ssl.minimumValidDays = sslset.minimumValidDays;
                        Run.ssl.checksumType = sslset.checksumType;
                        Run.ssl.checksum = sslset.checksum;
                        Run.ssl.clientpemfile = sslset.clientpemfile;
                        Run.ssl.CACertificateFile = sslset.CACertificateFile;
                        Run.ssl.CACertificatePath = sslset.CACertificatePath;
                        if (Run.ssl.allowSelfSigned == true)
                                Run.httpd.flags |= Httpd_AllowSelfSignedCertificates;
                        reset_sslset();
                  }
#line 3466 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 789 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                  }
#line 3474 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 799 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.verify = true;
                  }
#line 3483 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 803 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.verify = false;
                  }
#line 3492 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 807 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.allowSelfSigned = true;
                  }
#line 3501 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 811 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.allowSelfSigned = false;
                  }
#line 3510 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 815 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                  }
#line 3518 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 818 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.clientpemfile = (yyvsp[0].string);
                        if (! File_exist(sslset.clientpemfile))
                                yyerror2("SSL client PEM file doesn't exist");
                        else if (! File_isFile(sslset.clientpemfile))
                                yyerror2("SSL client PEM file is not a file");
                        else if (! File_isReadable(sslset.clientpemfile))
                                yyerror2("Cannot read SSL client PEM file");
                  }
#line 3533 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 828 "src/p.y" /* yacc.c:1646  */
    {
                        if (sslset.CACertificateFile)
                                yyerror2("Duplicate SSL CA certificates file doesn't exist");
                        sslset.flags = SSL_Enabled;
                        sslset.CACertificateFile = (yyvsp[0].string);
                        if (! File_exist(sslset.CACertificateFile))
                                yyerror2("SSL CA certificates file doesn't exist");
                        else if (! File_isFile(sslset.CACertificateFile))
                                yyerror2("SSL CA certificates file is not a file");
                        else if (! File_isReadable(sslset.CACertificateFile))
                                yyerror2("Cannot read CA certificates file");
                  }
#line 3550 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 840 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.CACertificatePath = (yyvsp[0].string);
                        if (! File_exist(sslset.CACertificatePath))
                                yyerror2("SSL CA certificates directory doesn't exist");
                        else if (! File_isDirectory(sslset.CACertificatePath))
                                yyerror2("SSL CA certificates path is not directory");
                        else if (! File_isReadable(sslset.CACertificatePath))
                                yyerror2("Cannot read CA certificates directory");
                  }
#line 3565 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 852 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.minimumValidDays = (yyvsp[-1].number);
                  }
#line 3574 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 862 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.checksum = (yyvsp[0].string);
                        switch (cleanup_hash_string(sslset.checksum)) {
                                case 32:
                                        sslset.checksumType = Hash_Md5;
                                        break;
                                case 40:
                                        sslset.checksumType = Hash_Sha1;
                                        break;
                                default:
                                        yyerror2("Unknown checksum type: [%s] is not MD5 nor SHA1", sslset.checksum);
                        }
                  }
#line 3593 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 876 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.checksum = (yyvsp[0].string);
                        if (cleanup_hash_string(sslset.checksum) != 32)
                                yyerror2("Unknown checksum type: [%s] is not MD5", sslset.checksum);
                        sslset.checksumType = Hash_Md5;
                  }
#line 3605 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 883 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.checksum = (yyvsp[0].string);
                        if (cleanup_hash_string(sslset.checksum) != 40)
                                yyerror2("Unknown checksum type: [%s] is not SHA1", sslset.checksum);
                        sslset.checksumType = Hash_Sha1;
                  }
#line 3617 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 260:
#line 896 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.version = SSL_V2;
                  }
#line 3626 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 261:
#line 900 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.version = SSL_V3;
                  }
#line 3635 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 262:
#line 904 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.version = SSL_TLSV1;
                  }
#line 3644 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 909 "src/p.y" /* yacc.c:1646  */
    {
#ifndef HAVE_TLSV1_1
                        yyerror("Your SSL Library does not support TLS version 1.1");
#endif
                        sslset.flags = SSL_Enabled;
                        sslset.version = SSL_TLSV11;
                }
#line 3656 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 264:
#line 917 "src/p.y" /* yacc.c:1646  */
    {
#ifndef HAVE_TLSV1_2
                        yyerror("Your SSL Library does not support TLS version 1.2");
#endif
                        sslset.flags = SSL_Enabled;
                        sslset.version = SSL_TLSV12;
                }
#line 3668 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 265:
#line 924 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.version = SSL_Auto;
                  }
#line 3677 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 928 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        sslset.version = SSL_Auto;
                  }
#line 3686 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 934 "src/p.y" /* yacc.c:1646  */
    { // Backward compatibility
                        sslset.flags = SSL_Enabled;
                        sslset.checksum = (yyvsp[0].string);
                        if (cleanup_hash_string(sslset.checksum) != 32)
                                yyerror2("Unknown checksum type: [%s] is not MD5", sslset.checksum);
                        sslset.checksumType = Hash_Md5;
                  }
#line 3698 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 943 "src/p.y" /* yacc.c:1646  */
    {
                   if (((yyvsp[-1].number)) > SMTP_TIMEOUT)
                        Run.mailserver_timeout = (yyvsp[-1].number);
                   Run.mail_hostname = (yyvsp[0].string);
                  }
#line 3708 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 950 "src/p.y" /* yacc.c:1646  */
    {
                   if (mailset.from) {
                        Run.MailFormat.from = mailset.from;
                   } else {
                        Run.MailFormat.from = Address_new();
                        Run.MailFormat.from->address = Str_dup(ALERT_FROM);
                   }
                   if (mailset.replyto)
                        Run.MailFormat.replyto = mailset.replyto;
                   Run.MailFormat.subject = mailset.subject ?  mailset.subject : Str_dup(ALERT_SUBJECT);
                   Run.MailFormat.message = mailset.message ?  mailset.message : Str_dup(ALERT_MESSAGE);
                   reset_mailset();
                 }
#line 3726 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 969 "src/p.y" /* yacc.c:1646  */
    {
                        /* Restore the current text overriden by lookahead */
                        FREE(argyytext);
                        argyytext = Str_dup((yyvsp[-1].string));

                        mailserverset.host = (yyvsp[-1].string);
                        mailserverset.port = PORT_SMTP;
                        addmailserver(&mailserverset);
                  }
#line 3740 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 978 "src/p.y" /* yacc.c:1646  */
    {
                        /* Restore the current text overriden by lookahead */
                        FREE(argyytext);
                        argyytext = Str_dup((yyvsp[-3].string));

                        mailserverset.host = (yyvsp[-3].string);
                        mailserverset.port = (yyvsp[-1].number);
                        addmailserver(&mailserverset);
                  }
#line 3754 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 993 "src/p.y" /* yacc.c:1646  */
    {
                        mailserverset.username = (yyvsp[0].string);
                  }
#line 3762 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 996 "src/p.y" /* yacc.c:1646  */
    {
                        mailserverset.password = (yyvsp[0].string);
                  }
#line 3770 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1020 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags &= ~Httpd_Ssl;
                  }
#line 3778 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1023 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_Ssl;
#ifdef HAVE_OPENSSL
                        if (! Run.httpd.socket.net.ssl.pem)
                                yyerror("SSL server PEM file is required (pemfile option)");
                        else if (! file_checkStat(Run.httpd.socket.net.ssl.pem, "SSL server PEM file", S_IRWXU))
                                yyerror("SSL server PEM file permissions check failed");
#else
                        yyerror("SSL is not supported");
#endif
                  }
#line 3794 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1053 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_Net;
                        Run.httpd.socket.net.port = (yyvsp[0].number);
                  }
#line 3803 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1059 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_Unix;
                        Run.httpd.socket.unix.path = (yyvsp[0].string);
                  }
#line 3812 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1065 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_Signature;
                  }
#line 3820 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1068 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags &= ~Httpd_Signature;
                  }
#line 3828 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1081 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.socket.net.address = (yyvsp[0].string);
                  }
#line 3836 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1086 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.socket.net.ssl.pem = (yyvsp[0].string);
                  }
#line 3844 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1091 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.socket.net.ssl.clientpem = (yyvsp[0].string);
                        if (! file_checkStat(Run.httpd.socket.net.ssl.clientpem, "SSL client PEM file", S_IRWXU | S_IRGRP | S_IROTH))
                                yyerror2("SSL client PEM file has too loose permissions");
                  }
#line 3854 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1098 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_AllowSelfSignedCertificates;
                  }
#line 3862 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1103 "src/p.y" /* yacc.c:1646  */
    {
                        addcredentials((yyvsp[-3].string), (yyvsp[-1].string), Digest_Cleartext, (yyvsp[0].number));
                  }
#line 3870 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1106 "src/p.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBPAM
                        addpamauth((yyvsp[-1].string), (yyvsp[0].number));
#else
                        yyerror("PAM is not supported");
                        FREE((yyvsp[-1].string));
#endif
                  }
#line 3883 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1114 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry((yyvsp[0].string), NULL, Digest_Cleartext);
                        FREE((yyvsp[0].string));
                  }
#line 3892 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1118 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry((yyvsp[0].string), NULL, Digest_Cleartext);
                        FREE((yyvsp[0].string));
                  }
#line 3901 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1122 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry((yyvsp[0].string), NULL, Digest_Md5);
                        FREE((yyvsp[0].string));
                  }
#line 3910 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1126 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry((yyvsp[0].string), NULL, Digest_Crypt);
                        FREE((yyvsp[0].string));
                  }
#line 3919 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1130 "src/p.y" /* yacc.c:1646  */
    {
                        htpasswd_file = (yyvsp[0].string);
                        digesttype = Digest_Cleartext;
                  }
#line 3928 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1134 "src/p.y" /* yacc.c:1646  */
    {
                        FREE(htpasswd_file);
                  }
#line 3936 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1137 "src/p.y" /* yacc.c:1646  */
    {
                        htpasswd_file = (yyvsp[0].string);
                        digesttype = Digest_Cleartext;
                  }
#line 3945 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1141 "src/p.y" /* yacc.c:1646  */
    {
                        FREE(htpasswd_file);
                  }
#line 3953 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1144 "src/p.y" /* yacc.c:1646  */
    {
                        htpasswd_file = (yyvsp[0].string);
                        digesttype = Digest_Md5;
                  }
#line 3962 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1148 "src/p.y" /* yacc.c:1646  */
    {
                        FREE(htpasswd_file);
                  }
#line 3970 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1151 "src/p.y" /* yacc.c:1646  */
    {
                        htpasswd_file = (yyvsp[0].string);
                        digesttype = Digest_Crypt;
                  }
#line 3979 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1155 "src/p.y" /* yacc.c:1646  */
    {
                        FREE(htpasswd_file);
                  }
#line 3987 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1158 "src/p.y" /* yacc.c:1646  */
    {
                        if (! Engine_addAllow((yyvsp[0].string)))
                                yywarning2("invalid allow option", (yyvsp[0].string));
                        FREE((yyvsp[0].string));
                  }
#line 3997 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1169 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry(htpasswd_file, (yyvsp[0].string), digesttype);
                        FREE((yyvsp[0].string));
                  }
#line 4006 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1175 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = false; }
#line 4012 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1176 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = true; }
#line 4018 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1179 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Process, (yyvsp[-2].string), (yyvsp[0].string), check_process);
                  }
#line 4026 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1182 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Process, (yyvsp[-2].string), (yyvsp[0].string), check_process);
                  }
#line 4034 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1185 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Process, (yyvsp[-2].string), (yyvsp[0].string), check_process);
                    matchset.ignore = false;
                    matchset.match_path = NULL;
                    matchset.match_string = Str_dup((yyvsp[0].string));
                    addmatch(&matchset, Action_Ignored, 0);
                  }
#line 4046 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1192 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Process, (yyvsp[-2].string), (yyvsp[0].string), check_process);
                    matchset.ignore = false;
                    matchset.match_path = NULL;
                    matchset.match_string = Str_dup((yyvsp[0].string));
                    addmatch(&matchset, Action_Ignored, 0);
                  }
#line 4058 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1201 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_File, (yyvsp[-2].string), (yyvsp[0].string), check_file);
                  }
#line 4066 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1206 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Filesystem, (yyvsp[-2].string), (yyvsp[0].string), check_filesystem);
                  }
#line 4074 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1209 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Filesystem, (yyvsp[-2].string), (yyvsp[0].string), check_filesystem);
                  }
#line 4082 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1214 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Directory, (yyvsp[-2].string), (yyvsp[0].string), check_directory);
                  }
#line 4090 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1219 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Host, (yyvsp[-2].string), (yyvsp[0].string), check_remote_host);
                  }
#line 4098 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1224 "src/p.y" /* yacc.c:1646  */
    {
                    if (Link_isGetByAddressSupported()) {
                        createservice(Service_Net, (yyvsp[-2].string), (yyvsp[0].string), check_net);
                        current->inf->priv.net.stats = Link_createForAddress((yyvsp[0].string));
                    } else {
                        yyerror("Network monitoring by IP address is not supported on this platform, please use 'check network <foo> with interface <bar>' instead");
                    }
                  }
#line 4111 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1232 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Net, (yyvsp[-2].string), (yyvsp[0].string), check_net);
                    current->inf->priv.net.stats = Link_createForInterface((yyvsp[0].string));
                  }
#line 4120 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1238 "src/p.y" /* yacc.c:1646  */
    {
                        char *servicename = (yyvsp[0].string);
                        if (Str_sub(servicename, "$HOST")) {
                                char hostname[STRLEN];
                                if (gethostname(hostname, sizeof(hostname))) {
                                        LogError("System hostname error -- %s\n", STRERROR);
                                        cfg_errflag++;
                                } else {
                                        Util_replaceString(&servicename, "$HOST", hostname);
                                }
                        }
                        Run.system = createservice(Service_System, servicename, NULL, check_system); // The name given in the 'check system' statement overrides system hostname
                  }
#line 4138 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1253 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Fifo, (yyvsp[-2].string), (yyvsp[0].string), check_fifo);
                  }
#line 4146 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1258 "src/p.y" /* yacc.c:1646  */
    {
                        command_t c = command; // Current command
                        check_exec(c->arg[0]);
                        createservice(Service_Program, (yyvsp[-3].string), NULL, check_program);
                        current->program->timeout = (yyvsp[0].number);
                        current->program->output = StringBuffer_create(64);
                 }
#line 4158 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1265 "src/p.y" /* yacc.c:1646  */
    {
                        command_t c = command; // Current command
                        check_exec(c->arg[0]);
                        createservice(Service_Program, (yyvsp[-4].string), NULL, check_program);
                        current->program->timeout = (yyvsp[0].number);
                        current->program->output = StringBuffer_create(64);
                 }
#line 4170 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1274 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(START, (yyvsp[0].number));
                  }
#line 4178 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1277 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(START, (yyvsp[0].number));
                  }
#line 4186 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1282 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(STOP, (yyvsp[0].number));
                  }
#line 4194 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1285 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(STOP, (yyvsp[0].number));
                  }
#line 4202 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1291 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(RESTART, (yyvsp[0].number));
                  }
#line 4210 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1294 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(RESTART, (yyvsp[0].number));
                  }
#line 4218 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1307 "src/p.y" /* yacc.c:1646  */
    {
                        addargument((yyvsp[0].string));
                  }
#line 4226 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1310 "src/p.y" /* yacc.c:1646  */
    {
                        addargument((yyvsp[0].string));
                  }
#line 4234 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1315 "src/p.y" /* yacc.c:1646  */
    {
                        addeuid(get_uid((yyvsp[0].string), 0));
                        FREE((yyvsp[0].string));
                  }
#line 4243 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1319 "src/p.y" /* yacc.c:1646  */
    {
                        addegid(get_gid((yyvsp[0].string), 0));
                        FREE((yyvsp[0].string));
                  }
#line 4252 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1323 "src/p.y" /* yacc.c:1646  */
    {
                        addeuid(get_uid(NULL, (yyvsp[0].number)));
                  }
#line 4260 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1326 "src/p.y" /* yacc.c:1646  */
    {
                        addegid(get_gid(NULL, (yyvsp[0].number)));
                  }
#line 4268 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1331 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = (yyvsp[0].string);
                  }
#line 4276 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1334 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = (yyvsp[0].string);
                  }
#line 4284 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1339 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = (yyvsp[0].string);
                  }
#line 4292 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1344 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = NULL;
                  }
#line 4300 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 1347 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = (yyvsp[0].string);
                  }
#line 4308 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1352 "src/p.y" /* yacc.c:1646  */
    {
                    /* This is a workaround to support content match without having to create an URL object. 'urloption' creates the Request_T object we need minus the URL object, but with enough information to perform content test.
                     TODO: Parser is in need of refactoring */
                    portset.url_request = urlrequest;
                    addeventaction(&(portset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addport(&(current->portlist), &portset);
                  }
#line 4320 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1378 "src/p.y" /* yacc.c:1646  */
    {
                    prepare_urlrequest((yyvsp[-5].url));
                    addeventaction(&(portset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addport(&(current->portlist), &portset);
                  }
#line 4330 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1397 "src/p.y" /* yacc.c:1646  */
    {
                        addeventaction(&(portset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addport(&(current->socketlist), &portset);
                  }
#line 4339 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1414 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.family = Socket_Ip;
                        icmpset.type = (yyvsp[-5].number);
                        addeventaction(&(icmpset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addicmp(&icmpset);
                  }
#line 4350 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1420 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.family = Socket_Ip;
                        addeventaction(&(icmpset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addicmp(&icmpset);
                 }
#line 4360 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1425 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.family = Socket_Ip4;
                        addeventaction(&(icmpset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addicmp(&icmpset);
                 }
#line 4370 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1430 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.family = Socket_Ip6;
                        addeventaction(&(icmpset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addicmp(&icmpset);
                 }
#line 4380 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1447 "src/p.y" /* yacc.c:1646  */
    {
                        portset.hostname = Str_dup(current->type == Service_Host ? current->path : LOCALHOST);
                  }
#line 4388 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1450 "src/p.y" /* yacc.c:1646  */
    {
                        portset.hostname = (yyvsp[0].string);
                  }
#line 4396 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 1455 "src/p.y" /* yacc.c:1646  */
    {
                        portset.target.net.port = (yyvsp[0].number);
                  }
#line 4404 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 1460 "src/p.y" /* yacc.c:1646  */
    {
                        portset.family = Socket_Unix;
                        portset.target.unix.pathname = (yyvsp[0].string);
                  }
#line 4413 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1466 "src/p.y" /* yacc.c:1646  */
    {
                    portset.family = Socket_Ip4;
                  }
#line 4421 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1469 "src/p.y" /* yacc.c:1646  */
    {
                    portset.family = Socket_Ip6;
                  }
#line 4429 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1474 "src/p.y" /* yacc.c:1646  */
    {
                    portset.type = Socket_Tcp;
                  }
#line 4437 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 1477 "src/p.y" /* yacc.c:1646  */
    { // The typelist is kept for backward compatibility (replaced by ssloptionlist)
                    portset.type = Socket_Tcp;
                    sslset.flags = SSL_Enabled;
                  }
#line 4446 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 1481 "src/p.y" /* yacc.c:1646  */
    {
                    portset.type = Socket_Udp;
                  }
#line 4454 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 424:
#line 1494 "src/p.y" /* yacc.c:1646  */
    {
                        _parseOutgoingAddress((yyvsp[0].string), &(portset.outgoing));
                  }
#line 4462 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 425:
#line 1499 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_APACHESTATUS);
                  }
#line 4470 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 1502 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_DEFAULT);
                  }
#line 4478 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 1505 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_DNS);
                  }
#line 4486 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1508 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_DWP);
                  }
#line 4494 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 1511 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_FTP);
                  }
#line 4502 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 430:
#line 1514 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_HTTP);
                  }
#line 4510 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 431:
#line 1517 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        portset.type = Socket_Tcp;
                        portset.protocol = Protocol_get(Protocol_HTTP);
                 }
#line 4520 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 1522 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_IMAP);
                  }
#line 4528 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 1525 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        portset.type = Socket_Tcp;
                        portset.protocol = Protocol_get(Protocol_IMAP);
                  }
#line 4538 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 1530 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_CLAMAV);
                  }
#line 4546 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 1533 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_LDAP2);
                  }
#line 4554 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 1536 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_LDAP3);
                  }
#line 4562 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 437:
#line 1539 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_MONGODB);
                  }
#line 4570 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 438:
#line 1542 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_MYSQL);
                  }
#line 4578 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 1545 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_SIP);
                  }
#line 4586 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 1548 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_NNTP);
                  }
#line 4594 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 441:
#line 1551 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_NTP3);
                        portset.type = Socket_Udp;
                  }
#line 4603 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 442:
#line 1555 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_POSTFIXPOLICY);
                  }
#line 4611 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 443:
#line 1558 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_POP);
                  }
#line 4619 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 444:
#line 1561 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        portset.type = Socket_Tcp;
                        portset.protocol = Protocol_get(Protocol_POP);
                  }
#line 4629 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 445:
#line 1566 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_SIEVE);
                  }
#line 4637 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 446:
#line 1569 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_SMTP);
                  }
#line 4645 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 447:
#line 1572 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.flags = SSL_Enabled;
                        portset.type = Socket_Tcp;
                        portset.protocol = Protocol_get(Protocol_SMTP);
                 }
#line 4655 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 1577 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_SSH);
                  }
#line 4663 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 1580 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_RDATE);
                  }
#line 4671 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1583 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_REDIS);
                  }
#line 4679 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1586 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_RSYNC);
                  }
#line 4687 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 452:
#line 1589 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_TNS);
                  }
#line 4695 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 1592 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_PGSQL);
                  }
#line 4703 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 1595 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_LMTP);
                  }
#line 4711 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 455:
#line 1598 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_GPS);
                  }
#line 4719 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 456:
#line 1601 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_RADIUS);
                  }
#line 4727 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 1604 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_MEMCACHE);
                  }
#line 4735 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 458:
#line 1607 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_WEBSOCKET);
                  }
#line 4743 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 459:
#line 1612 "src/p.y" /* yacc.c:1646  */
    {
                        if (portset.protocol->check == check_default || portset.protocol->check == check_generic) {
                                portset.protocol = Protocol_get(Protocol_GENERIC);
                                addgeneric(&portset, (yyvsp[0].string), NULL);
                        } else {
                                yyerror("The SEND statement is not allowed in the %s protocol context", portset.protocol->name);
                        }
                  }
#line 4756 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1620 "src/p.y" /* yacc.c:1646  */
    {
                        if (portset.protocol->check == check_default || portset.protocol->check == check_generic) {
                                portset.protocol = Protocol_get(Protocol_GENERIC);
                                addgeneric(&portset, NULL, (yyvsp[0].string));
                        } else {
                                yyerror("The EXPECT statement is not allowed in the %s protocol context", portset.protocol->name);
                        }
                  }
#line 4769 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1634 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.websocket.origin = (yyvsp[0].string);
                  }
#line 4777 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1637 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.websocket.request = (yyvsp[0].string);
                  }
#line 4785 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 1640 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.websocket.host = (yyvsp[0].string);
                  }
#line 4793 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 1643 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.websocket.version = (yyvsp[0].number);
                  }
#line 4801 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 1652 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.smtp.username = (yyvsp[0].string);
                  }
#line 4809 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 1655 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.smtp.password = (yyvsp[0].string);
                  }
#line 4817 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 1664 "src/p.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[0].string)) {
                                if (strlen((yyvsp[0].string)) > 16)
                                        yyerror2("Username too long -- Maximum MySQL username length is 16 characters");
                                else
                                        portset.parameters.mysql.username = (yyvsp[0].string);
                        }
                  }
#line 4830 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 1672 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.mysql.password = (yyvsp[0].string);
                  }
#line 4838 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 1677 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.string) = (yyvsp[0].string);
                  }
#line 4846 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 1680 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.string) = (yyvsp[0].string);
                  }
#line 4854 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 1685 "src/p.y" /* yacc.c:1646  */
    {
                     (yyval.number) = verifyMaxForward((yyvsp[0].number));
                  }
#line 4862 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 1694 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.sip.target = (yyvsp[0].string);
                  }
#line 4870 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 1697 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.sip.maxforward = (yyvsp[0].number);
                  }
#line 4878 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 1706 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.http.username = (yyvsp[0].string);
                  }
#line 4886 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 1709 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.http.password = (yyvsp[0].string);
                  }
#line 4894 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 1719 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.http.operator = (yyvsp[-1].number);
                    portset.parameters.http.status = (yyvsp[0].number);
                  }
#line 4903 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 1725 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.http.request = Util_urlEncode((yyvsp[0].string), false);
                    FREE((yyvsp[0].string));
                  }
#line 4912 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 1731 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.http.checksum = (yyvsp[0].string);
                  }
#line 4920 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 1736 "src/p.y" /* yacc.c:1646  */
    {
                    addhttpheader(&portset, Str_cat("Host:%s", (yyvsp[0].string)));
                    FREE((yyvsp[0].string));
                  }
#line 4929 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 496:
#line 1743 "src/p.y" /* yacc.c:1646  */
    {
                        addhttpheader(&portset, (yyvsp[0].string));
                 }
#line 4937 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 497:
#line 1748 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.string) = (yyvsp[0].string);
                  }
#line 4945 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 1757 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.radius.secret = (yyvsp[0].string);
                  }
#line 4953 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 1766 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.username = (yyvsp[0].string);
                  }
#line 4961 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 504:
#line 1769 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.password = (yyvsp[0].string);
                  }
#line 4969 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 1772 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.path = (yyvsp[0].string);
                  }
#line 4977 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 1775 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.loglimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.loglimit = (yyvsp[-1].number);
                  }
#line 4986 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 1779 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.closelimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.closelimit = (yyvsp[-1].number);
                  }
#line 4995 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 1783 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.dnslimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.dnslimit = (yyvsp[-1].number);
                  }
#line 5004 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 1787 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.keepalivelimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.keepalivelimit = (yyvsp[-1].number);
                  }
#line 5013 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 510:
#line 1791 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.replylimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.replylimit = (yyvsp[-1].number);
                  }
#line 5022 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 511:
#line 1795 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.requestlimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.requestlimit = (yyvsp[-1].number);
                  }
#line 5031 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 512:
#line 1799 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.startlimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.startlimit = (yyvsp[-1].number);
                  }
#line 5040 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 513:
#line 1803 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.waitlimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.waitlimit = (yyvsp[-1].number);
                  }
#line 5049 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 514:
#line 1807 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.gracefullimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.gracefullimit = (yyvsp[-1].number);
                  }
#line 5058 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 515:
#line 1811 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.apachestatus.cleanuplimitOP = (yyvsp[-2].number);
                        portset.parameters.apachestatus.cleanuplimit = (yyvsp[-1].number);
                  }
#line 5067 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 1817 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(nonexistset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addnonexist(&nonexistset);
                  }
#line 5076 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 517:
#line 1824 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(pidset).action, (yyvsp[0].number), Action_Ignored);
                    addpid(&pidset);
                  }
#line 5085 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 518:
#line 1830 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(ppidset).action, (yyvsp[0].number), Action_Ignored);
                    addppid(&ppidset);
                  }
#line 5094 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 1836 "src/p.y" /* yacc.c:1646  */
    {
                    uptimeset.operator = (yyvsp[-6].number);
                    uptimeset.uptime = ((unsigned long long)(yyvsp[-5].number) * (yyvsp[-4].number));
                    addeventaction(&(uptimeset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    adduptime(&uptimeset);
                  }
#line 5105 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 1843 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.count = (yyvsp[0].number);
                 }
#line 5113 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 521:
#line 1848 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.size = (yyvsp[0].number);
                 }
#line 5121 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 522:
#line 1853 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.timeout = (yyvsp[-1].number) * 1000; // timeout is in milliseconds internally
                    }
#line 5129 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 523:
#line 1858 "src/p.y" /* yacc.c:1646  */
    {
                        _parseOutgoingAddress((yyvsp[0].string), &(icmpset.outgoing));
                  }
#line 5137 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 524:
#line 1863 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = Run.limits.stopTimeout;
                  }
#line 5145 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 525:
#line 1866 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[-1].number) * 1000; // milliseconds internally
                  }
#line 5153 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 1871 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = Run.limits.startTimeout;
                  }
#line 5161 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 527:
#line 1874 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[-1].number) * 1000; // milliseconds internally
                  }
#line 5169 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 528:
#line 1879 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = Run.limits.restartTimeout;
                  }
#line 5177 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 529:
#line 1882 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[-1].number) * 1000; // milliseconds internally
                  }
#line 5185 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 530:
#line 1887 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = Run.limits.programTimeout;
                  }
#line 5193 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 531:
#line 1890 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[-1].number) * 1000; // milliseconds internally
                  }
#line 5201 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 532:
#line 1895 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = Run.limits.networkTimeout;
                  }
#line 5209 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 533:
#line 1898 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[-1].number) * 1000; // net timeout is in milliseconds internally
                  }
#line 5217 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 534:
#line 1903 "src/p.y" /* yacc.c:1646  */
    {
                        portset.timeout = (yyvsp[-1].number) * 1000; // timeout is in milliseconds internally
                    }
#line 5225 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 535:
#line 1908 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[0].number);
                  }
#line 5233 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 536:
#line 1913 "src/p.y" /* yacc.c:1646  */
    {
                   actionrateset.count = (yyvsp[-5].number);
                   actionrateset.cycle = (yyvsp[-3].number);
                   addeventaction(&(actionrateset).action, (yyvsp[0].number), Action_Alert);
                   addactionrate(&actionrateset);
                 }
#line 5244 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 537:
#line 1919 "src/p.y" /* yacc.c:1646  */
    {
                   actionrateset.count = (yyvsp[-5].number);
                   actionrateset.cycle = (yyvsp[-3].number);
                   addeventaction(&(actionrateset).action, Action_Unmonitor, Action_Alert);
                   addactionrate(&actionrateset);
                 }
#line 5255 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 538:
#line 1927 "src/p.y" /* yacc.c:1646  */
    {
                    seturlrequest((yyvsp[-1].number), (yyvsp[0].string));
                    FREE((yyvsp[0].string));
                  }
#line 5264 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 539:
#line 1933 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Equal; }
#line 5270 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 540:
#line 1934 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_NotEqual; }
#line 5276 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 541:
#line 1937 "src/p.y" /* yacc.c:1646  */
    {
                   mailset.events = Event_All;
                   addmail((yyvsp[-2].string), &mailset, &current->maillist);
                  }
#line 5285 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 542:
#line 1941 "src/p.y" /* yacc.c:1646  */
    {
                   addmail((yyvsp[-5].string), &mailset, &current->maillist);
                  }
#line 5293 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 543:
#line 1944 "src/p.y" /* yacc.c:1646  */
    {
                   mailset.events = ~mailset.events;
                   addmail((yyvsp[-6].string), &mailset, &current->maillist);
                  }
#line 5302 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 544:
#line 1948 "src/p.y" /* yacc.c:1646  */
    {
                   addmail((yyvsp[0].string), &mailset, &current->maillist);
                  }
#line 5310 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 545:
#line 1953 "src/p.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 5316 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 546:
#line 1956 "src/p.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 5322 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 549:
#line 1963 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Action; }
#line 5328 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 550:
#line 1964 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_ByteIn; }
#line 5334 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 551:
#line 1965 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_ByteOut; }
#line 5340 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 552:
#line 1966 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Checksum; }
#line 5346 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 553:
#line 1967 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Connection; }
#line 5352 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 554:
#line 1968 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Content; }
#line 5358 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 555:
#line 1969 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Data; }
#line 5364 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 556:
#line 1970 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Exec; }
#line 5370 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 557:
#line 1971 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Fsflag; }
#line 5376 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 558:
#line 1972 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Gid; }
#line 5382 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 559:
#line 1973 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Icmp; }
#line 5388 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 560:
#line 1974 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Instance; }
#line 5394 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 561:
#line 1975 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Invalid; }
#line 5400 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 562:
#line 1976 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Link; }
#line 5406 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 563:
#line 1977 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Nonexist; }
#line 5412 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 564:
#line 1978 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_PacketIn; }
#line 5418 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 565:
#line 1979 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_PacketOut; }
#line 5424 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 566:
#line 1980 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Permission; }
#line 5430 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 567:
#line 1981 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Pid; }
#line 5436 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 568:
#line 1982 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_PPid; }
#line 5442 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 569:
#line 1983 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Resource; }
#line 5448 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 570:
#line 1984 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Saturation; }
#line 5454 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 571:
#line 1985 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Size; }
#line 5460 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 572:
#line 1986 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Speed; }
#line 5466 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 573:
#line 1987 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Status; }
#line 5472 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 574:
#line 1988 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Timeout; }
#line 5478 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 575:
#line 1989 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Timestamp; }
#line 5484 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 576:
#line 1990 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Uid; }
#line 5490 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 577:
#line 1991 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Uptime; }
#line 5496 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2002 "src/p.y" /* yacc.c:1646  */
    { mailset.from = (yyvsp[-1].address); }
#line 5502 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2003 "src/p.y" /* yacc.c:1646  */
    { mailset.replyto = (yyvsp[-1].address); }
#line 5508 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2004 "src/p.y" /* yacc.c:1646  */
    { mailset.subject = (yyvsp[0].string); }
#line 5514 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2005 "src/p.y" /* yacc.c:1646  */
    { mailset.message = (yyvsp[0].string); }
#line 5520 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2008 "src/p.y" /* yacc.c:1646  */
    {
                   current->every.type = Every_SkipCycles;
                   current->every.spec.cycle.counter = current->every.spec.cycle.number = (yyvsp[-1].number);
                 }
#line 5529 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2012 "src/p.y" /* yacc.c:1646  */
    {
                   current->every.type = Every_Cron;
                   current->every.spec.cron = (yyvsp[0].string);
                 }
#line 5538 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2016 "src/p.y" /* yacc.c:1646  */
    {
                   current->every.type = Every_NotInCron;
                   current->every.spec.cron = (yyvsp[0].string);
                 }
#line 5547 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2022 "src/p.y" /* yacc.c:1646  */
    {
                        current->mode = Monitor_Active;
                  }
#line 5555 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2025 "src/p.y" /* yacc.c:1646  */
    {
                        current->mode = Monitor_Passive;
                  }
#line 5563 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2028 "src/p.y" /* yacc.c:1646  */
    {
                        // Deprecated since monit 5.18
                        current->onreboot = Onreboot_Laststate;
                  }
#line 5572 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2034 "src/p.y" /* yacc.c:1646  */
    {
                        current->onreboot = Onreboot_Start;
                  }
#line 5580 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2037 "src/p.y" /* yacc.c:1646  */
    {
                        current->onreboot = Onreboot_Nostart;
                        current->monitor = Monitor_Not;
                  }
#line 5589 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2041 "src/p.y" /* yacc.c:1646  */
    {
                        current->onreboot = Onreboot_Laststate;
                  }
#line 5597 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2046 "src/p.y" /* yacc.c:1646  */
    {
                        addservicegroup((yyvsp[0].string));
                        FREE((yyvsp[0].string));
                  }
#line 5606 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2060 "src/p.y" /* yacc.c:1646  */
    { adddependant((yyvsp[0].string)); }
#line 5612 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2063 "src/p.y" /* yacc.c:1646  */
    {
                        statusset.initialized = true;
                        statusset.operator = (yyvsp[-5].number);
                        statusset.return_value = (yyvsp[-4].number);
                        addeventaction(&(statusset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addstatus(&statusset);
                   }
#line 5624 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2070 "src/p.y" /* yacc.c:1646  */
    {
                        statusset.initialized = false;
                        statusset.operator = Operator_Changed;
                        statusset.return_value = 0;
                        addeventaction(&(statusset).action, (yyvsp[0].number), Action_Ignored);
                        addstatus(&statusset);
                   }
#line 5636 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2079 "src/p.y" /* yacc.c:1646  */
    {
                     addeventaction(&(resourceset).action, (yyvsp[-1].number), (yyvsp[0].number));
                     addresource(&resourceset);
                   }
#line 5645 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2096 "src/p.y" /* yacc.c:1646  */
    {
                     addeventaction(&(resourceset).action, (yyvsp[-1].number), (yyvsp[0].number));
                     addresource(&resourceset);
                   }
#line 5654 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2112 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_CpuPercent;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real);
                  }
#line 5664 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2117 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_CpuPercentTotal;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real);
                  }
#line 5674 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2124 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = (yyvsp[-3].number);
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real);
                  }
#line 5684 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2131 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_CpuUser; }
#line 5690 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2132 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_CpuSystem; }
#line 5696 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2133 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_CpuWait; }
#line 5702 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2134 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_CpuPercent; }
#line 5708 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2137 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_MemoryKbyte;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real) * (yyvsp[0].number);
                  }
#line 5718 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2142 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_MemoryPercent;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real);
                  }
#line 5728 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2147 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_MemoryKbyteTotal;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real) * (yyvsp[0].number);
                  }
#line 5738 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2152 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_MemoryPercentTotal;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real);
                  }
#line 5748 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2159 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_SwapKbyte;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real) * (yyvsp[0].number);
                  }
#line 5758 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2164 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_SwapPercent;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (yyvsp[-1].real);
                  }
#line 5768 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2171 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_Threads;
                    resourceset.operator = (yyvsp[-1].number);
                    resourceset.limit = (yyvsp[0].number);
                  }
#line 5778 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2178 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_Children;
                    resourceset.operator = (yyvsp[-1].number);
                    resourceset.limit = (yyvsp[0].number);
                  }
#line 5788 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2185 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = (yyvsp[-2].number);
                    resourceset.operator = (yyvsp[-1].number);
                    resourceset.limit = (yyvsp[0].real);
                  }
#line 5798 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2192 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_LoadAverage1m; }
#line 5804 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2193 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_LoadAverage5m; }
#line 5810 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2194 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_LoadAverage15m; }
#line 5816 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2197 "src/p.y" /* yacc.c:1646  */
    { (yyval.real) = (yyvsp[0].real); }
#line 5822 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2198 "src/p.y" /* yacc.c:1646  */
    { (yyval.real) = (float) (yyvsp[0].number); }
#line 5828 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2201 "src/p.y" /* yacc.c:1646  */
    {
                    timestampset.operator = (yyvsp[-6].number);
                    timestampset.time = ((yyvsp[-5].number) * (yyvsp[-4].number));
                    addeventaction(&(timestampset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addtimestamp(&timestampset);
                  }
#line 5839 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2207 "src/p.y" /* yacc.c:1646  */
    {
                    timestampset.test_changes = true;
                    addeventaction(&(timestampset).action, (yyvsp[0].number), Action_Ignored);
                    addtimestamp(&timestampset);
                  }
#line 5849 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2214 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Equal; }
#line 5855 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2215 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Greater; }
#line 5861 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2216 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_GreaterOrEqual; }
#line 5867 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2217 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Less; }
#line 5873 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2218 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_LessOrEqual; }
#line 5879 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2219 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Equal; }
#line 5885 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2220 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_NotEqual; }
#line 5891 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2221 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Changed; }
#line 5897 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2224 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Second; }
#line 5903 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2225 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Second; }
#line 5909 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2226 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Minute; }
#line 5915 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2227 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Hour; }
#line 5921 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2228 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Day; }
#line 5927 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2229 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Month; }
#line 5933 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2232 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Minute; }
#line 5939 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2233 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Hour; }
#line 5945 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2234 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Day; }
#line 5951 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2236 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Second; }
#line 5957 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 658:
#line 2237 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Second; }
#line 5963 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 659:
#line 2239 "src/p.y" /* yacc.c:1646  */
    {
                        repeat = 0;
                  }
#line 5971 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 660:
#line 2242 "src/p.y" /* yacc.c:1646  */
    {
                        repeat = 1;
                  }
#line 5979 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 661:
#line 2245 "src/p.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[-1].number) < 0) {
                                yyerror2("The number of repeat cycles must be greater or equal to 0");
                        }
                        repeat = (yyvsp[-1].number);
                  }
#line 5990 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 662:
#line 2253 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.number) = Action_Alert;
                  }
#line 5998 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 663:
#line 2256 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.number) = Action_Exec;
                  }
#line 6006 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 664:
#line 2260 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.number) = Action_Exec;
                  }
#line 6014 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 665:
#line 2263 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.number) = Action_Restart;
                  }
#line 6022 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 666:
#line 2266 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.number) = Action_Start;
                  }
#line 6030 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 667:
#line 2269 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.number) = Action_Stop;
                  }
#line 6038 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2272 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.number) = Action_Unmonitor;
                  }
#line 6046 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2277 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                    if ((yyvsp[0].number) == Action_Exec && command) {
                      repeat1 = repeat;
                      repeat = 0;
                      command1 = command;
                      command = NULL;
                    }
                  }
#line 6060 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 670:
#line 2288 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                    if ((yyvsp[0].number) == Action_Exec && command) {
                      repeat2 = repeat;
                      repeat = 0;
                      command2 = command;
                      command = NULL;
                    }
                  }
#line 6074 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 671:
#line 2299 "src/p.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > BITMAP_MAX) {
                                yyerror2("The number of cycles must be between 1 and %d", BITMAP_MAX);
                        } else {
                                rate.count  = (yyvsp[-1].number);
                                rate.cycles = (yyvsp[-1].number);
                        }
                  }
#line 6087 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 672:
#line 2309 "src/p.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[-1].number) < 1 || (yyvsp[-1].number) > BITMAP_MAX) {
                                yyerror2("The number of cycles must be between 1 and %d", BITMAP_MAX);
                        } else if ((yyvsp[-2].number) < 1 || (yyvsp[-2].number) > (yyvsp[-1].number)) {
                                yyerror2("The number of events must be between 1 and less then poll cycles");
                        } else {
                                rate.count  = (yyvsp[-2].number);
                                rate.cycles = (yyvsp[-1].number);
                        }
                  }
#line 6102 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 674:
#line 2322 "src/p.y" /* yacc.c:1646  */
    {
                        rate1.count = rate.count;
                        rate1.cycles = rate.cycles;
                        reset_rateset(&rate);
                  }
#line 6112 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 675:
#line 2327 "src/p.y" /* yacc.c:1646  */
    {
                        rate1.count = rate.count;
                        rate1.cycles = rate.cycles;
                        reset_rateset(&rate);
                }
#line 6122 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 677:
#line 2335 "src/p.y" /* yacc.c:1646  */
    {
                        rate2.count = rate.count;
                        rate2.cycles = rate.cycles;
                        reset_rateset(&rate);
                  }
#line 6132 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 678:
#line 2340 "src/p.y" /* yacc.c:1646  */
    {
                        rate2.count = rate.count;
                        rate2.cycles = rate.cycles;
                        reset_rateset(&rate);
                }
#line 6142 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 679:
#line 2347 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = Action_Alert;
                  }
#line 6150 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 680:
#line 2350 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                  }
#line 6158 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 681:
#line 2353 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                  }
#line 6166 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 682:
#line 2356 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                  }
#line 6174 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 683:
#line 2361 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(checksumset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addchecksum(&checksumset);
                  }
#line 6183 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 684:
#line 2366 "src/p.y" /* yacc.c:1646  */
    {
                    snprintf(checksumset.hash, sizeof(checksumset.hash), "%s", (yyvsp[-4].string));
                    FREE((yyvsp[-4].string));
                    addeventaction(&(checksumset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addchecksum(&checksumset);
                  }
#line 6194 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 685:
#line 2372 "src/p.y" /* yacc.c:1646  */
    {
                    checksumset.test_changes = true;
                    addeventaction(&(checksumset).action, (yyvsp[0].number), Action_Ignored);
                    addchecksum(&checksumset);
                  }
#line 6204 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 686:
#line 2378 "src/p.y" /* yacc.c:1646  */
    { checksumset.type = Hash_Unknown; }
#line 6210 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 687:
#line 2379 "src/p.y" /* yacc.c:1646  */
    { checksumset.type = Hash_Md5; }
#line 6216 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 688:
#line 2380 "src/p.y" /* yacc.c:1646  */
    { checksumset.type = Hash_Sha1; }
#line 6222 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 689:
#line 2383 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_Inode;
                    filesystemset.operator = (yyvsp[-5].number);
                    filesystemset.limit_absolute = (yyvsp[-4].number);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 6234 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 690:
#line 2390 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_Inode;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_percent = (yyvsp[-5].real);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 6246 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 691:
#line 2397 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_InodeFree;
                    filesystemset.operator = (yyvsp[-5].number);
                    filesystemset.limit_absolute = (yyvsp[-4].number);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 6258 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 692:
#line 2404 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_InodeFree;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_percent = (yyvsp[-5].real);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 6270 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 693:
#line 2413 "src/p.y" /* yacc.c:1646  */
    {
                    if (! filesystem_usage(current))
                      yyerror2("Cannot read usage of filesystem %s", current->path);
                    filesystemset.resource = Resource_Space;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_absolute = (long long)((double)(yyvsp[-5].real) / (double)current->inf->priv.filesystem.f_bsize * (double)(yyvsp[-4].number));
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 6284 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 694:
#line 2422 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_Space;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_percent = (yyvsp[-5].real);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 6296 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 695:
#line 2429 "src/p.y" /* yacc.c:1646  */
    {
                    if (! filesystem_usage(current))
                      yyerror2("Cannot read usage of filesystem %s", current->path);
                    filesystemset.resource = Resource_SpaceFree;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_absolute = (long long)((double)(yyvsp[-5].real) / (double)current->inf->priv.filesystem.f_bsize * (double)(yyvsp[-4].number));
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 6310 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 696:
#line 2438 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_SpaceFree;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_percent = (yyvsp[-5].real);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 6322 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 697:
#line 2447 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(fsflagset).action, (yyvsp[0].number), Action_Ignored);
                    addfsflag(&fsflagset);
                  }
#line 6331 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 698:
#line 2453 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Byte; }
#line 6337 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 699:
#line 2454 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Byte; }
#line 6343 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 700:
#line 2455 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Kilobyte; }
#line 6349 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 701:
#line 2456 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Megabyte; }
#line 6355 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 702:
#line 2457 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Gigabyte; }
#line 6361 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 703:
#line 2460 "src/p.y" /* yacc.c:1646  */
    {
                    permset.perm = check_perm((yyvsp[-4].number));
                    addeventaction(&(permset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addperm(&permset);
                  }
#line 6371 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 704:
#line 2465 "src/p.y" /* yacc.c:1646  */
    {
                    permset.test_changes = true;
                    addeventaction(&(permset).action, (yyvsp[-1].number), Action_Ignored);
                    addperm(&permset);
                  }
#line 6381 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 705:
#line 2472 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.not = (yyvsp[-4].number) == Operator_Equal ? false : true;
                    matchset.ignore = false;
                    matchset.match_path = (yyvsp[-3].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, (yyvsp[0].number));
                    FREE((yyvsp[-3].string));
                  }
#line 6394 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 706:
#line 2480 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.not = (yyvsp[-4].number) == Operator_Equal ? false : true;
                    matchset.ignore = false;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[-3].string);
                    addmatch(&matchset, (yyvsp[0].number), 0);
                  }
#line 6406 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 707:
#line 2487 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.not = (yyvsp[-1].number) == Operator_Equal ? false : true;
                    matchset.ignore = true;
                    matchset.match_path = (yyvsp[0].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, Action_Ignored);
                    FREE((yyvsp[0].string));
                  }
#line 6419 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 708:
#line 2495 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.not = (yyvsp[-1].number) == Operator_Equal ? false : true;
                    matchset.ignore = true;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[0].string);
                    addmatch(&matchset, Action_Ignored, 0);
                  }
#line 6431 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 709:
#line 2503 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.ignore = false;
                    matchset.match_path = (yyvsp[-3].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, (yyvsp[0].number));
                    FREE((yyvsp[-3].string));
                  }
#line 6443 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 710:
#line 2510 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.ignore = false;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[-3].string);
                    addmatch(&matchset, (yyvsp[0].number), 0);
                  }
#line 6454 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 711:
#line 2516 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.ignore = true;
                    matchset.match_path = (yyvsp[0].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, Action_Ignored);
                    FREE((yyvsp[0].string));
                  }
#line 6466 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 712:
#line 2523 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.ignore = true;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[0].string);
                    addmatch(&matchset, Action_Ignored, 0);
                  }
#line 6477 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 713:
#line 2531 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.not = false;
                  }
#line 6485 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 714:
#line 2534 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.not = true;
                  }
#line 6493 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 715:
#line 2540 "src/p.y" /* yacc.c:1646  */
    {
                    sizeset.operator = (yyvsp[-6].number);
                    sizeset.size = ((unsigned long long)(yyvsp[-5].number) * (yyvsp[-4].number));
                    addeventaction(&(sizeset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addsize(&sizeset);
                  }
#line 6504 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 716:
#line 2546 "src/p.y" /* yacc.c:1646  */
    {
                    sizeset.test_changes = true;
                    addeventaction(&(sizeset).action, (yyvsp[0].number), Action_Ignored);
                    addsize(&sizeset);
                  }
#line 6514 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 717:
#line 2553 "src/p.y" /* yacc.c:1646  */
    {
                    uidset.uid = get_uid((yyvsp[-4].string), 0);
                    addeventaction(&(uidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->uid = adduid(&uidset);
                    FREE((yyvsp[-4].string));
                  }
#line 6525 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 718:
#line 2559 "src/p.y" /* yacc.c:1646  */
    {
                    uidset.uid = get_uid(NULL, (yyvsp[-4].number));
                    addeventaction(&(uidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->uid = adduid(&uidset);
                  }
#line 6535 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 719:
#line 2566 "src/p.y" /* yacc.c:1646  */
    {
                    uidset.uid = get_uid((yyvsp[-4].string), 0);
                    addeventaction(&(uidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->euid = adduid(&uidset);
                    FREE((yyvsp[-4].string));
                  }
#line 6546 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 720:
#line 2572 "src/p.y" /* yacc.c:1646  */
    {
                    uidset.uid = get_uid(NULL, (yyvsp[-4].number));
                    addeventaction(&(uidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->euid = adduid(&uidset);
                  }
#line 6556 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 721:
#line 2579 "src/p.y" /* yacc.c:1646  */
    {
                    gidset.gid = get_gid((yyvsp[-4].string), 0);
                    addeventaction(&(gidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->gid = addgid(&gidset);
                    FREE((yyvsp[-4].string));
                  }
#line 6567 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 722:
#line 2585 "src/p.y" /* yacc.c:1646  */
    {
                    gidset.gid = get_gid(NULL, (yyvsp[-4].number));
                    addeventaction(&(gidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->gid = addgid(&gidset);
                  }
#line 6577 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 723:
#line 2592 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(linkstatusset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addlinkstatus(current, &linkstatusset);
                  }
#line 6586 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 724:
#line 2598 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(linkspeedset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addlinkspeed(current, &linkspeedset);
                  }
#line 6595 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 725:
#line 2603 "src/p.y" /* yacc.c:1646  */
    {
                    linksaturationset.operator = (yyvsp[-6].number);
                    linksaturationset.limit = (unsigned long long)(yyvsp[-5].number);
                    addeventaction(&(linksaturationset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addlinksaturation(current, &linksaturationset);
                  }
#line 6606 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 726:
#line 2611 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-6].number) * (yyvsp[-5].number));
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadbyteslist), &bandwidthset);
                  }
#line 6619 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 727:
#line 2619 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-6].number) * (yyvsp[-5].number));
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadbyteslist), &bandwidthset);
                  }
#line 6632 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 728:
#line 2627 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-8].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-7].number) * (yyvsp[-6].number));
                    bandwidthset.rangecount = (yyvsp[-5].number);
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadbyteslist), &bandwidthset);
                  }
#line 6645 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 729:
#line 2635 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-6].number);
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadpacketslist), &bandwidthset);
                  }
#line 6658 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 730:
#line 2643 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-6].number);
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadpacketslist), &bandwidthset);
                  }
#line 6671 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 731:
#line 2651 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-8].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-7].number);
                    bandwidthset.rangecount = (yyvsp[-5].number);
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadpacketslist), &bandwidthset);
                  }
#line 6684 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 732:
#line 2661 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-6].number) * (yyvsp[-5].number));
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadbyteslist), &bandwidthset);
                  }
#line 6697 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 733:
#line 2669 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-6].number) * (yyvsp[-5].number));
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadbyteslist), &bandwidthset);
                  }
#line 6710 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 734:
#line 2677 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-8].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-7].number) * (yyvsp[-6].number));
                    bandwidthset.rangecount = (yyvsp[-5].number);
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadbyteslist), &bandwidthset);
                  }
#line 6723 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 735:
#line 2685 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-6].number);
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadpacketslist), &bandwidthset);
                  }
#line 6736 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 736:
#line 2693 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-6].number);
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadpacketslist), &bandwidthset);
                  }
#line 6749 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 737:
#line 2701 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-8].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-7].number);
                    bandwidthset.rangecount = (yyvsp[-5].number);
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadpacketslist), &bandwidthset);
                  }
#line 6762 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 738:
#line 2711 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = ICMP_ECHO; }
#line 6768 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 739:
#line 2714 "src/p.y" /* yacc.c:1646  */
    { mailset.reminder = 0; }
#line 6774 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 740:
#line 2715 "src/p.y" /* yacc.c:1646  */
    { mailset.reminder = (yyvsp[0].number); }
#line 6780 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 741:
#line 2716 "src/p.y" /* yacc.c:1646  */
    { mailset.reminder = (yyvsp[-1].number); }
#line 6786 "src/y.tab.c" /* yacc.c:1646  */
    break;


#line 6790 "src/y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2719 "src/p.y" /* yacc.c:1906  */



/* -------------------------------------------------------- Parser interface */


/**
 * Syntactic error routine
 *
 * This routine is automatically called by the lexer!
 */
void yyerror(const char *s, ...) {
        va_list ap;
        char *msg = NULL;

        ASSERT(s);

        va_start(ap,s);
        msg = Str_vcat(s, ap);
        va_end(ap);

        LogError("%s:%i: %s '%s'\n", currentfile, lineno, msg, yytext);
        cfg_errflag++;

        FREE(msg);

}

/**
 * Syntactical warning routine
 */
void yywarning(const char *s, ...) {
        va_list ap;
        char *msg = NULL;

        ASSERT(s);

        va_start(ap,s);
        msg = Str_vcat(s, ap);
        va_end(ap);

        LogWarning("%s:%i: %s '%s'\n", currentfile, lineno, msg, yytext);

        FREE(msg);

}

/**
 * Argument error routine
 */
void yyerror2(const char *s, ...) {
        va_list ap;
        char *msg = NULL;

        ASSERT(s);

        va_start(ap,s);
        msg = Str_vcat(s, ap);
        va_end(ap);

        LogError("%s:%i: %s '%s'\n", argcurrentfile, arglineno, msg, argyytext);
        cfg_errflag++;

        FREE(msg);

}

/**
 * Argument warning routine
 */
void yywarning2(const char *s, ...) {
        va_list ap;
        char *msg = NULL;

        ASSERT(s);

        va_start(ap,s);
        msg = Str_vcat(s, ap);
        va_end(ap);

        LogWarning("%s:%i: %s '%s'\n", argcurrentfile, arglineno, msg, argyytext);

        FREE(msg);

}

/*
 * The Parser hook - start parsing the control file
 * Returns true if parsing succeeded, otherwise false
 */
boolean_t parse(char *controlfile) {

        ASSERT(controlfile);

        servicelist = tail = current = NULL;

        if ((yyin = fopen(controlfile,"r")) == (FILE *)NULL) {
                LogError("Cannot open the control file '%s' -- %s\n", controlfile, STRERROR);
                return false;
        }

        currentfile = Str_dup(controlfile);

        /*
         * Creation of the global service list is synchronized
         */
        LOCK(Run.mutex)
        {
                preparse();
                yyparse();
                fclose(yyin);
                postparse();
        }
        END_LOCK;

        FREE(currentfile);

        if (argyytext != NULL)
                FREE(argyytext);

        /*
         * Secure check the monitrc file. The run control file must have the
         * same uid as the REAL uid of this process, it must have permissions
         * no greater than 700 and it must not be a symbolic link.
         */
        if (! file_checkStat(controlfile, "control file", S_IRUSR|S_IWUSR|S_IXUSR))
                return false;

        return cfg_errflag == 0;
}


/* ----------------------------------------------------------------- Private */


/**
 * Initialize objects used by the parser.
 */
static void preparse() {
        /* Set instance incarnation ID */
        time(&Run.incarnation);
        /* Reset lexer */
        buffer_stack_ptr            = 0;
        lineno                      = 1;
        arglineno                   = 1;
        argcurrentfile              = NULL;
        argyytext                   = NULL;
        /* Reset parser */
        Run.limits.sendExpectBuffer  = LIMIT_SENDEXPECTBUFFER;
        Run.limits.fileContentBuffer = LIMIT_FILECONTENTBUFFER;
        Run.limits.httpContentBuffer = LIMIT_HTTPCONTENTBUFFER;
        Run.limits.programOutput     = LIMIT_PROGRAMOUTPUT;
        Run.limits.networkTimeout    = LIMIT_NETWORKTIMEOUT;
        Run.limits.programTimeout    = LIMIT_PROGRAMTIMEOUT;
        Run.limits.stopTimeout       = LIMIT_STOPTIMEOUT;
        Run.limits.startTimeout      = LIMIT_STARTTIMEOUT;
        Run.limits.restartTimeout    = LIMIT_RESTARTTIMEOUT;
        Run.onreboot                 = Onreboot_Start;
        Run.mmonitcredentials        = NULL;
        Run.httpd.flags              = Httpd_Disabled | Httpd_Signature;
        Run.httpd.credentials        = NULL;
        memset(&(Run.httpd.socket), 0, sizeof(Run.httpd.socket));
        Run.mailserver_timeout       = SMTP_TIMEOUT;
        Run.eventlist_dir            = NULL;
        Run.eventlist_slots          = -1;
        Run.system                   = NULL;
        Run.mmonits                  = NULL;
        Run.maillist                 = NULL;
        Run.mailservers              = NULL;
        Run.MailFormat.from          = NULL;
        Run.MailFormat.replyto       = NULL;
        Run.MailFormat.subject       = NULL;
        Run.MailFormat.message       = NULL;
        depend_list                  = NULL;
        Run.flags |= Run_HandlerInit | Run_MmonitCredentials;
        for (int i = 0; i <= Handler_Max; i++)
                Run.handler_queue[i] = 0;

        /*
         * Initialize objects
         */
        reset_uidset();
        reset_gidset();
        reset_statusset();
        reset_sizeset();
        reset_mailset();
        reset_sslset();
        reset_mailserverset();
        reset_mmonitset();
        reset_portset();
        reset_permset();
        reset_icmpset();
        reset_linkstatusset();
        reset_linkspeedset();
        reset_linksaturationset();
        reset_bandwidthset();
        reset_rateset(&rate);
        reset_rateset(&rate1);
        reset_rateset(&rate2);
        reset_filesystemset();
        reset_resourceset();
        reset_checksumset();
        reset_timestampset();
        reset_actionrateset();
}


/*
 * Check that values are reasonable after parsing
 */
static void postparse() {
        if (cfg_errflag)
                return;

        /* If defined - add the last service to the service list */
        if (current)
                addservice(current);

        /* Check that we do not start monit in daemon mode without having a poll time */
        if (! Run.polltime && ((Run.flags & Run_Daemon) || (Run.flags & Run_Foreground))) {
                LogError("Poll time is invalid or not defined. Please define poll time in the control file\nas a number (> 0)  or use the -d option when starting monit\n");
                cfg_errflag++;
        }

        if (Run.files.log)
                Run.flags |= Run_Log;

        /* Add the default general system service if not specified explicitly: service name default to hostname */
        if (! Run.system) {
                char hostname[STRLEN];
                if (gethostname(hostname, sizeof(hostname))) {
                        LogError("Cannot get system hostname -- please add 'check system <name>'\n");
                        cfg_errflag++;
                }
                if (Util_existService(hostname)) {
                        LogError("'check system' not defined in control file, failed to add automatic configuration (service name %s is used already) -- please add 'check system <name>' manually\n", hostname);
                        cfg_errflag++;
                }
                Run.system = createservice(Service_System, Str_dup(hostname), NULL, check_system);
                addservice(Run.system);
        }
        addeventaction(&(Run.system->action_MONIT_START), Action_Start, Action_Ignored);
        addeventaction(&(Run.system->action_MONIT_STOP), Action_Stop,  Action_Ignored);

        if (Run.mmonits) {
                if (Run.httpd.flags & Httpd_Net) {
                        if (Run.flags & Run_MmonitCredentials) {
                                Auth_T c;
                                for (c = Run.httpd.credentials; c; c = c->next) {
                                        if (c->digesttype == Digest_Cleartext && ! c->is_readonly) {
                                                Run.mmonitcredentials = c;
                                                break;
                                        }
                                }
                                if (! Run.mmonitcredentials)
                                        LogWarning("M/Monit registration with credentials enabled, but no suitable credentials found in monit configuration file -- please add 'allow user:password' option to 'set httpd' statement\n");
                        }
                } else if (Run.httpd.flags & Httpd_Unix) {
                        LogWarning("M/Monit enabled but Monit httpd is using unix socket -- please change 'set httpd' statement to use TCP port in order to be able to manage services on Monit\n");
                } else {
                        LogWarning("M/Monit enabled but no httpd allowed -- please add 'set httpd' statement\n");
                }
        }

        /* Check the sanity of any dependency graph */
        check_depend();

#ifdef HAVE_OPENSSL
        Ssl_setFipsMode(Run.flags & Run_FipsEnabled);
#endif

        Processor_setHttpPostLimit();
}


static boolean_t _parseOutgoingAddress(const char *ip, Outgoing_T *outgoing) {
        struct addrinfo *result, hints = {.ai_flags = AI_NUMERICHOST};
        int status = getaddrinfo(ip, NULL, &hints, &result);
        if (status == 0) {
                outgoing->ip = (char *)ip;
                outgoing->addrlen = result->ai_addrlen;
                memcpy(&(outgoing->addr), result->ai_addr, result->ai_addrlen);
                freeaddrinfo(result);
                return true;
        } else {
                yyerror2("IP address parsing failed -- %s", ip, status == EAI_SYSTEM ? STRERROR : gai_strerror(status));
        }
        return false;
}


/*
 * Create a new service object and add any current objects to the
 * service list.
 */
static Service_T createservice(Service_Type type, char *name, char *value, State_Type (*check)(Service_T s)) {
        ASSERT(name);

        check_name(name);

        if (current)
                addservice(current);

        NEW(current);

        current->type = type;

        NEW(current->inf);
        Util_resetInfo(current);

        if (type == Service_Program) {
                NEW(current->program);
                current->program->args = command;
                command = NULL;
                current->program->timeout = Run.limits.programTimeout;
        }

        /* Set default values */
        current->mode     = Monitor_Active;
        current->monitor  = Monitor_Init;
        current->onreboot = Run.onreboot;
        current->name     = name;
        current->check    = check;
        current->path     = value;

        /* Initialize general event handlers */
        addeventaction(&(current)->action_DATA,     Action_Alert,     Action_Alert);
        addeventaction(&(current)->action_EXEC,     Action_Alert,     Action_Alert);
        addeventaction(&(current)->action_INVALID,  Action_Restart,   Action_Alert);

        /* Initialize internal event handlers */
        addeventaction(&(current)->action_ACTION,       Action_Alert, Action_Ignored);

        gettimeofday(&current->collected, NULL);

        return current;
}


/*
 * Add a service object to the servicelist
 */
static void addservice(Service_T s) {
        ASSERT(s);

        // Test sanity check
        switch (s->type) {
                case Service_Host:
                        // Verify that a remote service has a port or an icmp list
                        if (! s->portlist && ! s->icmplist) {
                                LogError("'check host' statement is incomplete: Please specify a port number to test\n or an icmp test at the remote host: '%s'\n", s->name);
                                cfg_errflag++;
                        }
                        break;
                case Service_Program:
                        // Verify that a program test has a status test
                        if (! s->statuslist) {
                                LogError("'check program %s' is incomplete: Please add an 'if status != n' test\n", s->name);
                                cfg_errflag++;
                        }
                        // Create the Command object
                        char program[PATH_MAX];
                        strncpy(program, s->program->args->arg[0], sizeof(program) - 1);
                        s->program->C = Command_new(program, NULL);
                        for (int i = 1; i < s->program->args->length; i++) {
                                Command_appendArgument(s->program->C, s->program->args->arg[i]);
                                snprintf(program + strlen(program), sizeof(program) - strlen(program) - 1, " %s", s->program->args->arg[i]);
                        }
                        s->path = Str_dup(program);
                        if (s->program->args->has_uid)
                                Command_setUid(s->program->C, s->program->args->uid);
                        if (s->program->args->has_gid)
                                Command_setGid(s->program->C, s->program->args->gid);
                        // Set environment
                        Command_setEnv(s->program->C, "MONIT_SERVICE", s->name);
                        break;
                case Service_Net:
                        if (! s->linkstatuslist) {
                                // Add link status test if not defined
                                addeventaction(&(linkstatusset).action, Action_Alert, Action_Alert);
                                addlinkstatus(s, &linkstatusset);
                        }
                        break;
                case Service_Filesystem:
                        if (! s->fsflaglist) {
                                // Add filesystem flags change test if not defined
                                addeventaction(&(fsflagset).action, Action_Alert, Action_Ignored);
                                addfsflag(&fsflagset);
                        }
                        break;
                case Service_Directory:
                case Service_Fifo:
                case Service_File:
                case Service_Process:
                        if (! s->nonexistlist) {
                                // Add existence test if not defined
                                addeventaction(&(nonexistset).action, Action_Restart, Action_Alert);
                                addnonexist(&nonexistset);
                        }
                        break;
                default:
                        break;
        }

        /* Add the service to the end of the service list */
        if (tail != NULL) {
                tail->next = s;
                tail->next_conf = s;
        } else {
                servicelist = s;
                servicelist_conf = s;
        }
        tail = s;
}


/*
 * Add entry to service group list
 */
static void addservicegroup(char *name) {
        ServiceGroup_T g;

        ASSERT(name);

        /* Check if service group with the same name is defined already */
        for (g = servicegrouplist; g; g = g->next)
                if (IS(g->name, name))
                        break;

        if (! g) {
                NEW(g);
                g->name = Str_dup(name);
                g->members = List_new();
                g->next = servicegrouplist;
                servicegrouplist = g;
        }

        List_append(g->members, current);
}


/*
 * Add a dependant entry to the current service dependant list
 *
 */
static void adddependant(char *dependant) {
        Dependant_T d;

        ASSERT(dependant);

        NEW(d);

        if (current->dependantlist)
                d->next = current->dependantlist;

        d->dependant = dependant;
        current->dependantlist = d;

}


/*
 * Add the given mailaddress with the appropriate alert notification
 * values and mail attributes to the given mailinglist.
 */
static void addmail(char *mailto, Mail_T f, Mail_T *l) {
        Mail_T m;

        ASSERT(mailto);

        NEW(m);
        m->to       = mailto;
        m->from     = f->from;
        m->replyto  = f->replyto;
        m->subject  = f->subject;
        m->message  = f->message;
        m->events   = f->events;
        m->reminder = f->reminder;

        m->next = *l;
        *l = m;

        reset_mailset();
}


/*
 * Add the given portset to the current service's portlist
 */
static void addport(Port_T *list, Port_T port) {
        ASSERT(port);

        if (port->protocol->check == check_radius && port->type != Socket_Udp)
                yyerror("Radius protocol test supports UDP only");

        Port_T p;
        NEW(p);
        p->is_available       = Connection_Init;
        p->type               = port->type;
        p->socket             = port->socket;
        p->family             = port->family;
        p->action             = port->action;
        p->timeout            = port->timeout;
        p->retry              = port->retry;
        p->protocol           = port->protocol;
        p->hostname           = port->hostname;
        p->url_request        = port->url_request;
        p->outgoing           = port->outgoing;
        if (p->family == Socket_Unix) {
                p->target.unix.pathname = port->target.unix.pathname;
        } else {
                p->target.net.port = port->target.net.port;
                if (sslset.flags) {
#ifdef HAVE_OPENSSL
                        if (sslset.flags && (p->target.net.port == 25 || p->target.net.port == 587))
                                p->target.net.ssl.flags = SSL_StartTLS;
                        else
                                p->target.net.ssl.flags = sslset.flags;
                        p->target.net.ssl.verify = sslset.verify;
                        p->target.net.ssl.allowSelfSigned = sslset.allowSelfSigned;
                        p->target.net.ssl.minimumValidDays = sslset.minimumValidDays;
                        p->target.net.ssl.version = sslset.version;
                        p->target.net.ssl.checksumType = sslset.checksumType;
                        p->target.net.ssl.checksum = sslset.checksum;
                        p->target.net.ssl.clientpemfile = sslset.clientpemfile;
                        p->target.net.ssl.CACertificateFile = sslset.CACertificateFile;
                        p->target.net.ssl.CACertificatePath = sslset.CACertificatePath;
#else
                        yyerror("SSL check cannot be activated -- SSL disabled");
#endif
                }
        }
        memcpy(&p->parameters, &port->parameters, sizeof(port->parameters));

        if (p->protocol->check == check_http) {
                if (p->parameters.http.checksum) {
                        cleanup_hash_string(p->parameters.http.checksum);
                        if (strlen(p->parameters.http.checksum) == 32)
                                p->parameters.http.hashtype = Hash_Md5;
                        else if (strlen(p->parameters.http.checksum) == 40)
                                p->parameters.http.hashtype = Hash_Sha1;
                        else
                                yyerror2("invalid checksum [%s]", p->parameters.http.checksum);
                } else {
                        p->parameters.http.hashtype = Hash_Unknown;
                }
        }

        p->next = *list;
        *list = p;

        reset_sslset();
        reset_portset();

}


static void addhttpheader(Port_T port, const char *header) {
        if (! port->parameters.http.headers)
                port->parameters.http.headers = List_new();
        List_append(port->parameters.http.headers, (char *)header);
}


/*
 * Add a new resource object to the current service resource list
 */
static void addresource(Resource_T rr) {
        ASSERT(rr);
        if (Run.flags & Run_ProcessEngineEnabled) {
                Resource_T r;
                NEW(r);
                r->resource_id = rr->resource_id;
                r->limit       = rr->limit;
                r->action      = rr->action;
                r->operator    = rr->operator;
                r->next        = current->resourcelist;
                current->resourcelist = r;
        } else {
                yywarning("Cannot activate service check. The process status engine was disabled. On certain systems you must run monit as root to utilize this feature)\n");
        }
        reset_resourceset();
}


/*
 * Add a new file object to the current service timestamp list
 */
static void addtimestamp(Timestamp_T ts) {
        ASSERT(ts);

        Timestamp_T t;
        NEW(t);
        t->operator     = ts->operator;
        t->time         = ts->time;
        t->action       = ts->action;
        t->test_changes = ts->test_changes;

        if (t->test_changes) {
                if (! File_exist(current->path))
                        DEBUG("The path '%s' used in the TIMESTAMP statement refer to a non-existing object\n", current->path);
                else if (! (t->timestamp = file_getTimestamp(current->path, S_IFDIR|S_IFREG)))
                        yyerror2("Cannot get the timestamp for '%s'", current->path);
                else
                        t->initialized = true;
        }

        t->next = current->timestamplist;
        current->timestamplist = t;

        reset_timestampset();
}


/*
 * Add a new object to the current service actionrate list
 */
static void addactionrate(ActionRate_T ar) {
        ActionRate_T a;

        ASSERT(ar);

        if (ar->count > ar->cycle)
                yyerror2("The number of restarts must be less than poll cycles");
        if (ar->count <= 0 || ar->cycle <= 0)
                yyerror2("Zero or negative values not allowed in a action rate statement");

        NEW(a);
        a->count  = ar->count;
        a->cycle  = ar->cycle;
        a->action = ar->action;

        a->next = current->actionratelist;
        current->actionratelist = a;

        reset_actionrateset();
}



/*
 * Add a new Size object to the current service size list
 */
static void addsize(Size_T ss) {
        Size_T s;
        struct stat buf;

        ASSERT(ss);

        NEW(s);
        s->operator     = ss->operator;
        s->size         = ss->size;
        s->action       = ss->action;
        s->test_changes = ss->test_changes;
        /* Get the initial size for future comparision, if the file exists */
        if (s->test_changes) {
                s->initialized = ! stat(current->path, &buf);
                if (s->initialized)
                        s->size = (unsigned long long)buf.st_size;
        }

        s->next = current->sizelist;
        current->sizelist = s;

        reset_sizeset();
}


/*
 * Add a new Uptime object to the current service uptime list
 */
static void adduptime(Uptime_T uu) {
        Uptime_T u;

        ASSERT(uu);

        NEW(u);
        u->operator = uu->operator;
        u->uptime = uu->uptime;
        u->action = uu->action;

        u->next = current->uptimelist;
        current->uptimelist = u;

        reset_uptimeset();
}


/*
 * Add a new Pid object to the current service pid list
 */
static void addpid(Pid_T pp) {
        ASSERT(pp);

        Pid_T p;
        NEW(p);
        p->action = pp->action;

        p->next = current->pidlist;
        current->pidlist = p;

        reset_pidset();
}


/*
 * Add a new PPid object to the current service ppid list
 */
static void addppid(Pid_T pp) {
        ASSERT(pp);

        Pid_T p;
        NEW(p);
        p->action = pp->action;

        p->next = current->ppidlist;
        current->ppidlist = p;

        reset_ppidset();
}


/*
 * Add a new Fsflag object to the current service fsflag list
 */
static void addfsflag(Fsflag_T ff) {
        ASSERT(ff);

        Fsflag_T f;
        NEW(f);
        f->action = ff->action;

        f->next = current->fsflaglist;
        current->fsflaglist = f;

        reset_fsflagset();
}


/*
 * Add a new Nonexist object to the current service list
 */
static void addnonexist(Nonexist_T ff) {
        ASSERT(ff);

        Nonexist_T f;
        NEW(f);
        f->action = ff->action;

        f->next = current->nonexistlist;
        current->nonexistlist = f;

        reset_nonexistset();
}


/*
 * Set Checksum object in the current service
 */
static void addchecksum(Checksum_T cs) {
        ASSERT(cs);

        cs->initialized = true;

        if (! *cs->hash) {
                if (cs->type == Hash_Unknown)
                        cs->type = Hash_Default;
                if (! (Util_getChecksum(current->path, cs->type, cs->hash, sizeof(cs->hash)))) {
                        /* If the file doesn't exist, set dummy value */
                        snprintf(cs->hash, sizeof(cs->hash), cs->type == Hash_Md5 ? "00000000000000000000000000000000" : "0000000000000000000000000000000000000000");
                        cs->initialized = false;
                        yywarning2("Cannot compute a checksum for file %s", current->path);
                }
        }

        int len = cleanup_hash_string(cs->hash);
        if (cs->type == Hash_Unknown) {
                if (len == 32) {
                        cs->type = Hash_Md5;
                } else if (len == 40) {
                        cs->type = Hash_Sha1;
                } else {
                        yyerror2("Unknown checksum type [%s] for file %s", cs->hash, current->path);
                        reset_checksumset();
                        return;
                }
        } else if ((cs->type == Hash_Md5 && len != 32) || (cs->type == Hash_Sha1 && len != 40)) {
                yyerror2("Invalid checksum [%s] for file %s", cs->hash, current->path);
                reset_checksumset();
                return;
        }

        Checksum_T c;
        NEW(c);
        c->type         = cs->type;
        c->test_changes = cs->test_changes;
        c->initialized  = cs->initialized;
        c->action       = cs->action;
        snprintf(c->hash, sizeof(c->hash), "%s", cs->hash);

        current->checksum = c;

        reset_checksumset();

}


/*
 * Set Perm object in the current service
 */
static void addperm(Perm_T ps) {
        ASSERT(ps);

        Perm_T p;
        NEW(p);
        p->action = ps->action;
        p->test_changes = ps->test_changes;
        if (p->test_changes) {
                if (! File_exist(current->path))
                        DEBUG("The path '%s' used in the PERMISSION statement refer to a non-existing object\n", current->path);
                else if ((p->perm = File_mod(current->path)) < 0)
                        yyerror2("Cannot get the timestamp for '%s'", current->path);
                else
                        p->perm &= 07777;
        } else {
                p->perm = ps->perm;
        }
        current->perm = p;
        reset_permset();
}


static void addlinkstatus(Service_T s, LinkStatus_T L) {
        ASSERT(L);
        
        LinkStatus_T l;
        NEW(l);
        l->action = L->action;
        
        l->next = s->linkstatuslist;
        s->linkstatuslist = l;
        
        reset_linkstatusset();
}


static void addlinkspeed(Service_T s, LinkSpeed_T L) {
        ASSERT(L);
        
        LinkSpeed_T l;
        NEW(l);
        l->action = L->action;
        
        l->next = s->linkspeedlist;
        s->linkspeedlist = l;
        
        reset_linkspeedset();
}


static void addlinksaturation(Service_T s, LinkSaturation_T L) {
        ASSERT(L);
        
        LinkSaturation_T l;
        NEW(l);
        l->operator = L->operator;
        l->limit = L->limit;
        l->action = L->action;
        
        l->next = s->linksaturationlist;
        s->linksaturationlist = l;
        
        reset_linksaturationset();
}


/*
 * Return Bandwidth object
 */
static void addbandwidth(Bandwidth_T *list, Bandwidth_T b) {
        ASSERT(list);
        ASSERT(b);

        if (b->rangecount * b->range > 24 * Time_Hour) {
                yyerror2("Maximum range for total test is 24 hours");
        } else if (b->range == Time_Minute && b->rangecount > 60) {
                yyerror2("Maximum value for [minute(s)] unit is 60");
        } else if (b->range == Time_Hour && b->rangecount > 24) {
                yyerror2("Maximum value for [hour(s)] unit is 24");
        } else if (b->range == Time_Day && b->rangecount > 1) {
                yyerror2("Maximum value for [day(s)] unit is 1");
        } else {
                if (b->range == Time_Day) {
                        // translate last day -> last 24 hours
                        b->rangecount = 24;
                        b->range = Time_Hour;
                }
                Bandwidth_T bandwidth;
                NEW(bandwidth);
                bandwidth->operator = b->operator;
                bandwidth->limit = b->limit;
                bandwidth->rangecount = b->rangecount;
                bandwidth->range = b->range;
                bandwidth->action = b->action;
                bandwidth->next = *list;
                *list = bandwidth;
        }
        reset_bandwidthset();
}


static void appendmatch(Match_T *list, Match_T item) {
        if (*list) {
                /* Find the end of the list (keep the same patterns order as in the config file) */
                Match_T last;
                for (last = *list; last->next; last = last->next)
                        ;
                last->next = item;
        } else {
                *list = item;
        }
}


/*
 * Set Match object in the current service
 */
static void addmatch(Match_T ms, int actionnumber, int linenumber) {
        Match_T m;

        ASSERT(ms);

        NEW(m);
        NEW(m->regex_comp);

        m->match_string = ms->match_string;
        m->match_path   = ms->match_path ? Str_dup(ms->match_path) : NULL;
        m->action       = ms->action;
        m->not          = ms->not;
        m->ignore       = ms->ignore;
        m->next         = NULL;

        addeventaction(&(m->action), actionnumber, Action_Ignored);

        int reg_return = regcomp(m->regex_comp, ms->match_string, REG_NOSUB|REG_EXTENDED);

        if (reg_return != 0) {
                char errbuf[STRLEN];
                regerror(reg_return, ms->regex_comp, errbuf, STRLEN);
                if (m->match_path != NULL)
                        yyerror2("Regex parsing error: %s on line %i of", errbuf, linenumber);
                else
                        yyerror2("Regex parsing error: %s", errbuf);
        }
        appendmatch(m->ignore ? &current->matchignorelist : &current->matchlist, m);
}


static void addmatchpath(Match_T ms, Action_Type actionnumber) {

        FILE *handle;
        command_t savecommand = NULL;
        char buf[2048];
        int linenumber = 0;

        ASSERT(ms->match_path);

        handle = fopen(ms->match_path, "r");
        if (handle == NULL) {
                yyerror2("Cannot read regex match file (%s)", ms->match_path);
                return;
        }

        while (! feof(handle)) {
                size_t len;

                linenumber++;

                if (! fgets(buf, 2048, handle))
                        continue;

                len = strlen(buf);

                if (len == 0 || buf[0] == '\n')
                        continue;

                if (buf[len-1] == '\n')
                        buf[len-1] = 0;

                ms->match_string = Str_dup(buf);

                /* The addeventaction() called from addmatch() will reset the
                 * command1 to NULL, but we need to duplicate the command for
                 * each line, thus need to save it here */
                if (actionnumber == Action_Exec) {
                        if (command1 == NULL) {
                                ASSERT(savecommand);
                                command1 = savecommand;
                        }
                        savecommand = copycommand(command1);
                }
                
                addmatch(ms, actionnumber, linenumber);
        }
        
        if (actionnumber == Action_Exec && savecommand)
                gccmd(&savecommand);
        
        fclose(handle);
}


/*
 * Set exit status test object in the current service
 */
static void addstatus(Status_T status) {
        Status_T s;
        ASSERT(status);
        NEW(s);
        s->initialized = status->initialized;
        s->return_value = status->return_value;
        s->operator = status->operator;
        s->action = status->action;
        s->next = current->statuslist;
        current->statuslist = s;

        reset_statusset();
}


/*
 * Set Uid object in the current service
 */
static Uid_T adduid(Uid_T u) {
        ASSERT(u);

        Uid_T uid;
        NEW(uid);
        uid->uid = u->uid;
        uid->action = u->action;
        reset_uidset();
        return uid;
}


/*
 * Set Gid object in the current service
 */
static Gid_T addgid(Gid_T g) {
        ASSERT(g);

        Gid_T gid;
        NEW(gid);
        gid->gid = g->gid;
        gid->action = g->action;
        reset_gidset();
        return gid;
}


/*
 * Add a new filesystem to the current service's filesystem list
 */
static void addfilesystem(Filesystem_T ds) {
        Filesystem_T dev;

        ASSERT(ds);

        NEW(dev);
        dev->resource           = ds->resource;
        dev->operator           = ds->operator;
        dev->limit_absolute     = ds->limit_absolute;
        dev->limit_percent      = ds->limit_percent;
        dev->action             = ds->action;

        dev->next               = current->filesystemlist;
        current->filesystemlist = dev;
        
        reset_filesystemset();

}


/*
 * Add a new icmp object to the current service's icmp list
 */
static void addicmp(Icmp_T is) {
        Icmp_T icmp;

        ASSERT(is);

        NEW(icmp);
        icmp->family       = is->family;
        icmp->type         = is->type;
        icmp->size         = is->size;
        icmp->count        = is->count;
        icmp->timeout      = is->timeout;
        icmp->action       = is->action;
        icmp->outgoing     = is->outgoing;
        icmp->is_available = Connection_Init;
        icmp->response     = -1;

        icmp->next         = current->icmplist;
        current->icmplist  = icmp;

        reset_icmpset();
}


/*
 * Set EventAction object
 */
static void addeventaction(EventAction_T *_ea, Action_Type failed, Action_Type succeeded) {
        EventAction_T ea;

        ASSERT(_ea);

        NEW(ea);
        NEW(ea->failed);
        NEW(ea->succeeded);

        ea->failed->id = failed;
        ea->failed->repeat = repeat1;
        ea->failed->count = rate1.count;
        ea->failed->cycles = rate1.cycles;
        if (failed == Action_Exec) {
                ASSERT(command1);
                ea->failed->exec = command1;
                command1 = NULL;
        }

        ea->succeeded->id = succeeded;
        ea->succeeded->repeat = repeat2;
        ea->succeeded->count = rate2.count;
        ea->succeeded->cycles = rate2.cycles;
        if (succeeded == Action_Exec) {
                ASSERT(command2);
                ea->succeeded->exec = command2;
                command2 = NULL;
        }
        *_ea = ea;
        reset_rateset(&rate);
        reset_rateset(&rate1);
        reset_rateset(&rate2);
        repeat = repeat1 = repeat2 = 0;
}


/*
 * Add a generic protocol handler to
 */
static void addgeneric(Port_T port, char *send, char *expect) {
        Generic_T g = port->parameters.generic.sendexpect;
        if (! g) {
                NEW(g);
                port->parameters.generic.sendexpect = g;
        } else {
                while (g->next)
                        g = g->next;
                NEW(g->next);
                g = g->next;
        }
        if (send) {
                g->send = send;
                g->expect = NULL;
        } else if (expect) {
                int reg_return;
                NEW(g->expect);
                reg_return = regcomp(g->expect, expect, REG_NOSUB|REG_EXTENDED);
                FREE(expect);
                if (reg_return != 0) {
                        char errbuf[STRLEN];
                        regerror(reg_return, g->expect, errbuf, STRLEN);
                        yyerror2("Regex parsing error: %s", errbuf);
                }
                g->send = NULL;
        }
}


/*
 * Add the current command object to the current service object's
 * start or stop program.
 */
static void addcommand(int what, unsigned timeout) {

        switch (what) {
                case START:   current->start = command; break;
                case STOP:    current->stop = command; break;
                case RESTART: current->restart = command; break;
        }

        command->timeout = timeout;
        
        command = NULL;

}


/*
 * Add a new argument to the argument list
 */
static void addargument(char *argument) {

        ASSERT(argument);

        if (! command) {

                NEW(command);
                check_exec(argument);

        }

        command->arg[command->length++] = argument;
        command->arg[command->length] = NULL;

        if (command->length >= ARGMAX)
                yyerror("Exceeded maximum number of program arguments");

}


/*
 * Setup a url request for the current port object
 */
static void prepare_urlrequest(URL_T U) {

        ASSERT(U);

        /* Only the HTTP protocol is supported for URLs currently. See also the lexer if this is to be changed in the future */
        portset.protocol = Protocol_get(Protocol_HTTP);

        if (urlrequest == NULL)
                NEW(urlrequest);
        urlrequest->url = U;
        portset.hostname = Str_dup(U->hostname);
        portset.target.net.port = U->port;
        portset.url_request = urlrequest;
        portset.type = Socket_Tcp;
        portset.parameters.http.request = Str_cat("%s%s%s", U->path, U->query ? "?" : "", U->query ? U->query : "");
        if (IS(U->protocol, "https"))
                sslset.flags = SSL_Enabled;
}


/*
 * Set the url request for a port
 */
static void  seturlrequest(int operator, char *regex) {

        ASSERT(regex);

        if (! urlrequest)
                NEW(urlrequest);
        urlrequest->operator = operator;
        int reg_return;
        NEW(urlrequest->regex);
        reg_return = regcomp(urlrequest->regex, regex, REG_NOSUB|REG_EXTENDED);
        if (reg_return != 0) {
                char errbuf[STRLEN];
                regerror(reg_return, urlrequest->regex, errbuf, STRLEN);
                yyerror2("Regex parsing error: %s", errbuf);
        }
}


/*
 * Add a new data recipient server to the mmonit server list
 */
static void addmmonit(Mmonit_T mmonit) {
        ASSERT(mmonit->url);

        Mmonit_T c;
        NEW(c);
        c->url = mmonit->url;
        c->compress = MmonitCompress_Init;
        c->ssl.flags = sslset.flags;
        c->ssl.verify = sslset.verify;
        c->ssl.allowSelfSigned = sslset.allowSelfSigned;
        c->ssl.minimumValidDays = sslset.minimumValidDays;
        c->ssl.version = sslset.version;
        c->ssl.checksumType = sslset.checksumType;
        c->ssl.checksum = sslset.checksum;
        c->ssl.clientpemfile = sslset.clientpemfile;
        c->ssl.CACertificateFile = sslset.CACertificateFile;
        c->ssl.CACertificatePath = sslset.CACertificatePath;
        if (IS(c->url->protocol, "https")) {
#ifdef HAVE_OPENSSL
                c->ssl.flags = SSL_Enabled;
#else
                yyerror("SSL check cannot be activated -- SSL disabled");
#endif
        }
        c->timeout = mmonit->timeout;
        c->next = NULL;

        if (Run.mmonits) {
                Mmonit_T C;
                for (C = Run.mmonits; C->next; C = C->next)
                        /* Empty */ ;
                C->next = c;
        } else {
                Run.mmonits = c;
        }
        reset_sslset();
        reset_mmonitset();
}


/*
 * Add a new smtp server to the mail server list
 */
static void addmailserver(MailServer_T mailserver) {

        MailServer_T s;

        ASSERT(mailserver->host);

        NEW(s);
        s->host        = mailserver->host;
        s->port        = mailserver->port;
        s->username    = mailserver->username;
        s->password    = mailserver->password;

        if (sslset.flags && (mailserver->port == 25 || mailserver->port == 587))
                s->ssl.flags = SSL_StartTLS;
        else
                s->ssl.flags = sslset.flags;
        s->ssl.verify = sslset.verify;
        s->ssl.allowSelfSigned = sslset.allowSelfSigned;
        s->ssl.minimumValidDays = sslset.minimumValidDays;
        s->ssl.version = sslset.version;
        s->ssl.checksumType = sslset.checksumType;
        s->ssl.checksum = sslset.checksum;
        s->ssl.clientpemfile = sslset.clientpemfile;
        s->ssl.CACertificateFile = sslset.CACertificateFile;
        s->ssl.CACertificatePath = sslset.CACertificatePath;
        reset_sslset();

        s->next = NULL;

        if (Run.mailservers) {
                MailServer_T l;
                for (l = Run.mailservers; l->next; l = l->next)
                        /* empty */;
                l->next = s;
        } else {
                Run.mailservers = s;
        }
        reset_mailserverset();
}


/*
 * Return uid if found on the system. If the parameter user is NULL
 * the uid parameter is used for looking up the user id on the system,
 * otherwise the user parameter is used.
 */
static uid_t get_uid(char *user, uid_t uid) {
        char buf[4096];
        struct passwd pwd, *result = NULL;
        if (user) {
                if (getpwnam_r(user, &pwd, buf, sizeof(buf), &result) != 0 || ! result) {
                        yyerror2("Requested user not found on the system");
                        return(0);
                }
        } else {
                if (getpwuid_r(uid, &pwd, buf, sizeof(buf), &result) != 0 || ! result) {
                        yyerror2("Requested uid not found on the system");
                        return(0);
                }
        }
        return(pwd.pw_uid);
}


/*
 * Return gid if found on the system. If the parameter group is NULL
 * the gid parameter is used for looking up the group id on the system,
 * otherwise the group parameter is used.
 */
static gid_t get_gid(char *group, gid_t gid) {
        struct group *grd;

        if (group) {
                grd = getgrnam(group);

                if (! grd) {
                        yyerror2("Requested group not found on the system");
                        return(0);
                }

        } else {

                if (! (grd = getgrgid(gid))) {
                        yyerror2("Requested gid not found on the system");
                        return(0);
                }

        }

        return(grd->gr_gid);

}


/*
 * Add a new user id to the current command object.
 */
static void addeuid(uid_t uid) {
        if (! getuid()) {
                command->has_uid = true;
                command->uid = uid;
        } else {
                yyerror("UID statement requires root privileges");
        }
}


/*
 * Add a new group id to the current command object.
 */
static void addegid(gid_t gid) {
        if (! getuid()) {
                command->has_gid = true;
                command->gid = gid;
        } else {
                yyerror("GID statement requires root privileges");
        }
}


/*
 * Reset the logfile if changed
 */
static void setlogfile(char *logfile) {
        if (Run.files.log) {
                if (IS(Run.files.log, logfile)) {
                        FREE(logfile);
                        return;
                } else {
                        FREE(Run.files.log);
                }
        }
        Run.files.log = logfile;
}


/*
 * Reset the pidfile if changed
 */
static void setpidfile(char *pidfile) {
        if (Run.files.pid) {
                if (IS(Run.files.pid, pidfile)) {
                        FREE(pidfile);
                        return;
                } else {
                        FREE(Run.files.pid);
                }
        }
        Run.files.pid = pidfile;
}


/*
 * Read a apache htpasswd file and add credentials found for username
 */
static void addhtpasswdentry(char *filename, char *username, Digest_Type dtype) {
        char *ht_username = NULL;
        char *ht_passwd = NULL;
        char buf[STRLEN];
        FILE *handle = NULL;
        int credentials_added = 0;

        ASSERT(filename);

        handle = fopen(filename, "r");

        if ( handle == NULL ) {
                if (username != NULL)
                        yyerror2("Cannot read htpasswd (%s)", filename);
                else
                        yyerror2("Cannot read htpasswd", filename);
                return;
        }

        while (! feof(handle)) {
                char *colonindex = NULL;

                if (! fgets(buf, STRLEN, handle))
                        continue;

                Str_rtrim(buf);
                Str_curtail(buf, "#");

                if ( NULL == (colonindex = strchr(buf, ':')))
                continue;

                ht_passwd = Str_dup(colonindex+1);
                *colonindex = '\0';

                /* In case we have a file in /etc/passwd or /etc/shadow style we
                 *  want to remove ":.*$" and Crypt and MD5 hashed dont have a colon
                 */

                if ( (NULL != (colonindex = strchr(ht_passwd, ':'))) && ( dtype != Digest_Cleartext) )
                *colonindex = '\0';

                ht_username = Str_dup(buf);

                if (username == NULL) {
                        if (addcredentials(ht_username, ht_passwd, dtype, false))
                                credentials_added++;
                } else if (Str_cmp(username, ht_username) == 0)  {
                        if (addcredentials(ht_username, ht_passwd, dtype, false))
                                credentials_added++;
                } else {
                        FREE(ht_passwd);
                        FREE(ht_username);
                }
        }

        if (credentials_added == 0) {
                if ( username == NULL )
                        yywarning2("htpasswd file (%s) has no usable credentials", filename);
                else
                        yywarning2("htpasswd file (%s) has no usable credentials for user %s", filename, username);
        }
        fclose(handle);
}


#ifdef HAVE_LIBPAM
static void addpamauth(char* groupname, int readonly) {
        Auth_T prev = NULL;

        ASSERT(groupname);

        if (! Run.httpd.credentials)
                NEW(Run.httpd.credentials);

        Auth_T c = Run.httpd.credentials;
        do {
                if (c->groupname != NULL && IS(c->groupname, groupname)) {
                        yywarning2("PAM group %s was added already, entry ignored", groupname);
                        FREE(groupname);
                        return;
                }
                prev = c;
                c = c->next;
        } while (c != NULL);

        NEW(prev->next);
        c = prev->next;

        c->next        = NULL;
        c->uname       = NULL;
        c->passwd      = NULL;
        c->groupname   = groupname;
        c->digesttype  = Digest_Pam;
        c->is_readonly = readonly;

        DEBUG("Adding PAM group '%s'\n", groupname);

        return;
}
#endif


/*
 * Add Basic Authentication credentials
 */
static boolean_t addcredentials(char *uname, char *passwd, Digest_Type dtype, boolean_t readonly) {
        Auth_T c;

        ASSERT(uname);
        ASSERT(passwd);

        if (strlen(passwd) > MAX_CONSTANT_TIME_STRING_LENGTH) {
                yyerror2("Password for user %s is too long, maximum %d allowed", uname, MAX_CONSTANT_TIME_STRING_LENGTH);
                FREE(uname);
                FREE(passwd);
                return false;
        }

        if (! Run.httpd.credentials) {
                NEW(Run.httpd.credentials);
                c = Run.httpd.credentials;
        } else {
                if (Util_getUserCredentials(uname) != NULL) {
                        yywarning2("Credentials for user %s were already added, entry ignored", uname);
                        FREE(uname);
                        FREE(passwd);
                        return false;
                }
                c = Run.httpd.credentials;
                while (c->next != NULL)
                        c = c->next;
                NEW(c->next);
                c = c->next;
        }

        c->next        = NULL;
        c->uname       = uname;
        c->passwd      = passwd;
        c->groupname   = NULL;
        c->digesttype  = dtype;
        c->is_readonly = readonly;

        DEBUG("Adding credentials for user '%s'\n", uname);

        return true;

}


/*
 * Set the syslog and the facilities to be used
 */
static void setsyslog(char *facility) {

        if (! Run.files.log || ihp.logfile) {
                ihp.logfile = true;
                setlogfile(Str_dup("syslog"));
                Run.flags |= Run_UseSyslog;
                Run.flags |= Run_Log;
        }

        if (facility) {
                if (IS(facility,"log_local0"))
                        Run.facility = LOG_LOCAL0;
                else if (IS(facility, "log_local1"))
                        Run.facility = LOG_LOCAL1;
                else if (IS(facility, "log_local2"))
                        Run.facility = LOG_LOCAL2;
                else if (IS(facility, "log_local3"))
                        Run.facility = LOG_LOCAL3;
                else if (IS(facility, "log_local4"))
                        Run.facility = LOG_LOCAL4;
                else if (IS(facility, "log_local5"))
                        Run.facility = LOG_LOCAL5;
                else if (IS(facility, "log_local6"))
                        Run.facility = LOG_LOCAL6;
                else if (IS(facility, "log_local7"))
                        Run.facility = LOG_LOCAL7;
                else if (IS(facility, "log_daemon"))
                        Run.facility = LOG_DAEMON;
                else
                        yyerror2("Invalid syslog facility");
        } else {
                Run.facility = LOG_USER;
        }

}


/*
 * Reset the current sslset for reuse
 */
static void reset_sslset() {
        memset(&sslset, 0, sizeof(struct SslOptions_T));
        sslset.version = sslset.verify = sslset.allowSelfSigned = sslset.minimumValidDays = -1;
}


/*
 * Reset the current mailset for reuse
 */
static void reset_mailset() {
        memset(&mailset, 0, sizeof(struct mymail));
}


/*
 * Reset the mailserver set to default values
 */
static void reset_mailserverset() {
        memset(&mailserverset, 0, sizeof(struct mymailserver));
        mailserverset.port = PORT_SMTP;
}


/*
 * Reset the mmonit set to default values
 */
static void reset_mmonitset() {
        memset(&mmonitset, 0, sizeof(struct mymmonit));
        mmonitset.timeout = Run.limits.networkTimeout;
}


/*
 * Reset the Port set to default values
 */
static void reset_portset() {
        memset(&portset, 0, sizeof(struct myport));
        portset.socket = -1;
        portset.type = Socket_Tcp;
        portset.family = Socket_Ip;
        portset.timeout = Run.limits.networkTimeout;
        portset.retry = 1;
        portset.protocol = Protocol_get(Protocol_DEFAULT);
        urlrequest = NULL;
}


/*
 * Reset the Proc set to default values
 */
static void reset_resourceset() {
        resourceset.resource_id = 0;
        resourceset.limit = 0;
        resourceset.action = NULL;
        resourceset.operator = Operator_Equal;
}


/*
 * Reset the Timestamp set to default values
 */
static void reset_timestampset() {
        timestampset.operator = Operator_Equal;
        timestampset.time = 0;
        timestampset.test_changes = false;
        timestampset.initialized = false;
        timestampset.action = NULL;
}


/*
 * Reset the ActionRate set to default values
 */
static void reset_actionrateset() {
        actionrateset.count = 0;
        actionrateset.cycle = 0;
        actionrateset.action = NULL;
}


/*
 * Reset the Size set to default values
 */
static void reset_sizeset() {
        sizeset.operator = Operator_Equal;
        sizeset.size = 0;
        sizeset.test_changes = false;
        sizeset.action = NULL;
}


/*
 * Reset the Uptime set to default values
 */
static void reset_uptimeset() {
        uptimeset.operator = Operator_Equal;
        uptimeset.uptime = 0;
        uptimeset.action = NULL;
}


static void reset_linkstatusset() {
        linkstatusset.action = NULL;
}


static void reset_linkspeedset() {
        linkspeedset.action = NULL;
}


static void reset_linksaturationset() {
        linksaturationset.limit = 0.;
        linksaturationset.operator = Operator_Equal;
        linksaturationset.action = NULL;
}


/*
 * Reset the Bandwidth set to default values
 */
static void reset_bandwidthset() {
        bandwidthset.operator = Operator_Equal;
        bandwidthset.limit = 0ULL;
        bandwidthset.action = NULL;
}


/*
 * Reset the Pid set to default values
 */
static void reset_pidset() {
        pidset.action = NULL;
}


/*
 * Reset the PPid set to default values
 */
static void reset_ppidset() {
        ppidset.action = NULL;
}


/*
 * Reset the Fsflag set to default values
 */
static void reset_fsflagset() {
        fsflagset.action = NULL;
}


/*
 * Reset the Nonexist set to default values
 */
static void reset_nonexistset() {
        nonexistset.action = NULL;
}


/*
 * Reset the Checksum set to default values
 */
static void reset_checksumset() {
        checksumset.type         = Hash_Unknown;
        checksumset.test_changes = false;
        checksumset.action       = NULL;
        *checksumset.hash        = 0;
}


/*
 * Reset the Perm set to default values
 */
static void reset_permset() {
        permset.test_changes = false;
        permset.perm = 0;
        permset.action = NULL;
}


/*
 * Reset the Status set to default values
 */
static void reset_statusset() {
        statusset.initialized = false;
        statusset.return_value = 0;
        statusset.operator = Operator_Equal;
        statusset.action = NULL;
}


/*
 * Reset the Uid set to default values
 */
static void reset_uidset() {
        uidset.uid = 0;
        uidset.action = NULL;
}


/*
 * Reset the Gid set to default values
 */
static void reset_gidset() {
        gidset.gid = 0;
        gidset.action = NULL;
}


/*
 * Reset the Filesystem set to default values
 */
static void reset_filesystemset() {
        filesystemset.resource = 0;
        filesystemset.operator = Operator_Equal;
        filesystemset.limit_absolute = -1;
        filesystemset.limit_percent = -1.;
        filesystemset.action = NULL;
}


/*
 * Reset the ICMP set to default values
 */
static void reset_icmpset() {
        icmpset.type = ICMP_ECHO;
        icmpset.size = ICMP_SIZE;
        icmpset.count = ICMP_ATTEMPT_COUNT;
        icmpset.timeout = Run.limits.networkTimeout;
        icmpset.action = NULL;
}


/*
 * Reset the Rate set to default values
 */
static void reset_rateset(struct myrate *r) {
        r->count = 1;
        r->cycles = 1;
}


/* ---------------------------------------------------------------- Checkers */


/*
 * Check for unique service name
 */
static void check_name(char *name) {
        ASSERT(name);

        if (Util_existService(name) || (current && IS(name, current->name)))
                yyerror2("Service name conflict, %s already defined", name);
        if (name && *name == '/')
                yyerror2("Service name '%s' must not start with '/' -- ", name);
}


/*
 * Permission statement semantic check
 */
static int check_perm(int perm) {
        int result;
        char *status;
        char buf[STRLEN];

        snprintf(buf, STRLEN, "%d", perm);

        result = (int)strtol(buf, &status, 8);

        if (*status != '\0' || result < 0 || result > 07777)
                yyerror2("Permission statements must have an octal value between 0 and 7777");

        return result;
}


/*
 * Check the dependency graph for errors
 * by doing a topological sort, thereby finding any cycles.
 * Assures that graph is a Directed Acyclic Graph (DAG).
 */
static void check_depend() {
        Service_T s;
        Service_T depends_on = NULL;
        Service_T* dlt = &depend_list; /* the current tail of it                                 */
        boolean_t done;                /* no unvisited nodes left?                               */
        boolean_t found_some;          /* last iteration found anything new ?                    */
        depend_list = NULL;            /* depend_list will be the topological sorted servicelist */

        do {
                done = true;
                found_some = false;
                for (s = servicelist; s; s = s->next) {
                        Dependant_T d;
                        if (s->visited)
                                continue;
                        done = false; // still unvisited nodes
                        depends_on = NULL;
                        for (d = s->dependantlist; d; d = d->next) {
                                Service_T dp = Util_getService(d->dependant);
                                if (! dp) {
                                        LogError("Depend service '%s' is not defined in the control file\n", d->dependant);
                                        exit(1);
                                }
                                if (! dp->visited) {
                                        depends_on = dp;
                                }
                        }

                        if (! depends_on) {
                                s->visited = true;
                                found_some = true;
                                *dlt = s;
                                dlt = &s->next_depend;
                        }
                }
        } while (found_some && ! done);

        if (! done) {
                ASSERT(depends_on);
                LogError("Found a depend loop in the control file involving the service '%s'\n", depends_on->name);
                exit(1);
        }

        ASSERT(depend_list);
        servicelist = depend_list;

        for (s = depend_list; s; s = s->next_depend)
                s->next = s->next_depend;
}


/*
 * Check if the executable exist
 */
static void check_exec(char *exec) {
        if (! File_exist(exec))
                yywarning2("Program does not exist:");
        else if (! File_isExecutable(exec))
                yywarning2("Program is not executable:");
}


/* Return a valid max forward value for SIP header */
static int verifyMaxForward(int mf) {
        if (mf >= 0 && mf <= 255)
                return mf;
        yywarning2("SIP max forward is outside the range [0..255]. Setting max forward to 70");
        return 70;
}


/* -------------------------------------------------------------------- Misc */


/*
 * Cleans up a hash string, tolower and remove byte separators
 */
static int cleanup_hash_string(char *hashstring) {
        int i = 0, j = 0;

        ASSERT(hashstring);

        while (hashstring[i]) {
                if (isxdigit((int)hashstring[i])) {
                        hashstring[j] = tolower((int)hashstring[i]);
                        j++;
                }
                i++;
        }
        hashstring[j] = 0;
        return j;
}


/* Return deep copy of the command */
static command_t copycommand(command_t source) {
        int i;
        command_t copy = NULL;

        NEW(copy);
        copy->length = source->length;
        copy->has_uid = source->has_uid;
        copy->uid = source->uid;
        copy->has_gid = source->has_gid;
        copy->gid = source->gid;
        copy->timeout = source->timeout;
        for (i = 0; i < copy->length; i++)
        copy->arg[i] = Str_dup(source->arg[i]);
        copy->arg[copy->length] = NULL;

        return copy;
}

