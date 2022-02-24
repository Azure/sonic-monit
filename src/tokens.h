/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 306 "src/p.y" /* yacc.c:1909  */

        URL_T url;
        Address_T address;
        float real;
        int   number;
        char *string;

#line 590 "src/y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
