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

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#include "monit.h"
#include "cervlet.h" 
#include "engine.h"
#include "processor.h"
#include "base64.h"
#include "event.h" 
#include "alert.h"
#include "process.h"
#include "device.h"

// libmonit
#include "system/Time.h"

#define ACTION(c) !strncasecmp(req->url, c, sizeof(c))

/* URL Commands supported */
#define HOME        "/"
#define TEST        "/_monit"
#define ABOUT       "/_about"
#define PING        "/_ping"
#define GETID       "/_getid"
#define STATUS      "/_status"
#define STATUS2     "/_status2"
#define RUN         "/_runtime"
#define VIEWLOG     "/_viewlog"
#define DOACTION    "/_doaction"

/* Private prototypes */
static int is_readonly(HttpRequest);
static void doGet(HttpRequest, HttpResponse);
static void doPost(HttpRequest, HttpResponse);
static void do_home(HttpRequest, HttpResponse);
static void do_home_system(HttpRequest, HttpResponse);
static void do_home_filesystem(HttpRequest, HttpResponse);
static void do_home_directory(HttpRequest, HttpResponse);
static void do_home_file(HttpRequest, HttpResponse);
static void do_home_fifo(HttpRequest, HttpResponse);
static void do_home_process(HttpRequest, HttpResponse);
static void do_home_program(HttpRequest, HttpResponse);
static void do_home_host(HttpRequest, HttpResponse);
static void do_about(HttpRequest, HttpResponse);
static void do_ping(HttpRequest, HttpResponse);
static void do_getid(HttpRequest, HttpResponse);
static void do_runtime(HttpRequest, HttpResponse);
static void do_viewlog(HttpRequest, HttpResponse);
static void handle_action(HttpRequest, HttpResponse);
static void handle_do_action(HttpRequest, HttpResponse);
static void handle_run(HttpRequest, HttpResponse);
static void is_monit_running(HttpRequest, HttpResponse);
static void do_service(HttpRequest, HttpResponse, Service_T);
static void print_alerts(HttpResponse, Mail_T);
static void print_buttons(HttpRequest, HttpResponse, Service_T);
static void print_service_rules_port(HttpResponse, Service_T);
static void print_service_rules_icmp(HttpResponse, Service_T);
static void print_service_rules_perm(HttpResponse, Service_T);
static void print_service_rules_uid(HttpResponse, Service_T);
static void print_service_rules_gid(HttpResponse, Service_T);
static void print_service_rules_timestamp(HttpResponse, Service_T);
static void print_service_rules_filesystem(HttpResponse, Service_T);
static void print_service_rules_size(HttpResponse, Service_T);
static void print_service_rules_match(HttpResponse, Service_T);
static void print_service_rules_checksum(HttpResponse, Service_T);
static void print_service_rules_process(HttpResponse, Service_T);
static void print_service_rules_program(HttpResponse, Service_T);
static void print_service_rules_resource(HttpResponse, Service_T);
static void print_service_params_port(HttpResponse, Service_T);
static void print_service_params_icmp(HttpResponse, Service_T);
static void print_service_params_perm(HttpResponse, Service_T);
static void print_service_params_uid(HttpResponse, Service_T);
static void print_service_params_gid(HttpResponse, Service_T);
static void print_service_params_timestamp(HttpResponse, Service_T);
static void print_service_params_filesystem(HttpResponse, Service_T);
static void print_service_params_size(HttpResponse, Service_T);
static void print_service_params_match(HttpResponse, Service_T);
static void print_service_params_checksum(HttpResponse, Service_T);
static void print_service_params_process(HttpResponse, Service_T);
static void print_service_params_resource(HttpResponse, Service_T);
static void print_service_params_program(HttpResponse, Service_T);
static void print_status(HttpRequest, HttpResponse, int);
static void status_service_txt(Service_T, HttpResponse, short);
static char *get_monitoring_status(Service_T s, char *, int);
static char *get_service_status(Service_T, char *, int);
static char *get_service_status_html(Service_T, char *, int);


/**
 *  Implementation of doGet and doPost routines used by the cervlet
 *  processor module. This particilary cervlet will provide
 *  information about the monit deamon and programs monitored by
 *  monit.
 *
 *  @file
 */


/* ------------------------------------------------------------------ Public */


/**
 * Callback hook to the Processor module for registering this modules
 * doGet and doPost methods.
 */
void init_service() {
        
        add_Impl(doGet, doPost);
        
}


/* ----------------------------------------------------------------- Private */


/**
 * Called by the Processor (via the service method)
 * to handle a POST request.
 */
static void doPost(HttpRequest req, HttpResponse res) {
        
        set_content_type(res, "text/html");
        
        if(ACTION(RUN)) {
                handle_run(req, res);
        } else if(ACTION(DOACTION)) {
                handle_do_action(req, res);
        } else {
                handle_action(req, res);
        }
        
}


/**
 * Called by the Processor (via the service method)
 * to handle a GET request.
 */
static void doGet(HttpRequest req, HttpResponse res) {
        
        set_content_type(res, "text/html");
        
        if(ACTION(HOME)) {
                LOCK(Run.mutex)
                do_home(req, res);
                END_LOCK;
        } else if(ACTION(RUN)) {
                handle_run(req, res);
        } else if(ACTION(TEST)) {
                is_monit_running(req, res);
        } else if(ACTION(VIEWLOG)) {
                do_viewlog(req, res);
        } else if(ACTION(ABOUT)) {
                do_about(req, res);
        } else if(ACTION(PING)) {
                do_ping(req, res);
        } else if(ACTION(GETID)) {
                do_getid(req, res);
        } else if(ACTION(STATUS)) {
                print_status(req, res, 1);
        } else if(ACTION(STATUS2)) {
                print_status(req, res, 2);
        } else if(ACTION(DOACTION)) {
                handle_do_action(req, res);
        } else {
                handle_action(req, res);
        }
        
}


/* ----------------------------------------------------------------- Helpers */


static void is_monit_running(HttpRequest req, HttpResponse res) {
        
        int status;
        int monit= exist_daemon();
        
        if(monit) {
                status= SC_OK;
        } else {
                status= SC_GONE;
        }
        
        set_status(res, status);
        
}


static void do_home(HttpRequest req, HttpResponse res) {
        char *uptime= Util_getUptime(Util_getProcessUptime(Run.pidfile), "&nbsp;");
        
        HEAD("", "", Run.polltime)
        out_print(res,
                  "<table id='header' width='100%%'>"
                  " <tr>"
                  "  <td colspan=2 valign='top' align='left' width='100%%'>"
                  "  <h1>Monit Service Manager</h1>"
                  "  <p align='center'>Monit is <a href='_runtime'>running</a> on %s with <i>uptime, %s</i> and monitoring:</p><br>"
                  "  </td>"
                  " </tr>"
                  "</table>", Run.localhostname, uptime);
        
        FREE(uptime);
        
        do_home_system(req, res);
        do_home_process(req, res);
        do_home_program(req, res);
        do_home_filesystem(req, res);
        do_home_file(req, res);
        do_home_fifo(req, res);
        do_home_directory(req, res);
        do_home_host(req, res);

        FOOT
}


static void do_about(HttpRequest req, HttpResponse res) {
        
        out_print(res,
                  "<html><head><title>about monit</title></head><body bgcolor=white>"
                  "<br><h1><center><a href='http://mmonit.com/monit/'>"
                  "monit " VERSION "</a></center></h1>");
        out_print(res,
                  "<ul>"
                  "<li style='padding-bottom:10px;'>Copyright &copy; 2000-2011 <a "
                  "href='http://tildeslash.com/'>Tildeslash Ltd"
                  "</a>. All Rights Reserved.</li>"
                  "<li>Portions of this software are copyright &copy; 1995, 1996 "
                  "<a href='http://www.gnu.org/'>Free Software Foundation, Inc.</a></li></ul>");
        out_print(res, "<hr size='1'>");
        out_print(res,
                  "<p>This program is free software; you can redistribute it and/or "
                  "modify it under the terms of the GNU Affero General Public License version 3</p>"
                  "<p>This program is distributed in the hope that it will be useful, but "
                  "WITHOUT ANY WARRANTY; without even the implied warranty of "
                  "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the "
                  "<a href='http://www.gnu.org/licenses/agpl.html'>"
                  "GNU AFFERO GENERAL PUBLIC LICENSE</a> for more details.</p>");
        out_print(res,
                  "<center><p style='padding-top:20px;'>[<a href='.'>Back to Monit</a>]</p></body></html>");
        
}


static void do_ping(HttpRequest req, HttpResponse res) {
        out_print(res, "pong");
}


static void do_getid(HttpRequest req, HttpResponse res) {
        out_print(res, "%s", Run.id);
}

static void do_runtime(HttpRequest req, HttpResponse res) {
        
        int pid=  exist_daemon();
        
        HEAD("_runtime", "Runtime", 1000)
        out_print(res,
                  "<h2>Monit runtime status</h2>");
        out_print(res, "<table id='status-table'><tr>"
                  "<th width='40%%'>Parameter</th>"
                  "<th width='60%%'>Value</th></tr>");
        out_print(res, "<tr><td>Monit ID</td><td>%s</td></tr>", Run.id);
        out_print(res, "<tr><td>Host</td><td>%s</td></tr>",  Run.localhostname);
        out_print(res,
                  "<tr><td>Process id</td><td>%d</td></tr>", pid);
        out_print(res,
                  "<tr><td>Effective user running Monit</td>"
                  "<td>%s</td></tr>", Run.Env.user);
        out_print(res,
                  "<tr><td>Controlfile</td><td>%s</td></tr>", Run.controlfile);
        if(Run.logfile)
                out_print(res,
                          "<tr><td>Logfile</td><td>%s</td></tr>", Run.logfile);
        out_print(res,
                  "<tr><td>Pidfile</td><td>%s</td></tr>", Run.pidfile);
        out_print(res,
                  "<tr><td>State file</td><td>%s</td></tr>", Run.statefile);
        out_print(res,
                  "<tr><td>Debug</td><td>%s</td></tr>",
                  Run.debug?"True":"False");
        out_print(res,
                  "<tr><td>Log</td><td>%s</td></tr>", Run.dolog?"True":"False");
        out_print(res,
                  "<tr><td>Use syslog</td><td>%s</td></tr>",
                  Run.use_syslog?"True":"False");
        
        if(Run.eventlist_dir) {
                char slots[STRLEN];
                if(Run.eventlist_slots < 0)
                        snprintf(slots, STRLEN, "unlimited");
                else
                        snprintf(slots, STRLEN, "%d", Run.eventlist_slots);
                out_print(res,
                          "<tr><td>Event queue</td>"
                          "<td>base directory %s with %d slots</td></tr>",
                          Run.eventlist_dir, Run.eventlist_slots);
        }
        
        if(Run.mmonits) {
                Mmonit_T c;
                out_print(res, "<tr><td>M/Monit server(s)</td><td>");
                for(c= Run.mmonits; c; c= c->next)
                {
                        out_print(res,
                                  "%s with timeout %d seconds%s%s%s%s</td></tr>%s",
                                  c->url->url,
                                  c->timeout,
                                  c->ssl.use_ssl?" ssl version ":"",
                                  c->ssl.use_ssl?sslnames[c->ssl.version]:"",
                                  c->ssl.certmd5?" server cert md5 sum ":"",
                                  c->ssl.certmd5?c->ssl.certmd5:"",
                                  c->next?"<tr><td>&nbsp;</td><td>":"");
                }
                printf("\n");
        }
        
        if(Run.mailservers) {
                MailServer_T mta;
                out_print(res, "<tr><td>Mail server(s)</td><td>");
                for(mta= Run.mailservers; mta; mta= mta->next)
                        out_print(res, "%s:%d%s&nbsp;",
                                  mta->host, mta->port, mta->ssl.use_ssl?"(ssl)":"");
                out_print(res, "</td></tr>");
        }
        
        if(Run.MailFormat.from)
                out_print(res,
                          "<tr><td>Default mail from</td><td>%s</td></tr>",
                          Run.MailFormat.from);
        if(Run.MailFormat.subject)
                out_print(res,
                          "<tr><td>Default mail subject</td><td>%s</td></tr>",
                          Run.MailFormat.subject);
        if(Run.MailFormat.message)
                out_print(res,
                          "<tr><td>Default mail message</td><td>%s</td></tr>",
                          Run.MailFormat.message);
        
        out_print(res,
                  "<tr><td>Poll time</td><td>%d seconds with start delay %d seconds</td></tr>",
                  Run.polltime, Run.startdelay);
        out_print(res,
                  "<tr><td>httpd bind address</td><td>%s</td></tr>",
                  Run.bind_addr?Run.bind_addr:"Any/All");
        out_print(res,
                  "<tr><td>httpd portnumber</td><td>%d</td></tr>", Run.httpdport);
        out_print(res,
                  "<tr><td>httpd signature</td><td>%s</td></tr>",
                  Run.httpdsig?"True":"False");
        out_print(res,
                  "<tr><td>Use ssl encryption</td><td>%s</td></tr>",
                  Run.httpdssl?"True":"False");
        if (Run.httpdssl) {
                out_print(res,
                          "<tr><td>PEM key/certificate file</td><td>%s</td></tr>",
                          Run.httpsslpem);
                
                if (Run.httpsslclientpem!=NULL) {
                        out_print(res,
                                  "<tr><td>Client PEM key/certification"
                                  "</td><td>%s</td></tr>", "Enabled");
                        out_print(res,
                                  "<tr><td>Client PEM key/certificate file"
                                  "</td><td>%s</td></tr>", Run.httpsslclientpem);
                } else {
                        out_print(res,
                                  "<tr><td>Client PEM key/certification"
                                  "</td><td>%s</td></tr>", "Disabled");
                }
                out_print(res,
                          "<tr><td>Allow self certified certificates "
                          "</td><td>%s</td></tr>", Run.allowselfcert?"True":"False");
        }
        
        out_print(res,
                  "<tr><td>httpd auth. style</td><td>%s</td></tr>",
                  (Run.credentials!=NULL)&&(has_hosts_allow())?
                  "Basic Authentication and Host/Net allow list":
                  (Run.credentials!=NULL)?"Basic Authentication":
                  (has_hosts_allow())?"Host/Net allow list":
                  "No authentication");
        
        print_alerts(res, Run.maillist);
        
        out_print(res, "</table>");
        
        if(!is_readonly(req)) {
                out_print(res,
                          "<table id='buttons'><tr>");
                out_print(res,
                          "<td style='color:red;'><form method=POST action='_runtime'>Stop Monit http server? "
                          "<input type=hidden name='action' value='stop'><input type=submit value='Go'></form></td>");
                out_print(res,
                          "<td><form method=POST action='_runtime'>Force validate now? <input type=hidden name='action' value='validate'>"
                          "<input type=submit value='Go'></form></td>");
                
                if(Run.dolog && !Run.use_syslog) {
                        out_print(res,
                                  "<td><form method=GET action='_viewlog'>View Monit logfile? <input type=submit value='Go'></form></td>");
                }
                out_print(res,
                          "</tr></table>");
        }
        
        FOOT
        
}


static void do_viewlog(HttpRequest req, HttpResponse res) {
        
        if(is_readonly(req)) {
                send_error(res, SC_FORBIDDEN,
                           "You do not have sufficent privileges to access this page");
                return;
        }
        
        HEAD("_viewlog", "View log", 100)
        
        if(Run.dolog && !Run.use_syslog) {
                
                struct stat sb;
                
                if(!stat(Run.logfile, &sb)) {
                        
                        FILE *f= fopen(Run.logfile, "r");
                        if(f) {
#define BUFSIZE 512
                                size_t n;
                                char buf[BUFSIZE+1];
                                out_print(res, "<br><p><form><textarea cols=120 rows=30 readonly>");
                                while((n = fread(buf, sizeof(char), BUFSIZE, f)) > 0) {
                                        buf[n] = 0;
                                        out_print(res, "%s", buf);
                                }
                                fclose(f);
                                out_print(res, "</textarea></form>");
                        } else {
                                out_print(res, "Error opening logfile: %s", STRERROR);
                        }
                } else {
                        out_print(res, "Error stating logfile: %s", STRERROR);
                }
        } else {
                
                out_print(res,
                          "<b>Cannot view logfile:</b><br>");
                if(!Run.dolog) {
                        
                        out_print(res, "Monit was started without logging");
                        
                } else {
                        
                        out_print(res, "Monit uses syslog");
                        
                }
                
        }
        
        FOOT
        
}


static void handle_action(HttpRequest req, HttpResponse res) {
        int doaction;
        char *name = req->url;
        const char *action;
        Service_T s;
        
        if(!(s = Util_getService(++name))) {
                send_error(res, SC_NOT_FOUND, "There is no service by that name");
                return;
        }
        if((action = get_parameter(req, "action"))) {
                const char *token = NULL;
                
                if(is_readonly(req)) {
                        send_error(res, SC_FORBIDDEN, "You do not have sufficent privileges to access this page");
                        return;
                }
                doaction = Util_getAction(action);
                if(doaction == ACTION_IGNORE) {
                        send_error(res, SC_BAD_REQUEST, "Invalid action");
                        return;
                }
                if(s->doaction != ACTION_IGNORE) {
                        send_error(res, SC_SERVICE_UNAVAILABLE, "Other action already in progress -- please try again later");
                        return;
                }
                s->doaction = doaction;
                token = get_parameter(req, "token");
                if (token) {
                        FREE(s->token);
                        s->token = xstrdup(token);
                }
                LogInfo("'%s' %s on user request\n", s->name, action);
                Run.doaction = TRUE; /* set the global flag */
                do_wakeupcall();
        }
        do_service(req, res, s);
}


static void handle_do_action(HttpRequest req, HttpResponse res) {
        Service_T s;
        int doaction = ACTION_IGNORE;
        const char *action = get_parameter(req, "action");
        const char *token = get_parameter(req, "token");
        
        if(action) {
                HttpParameter p;
                
                if(is_readonly(req)) {
                        send_error(res, SC_FORBIDDEN, "You do not have sufficent privileges to access this page");
                        return;
                }
                if((doaction = Util_getAction(action)) == ACTION_IGNORE) {
                        send_error(res, SC_BAD_REQUEST, "Invalid action");
                        return;
                }
                
                for(p= req->params; p; p= p->next) {
                        
                        if(!strcasecmp(p->name, "service")) {
                                s  = Util_getService(p->value);
                                
                                if(!s) {
                                        send_error(res, SC_BAD_REQUEST, "There is no service by that name");
                                        return;
                                }
                                if(s->doaction != ACTION_IGNORE) {
                                        send_error(res, SC_SERVICE_UNAVAILABLE, "Other action already in progress -- please try again later");
                                        return;
                                }
                                s->doaction = doaction;
                                LogInfo("'%s' %s on user request\n", s->name, action);
                        }
                }
                
                /* Set token for last service only so we'll get it back after all services were handled */
                if (token) {
                        Service_T q = NULL;
                        for (s = servicelist; s; s = s->next)
                                if (s->doaction == doaction)
                                        q = s;
                        if (q) {
                                FREE(q->token);
                                q->token = xstrdup(token);
                        }
                }
                
                Run.doaction = TRUE; 
                do_wakeupcall();
        }
}


static void handle_run(HttpRequest req, HttpResponse res) {
        
        const char *action= get_parameter(req, "action");
        
        if(action) {
                if(is_readonly(req)) {
                        send_error(res, SC_FORBIDDEN,
                                   "You do not have sufficent privileges to access this page");
                        return;
                }
                if(IS(action, "validate")) {
                        LogInfo("The Monit http server woke up on user request\n");
                        do_wakeupcall();
                } else if(IS(action, "stop")) {
                        LogInfo("The Monit http server stopped on user request\n");
                        send_error(res, SC_SERVICE_UNAVAILABLE,
                                   "The Monit http server is stopped");
                        stop_httpd();
                        return;
                }
        }
        
        LOCK(Run.mutex)
        do_runtime(req, res);
        END_LOCK;
        
}


static void do_service(HttpRequest req, HttpResponse res, Service_T s) {
        Dependant_T d;
        ActionRate_T ar;
        ServiceGroup_T sg;
        ServiceGroupMember_T sgm;
        char buf[STRLEN];
        
        ASSERT(s);
        
        HEAD(s->name, s->name, Run.polltime)
        
        out_print(res,
                  "<h2>%s status</h2>"
                  "<table id='status-table'>"
                  "<tr>"
                  "<th width='30%%'>Parameter</th>"
                  "<th width='70%%'>Value</th>"
                  "</tr>"
                  "<tr>"
                  "<td>Name</td>"
                  "<td>%s</td>"
                  "</tr>",
                  servicetypes[s->type],
                  s->name);
        
        if(s->type == TYPE_PROCESS)
                out_print(res, "<tr><td>%s</td><td>%s</td></tr>", s->matchlist ? "Match" : "Pid file", s->path);
        else if(s->type != TYPE_HOST && s->type != TYPE_SYSTEM)
                out_print(res, "<tr><td>Path</td><td>%s</td></tr>", s->path);
        
        out_print(res,
                  "<tr><td>Status</td><td>%s</td></tr>", get_service_status_html(s, buf, sizeof(buf)));
        
        for (sg = servicegrouplist; sg; sg = sg->next)
                for (sgm = sg->members; sgm; sgm = sgm->next)
                        if (! strcasecmp(sgm->name, s->name))
                                out_print(res, "<tr><td>Group</td><td class='blue-text'>%s</td></tr>", sg->name);
        
        out_print(res,
                  "<tr><td>Monitoring mode</td><td>%s</td></tr>", modenames[s->mode]);
        
        out_print(res,
                  "<tr><td>Monitoring status</td><td>%s</td></tr>", get_monitoring_status(s, buf, sizeof(buf)));
        
        for(d= s->dependantlist; d; d= d->next) {
                if(d->dependant != NULL) {
                        out_print(res,
                                  "<tr><td>Depends on service </td><td> <a href=%s> %s </a></td></tr>",
                                  d->dependant, d->dependant);
                }
        }
        
        if(s->start) {
                int i= 0;
                out_print(res, "<tr><td>Start program</td><td>'");
                while(s->start->arg[i]) {
                        if(i) out_print(res, " ");
                        out_print(res, "%s", s->start->arg[i++]);
                }
                out_print(res, "'");
                if(s->start->has_uid)
                        out_print(res, " as uid %d", s->start->uid);
                if(s->start->has_gid)
                        out_print(res, " as gid %d", s->start->gid);
                out_print(res, " timeout %d second(s)", s->start->timeout);
                out_print(res, "</td></tr>");
        }
        
        if(s->stop) {
                int i= 0;
                out_print(res, "<tr><td>Stop program</td><td>'");
                while(s->stop->arg[i]) {
                        if(i) out_print(res, " ");
                        out_print(res, "%s", s->stop->arg[i++]);
                }
                out_print(res, "'");
                if(s->stop->has_uid)
                        out_print(res, " as uid %d", s->stop->uid);
                if(s->stop->has_gid)
                        out_print(res, " as gid %d", s->stop->gid);
                out_print(res, " timeout %d second(s)", s->stop->timeout);
                out_print(res, "</td></tr>");
        }
        
        if(s->type != TYPE_SYSTEM) {
                out_print(res, "<tr><td>Existence</td><td>If doesn't exist %s ", Util_getEventratio(s->action_NONEXIST->failed, buf, sizeof(buf)));
                out_print(res, "then %s ", Util_describeAction(s->action_NONEXIST->failed, buf, sizeof(buf)));
                out_print(res, "else if succeeded %s ", Util_getEventratio(s->action_NONEXIST->succeeded, buf, sizeof(buf)));
                out_print(res, "then %s</td></tr>", Util_describeAction(s->action_NONEXIST->succeeded, buf, sizeof(buf)));
        }
        
        if (s->every.type != EVERY_CYCLE) {
                out_print(res, "<tr><td>Check service</td><td>");
                if (s->every.type == EVERY_SKIPCYCLES)
                        out_print(res, "every %d cycle", s->every.spec.cycle.number);
                else if (s->every.type == EVERY_CRON)
                        out_print(res, "every <code>\"%s\"</code>", s->every.spec.cron);
                else if (s->every.type == EVERY_NOTINCRON)
                        out_print(res, "not every <code>\"%s\"</code>", s->every.spec.cron);
                out_print(res, "</td></tr>");
        }
        
        for (ar = s->actionratelist; ar; ar = ar->next)
                out_print(res, "<tr><td>Timeout</td><td>If restarted %d times within %d cycle(s) then %s</td></tr>", ar->count, ar->cycle, Util_describeAction(ar->action->failed, buf, sizeof(buf)));
        
        out_print(res, "<tr><td>Data collected</td><td>%s</td></tr>", Time_string(s->collected.tv_sec, buf));
        
        /* Parameters */
        print_service_params_icmp(res, s);
        print_service_params_port(res, s);
        print_service_params_perm(res, s);
        print_service_params_uid(res, s);
        print_service_params_gid(res, s);
        print_service_params_timestamp(res, s);
        print_service_params_filesystem(res, s);
        print_service_params_size(res, s);
        print_service_params_match(res, s);
        print_service_params_checksum(res, s);
        print_service_params_process(res, s);
        print_service_params_resource(res, s);
        print_service_params_program(res, s);
        
        /* Rules */
        print_service_rules_icmp(res, s);
        print_service_rules_port(res, s);
        print_service_rules_perm(res, s);
        print_service_rules_uid(res, s);
        print_service_rules_gid(res, s);
        print_service_rules_timestamp(res, s);
        print_service_rules_filesystem(res, s);
        print_service_rules_size(res, s);
        print_service_rules_match(res, s);
        print_service_rules_checksum(res, s);
        print_service_rules_process(res, s);
        print_service_rules_program(res, s);
        print_service_rules_resource(res, s);
        
        print_alerts(res, s->maillist);
        
        out_print(res, "</table>");
        
        print_buttons(req, res, s);
        
        FOOT
}


static void do_home_system(HttpRequest req, HttpResponse res) {
        Service_T s = Run.system;
        char buf[STRLEN];
        
        out_print(res,
                  "<table id='header-row'>"
                  "<tr>"
                  "<th align='left' class='first'>System</th>"
                  "<th align='left'>Status</th>");
        
        if(Run.doprocess) {
                out_print(res,
                          "<th align='right'>Load</th>"
                          "<th align='right'>CPU</th>"
                          "<th align='right'>Memory</th>"
                          "<th align='right'>Swap</th>");
        }
        
        out_print(res,
                  "</tr>"
                  "<tr class='stripe'>"
                  "<td align='left'><a href='%s'>%s</a></td>"
                  "<td align='left'>%s</td>",
                  s->name, s->name, get_service_status_html(s, buf, sizeof(buf)));
        
        if(Run.doprocess) {
                out_print(res,
                          "<td align='right'>[%.2f]&nbsp;[%.2f]&nbsp;[%.2f]</td>"
                          "<td align='right'>"
                          "%.1f%%us,&nbsp;%.1f%%sy"
#ifdef HAVE_CPU_WAIT
                          ",&nbsp;%.1f%%wa"
#endif
                          "</td>"
                          "<td align='right'>%.1f%% [%ld&nbsp;kB]</td>"
                          "<td align='right'>%.1f%% [%ld&nbsp;kB]</td>",
                          systeminfo.loadavg[0], systeminfo.loadavg[1], systeminfo.loadavg[2],
                          systeminfo.total_cpu_user_percent > 0 ? systeminfo.total_cpu_user_percent/10. : 0,
                          systeminfo.total_cpu_syst_percent > 0 ? systeminfo.total_cpu_syst_percent/10. : 0,
#ifdef HAVE_CPU_WAIT
                          systeminfo.total_cpu_wait_percent > 0 ? systeminfo.total_cpu_wait_percent/10. : 0,
#endif
                          systeminfo.total_mem_percent/10., systeminfo.total_mem_kbyte,
                          systeminfo.total_swap_percent/10., systeminfo.total_swap_kbyte);
        }
        
        out_print(res,
                  "</tr>"
                  "</table>");
}


static void do_home_process(HttpRequest req, HttpResponse res) {
        
        Service_T      s;
        char           buf[STRLEN];
        int            on= TRUE;
        int            header= TRUE;
        
        for(s= servicelist_conf; s; s= s->next_conf) {
                
                if(s->type != TYPE_PROCESS) continue;
                
                if(header) {
                        
                        out_print(res,
                                  "<table id='header-row'>"
                                  "<tr>"
                                  "<th align='left' class='first'>Process</th>"
                                  "<th align='left'>Status</th>"
                                  "<th align='right'>Uptime</th>");
                        
                        if(Run.doprocess) {
                                out_print(res,
                                          "<th align='right'>CPU Total</b></th>"
                                          "<th align='right'>Memory Total</th>");
                        }
                        
                        out_print(res, "</tr>");
                        
                        
                        header= FALSE;
                        
                }
                
                out_print(res,
                          "<tr %s>"
                          "<td><a href='%s'>%s</a></td>"
                          "<td align='left'>%s</td>",
                          on?"class='stripe'":"",
                          s->name, s->name, get_service_status_html(s, buf, sizeof(buf)));
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<td align='right'>-</td>");
                        
                        if(Run.doprocess) {
                                out_print(res,
                                          "<td align='right'>-</td>"
                                          "<td align='right'>-</td>");
                        }
                        
                } else {
                        
                        char *uptime= Util_getUptime(s->inf->priv.process.uptime, "&nbsp;");
                        out_print(res,
                                  "<td align='right'>%s</td>", uptime);
                        FREE(uptime);
                        
                        if(Run.doprocess) {
                                out_print(res,
                                          "<td align='right' class='%s'>%.1f%%</td>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          s->inf->priv.process.total_cpu_percent/10.0);
                                out_print(res,
                                          "<td align='right' class='%s'>%.1f%% [%ld&nbsp;kB]</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          s->inf->priv.process.mem_percent/10.0, s->inf->priv.process.total_mem_kbyte);
                        }
                        
                }
                
                out_print(res, "</tr>");
                
                on= on?FALSE:TRUE;
                
        }
        
        if(!header)
                out_print(res, "</table>");
        
}


static void do_home_program(HttpRequest req, HttpResponse res) {
        
        Service_T      s;
        char           buf[STRLEN];
        int            on= TRUE;
        int            header= TRUE;
        
        for(s= servicelist_conf; s; s= s->next_conf) {
                
                if(s->type != TYPE_PROGRAM) continue;
                
                if(header) {
                        
                        out_print(res,
                                  "<table id='header-row'>"
                                  "<tr>"
                                  "<th align='left' class='first'>Program</th>"
                                  "<th align='left'>Status</th>"
                                  "<th align='right'>Last started</th>"
                                  "<th align='right'>Exit value</th>");
                        
                        out_print(res, "</tr>");
                        
                        header= FALSE;
                        
                }
                
                out_print(res,
                          "<tr %s>"
                          "<td><a href='%s'>%s</a></td>"
                          "<td align='left'>%s</td>",
                          on?"class='stripe'":"",
                          s->name, s->name, get_service_status_html(s, buf, sizeof(buf)));
                
                if(!Util_hasServiceStatus(s)) {
                        out_print(res, "<td align='right'>-</td>");
                        out_print(res, "<td align='right'>-</td>");
                } else {
                        if (s->program->started) {
                                char t[32];
                                out_print(res, "<td align='right'>%s</td>", Time_string(s->program->started, t));
                                out_print(res, "<td align='right'>%d</td>", s->program->exitStatus);
                        } else {
                                out_print(res, "<td align='right'>Not yet started</td>");
                                out_print(res, "<td align='right'>N/A</td>");
                        }
                }
                
                out_print(res, "</tr>");
                
                on= on?FALSE:TRUE;
                
        }
        
        if(!header)
                out_print(res, "</table>");
        
}


static void do_home_filesystem(HttpRequest req, HttpResponse res) {
        Service_T     s;
        char          buf[STRLEN];
        int           on= TRUE;
        int           header= TRUE;
        
        for(s= servicelist_conf; s; s= s->next_conf) {
                
                if(s->type != TYPE_FILESYSTEM) continue;
                
                if(header) {
                        
                        out_print(res,
                                  "<table id='header-row'>"
                                  "<tr>"
                                  "<th align='left' class='first'>Filesystem</th>"
                                  "<th align='left'>Status</th>"
                                  "<th align='right'>Space usage</th>"
                                  "<th align='right'>Inodes usage</th>"
                                  "</tr>");
                        
                        header= FALSE;
                        
                }
                
                out_print(res,
                          "<tr %s>"
                          "<td><a href='%s'>%s</a></td>"
                          "<td align='left'>%s</td>",
                          on?"class='stripe'":"",
                          s->name, s->name, get_service_status_html(s, buf, sizeof(buf)));
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<td align='right'>- [-]</td>"
                                  "<td align='right'>- [-]</td>");
                        
                } else {
                        
                        out_print(res,
                                  "<td align='right'>%.1f%% [%.1f&nbsp;MB]</td>",
                                  s->inf->priv.filesystem.space_percent/10.,
                                  s->inf->priv.filesystem.f_bsize > 0 ? ((float)s->inf->priv.filesystem.space_total / (float)1048576 * (float)s->inf->priv.filesystem.f_bsize) : 0);
                        
                        if(s->inf->priv.filesystem.f_files > 0) {
                                
                                out_print(res,
                                          "<td align='right'>%.1f%% [%ld&nbsp;objects]</td>",
                                          s->inf->priv.filesystem.inode_percent/10.,
                                          s->inf->priv.filesystem.inode_total);
                                
                        } else {
                                
                                out_print(res,
                                          "<td align='right'>not supported by filesystem</td>");
                                
                        }
                        
                }
                
                out_print(res, "</tr>");
                
                on= on?FALSE:TRUE;
                
        }
        
        if(!header)
                out_print(res, "</table>");
        
}


static void do_home_file(HttpRequest req, HttpResponse res) {
        
        Service_T  s;
        char       buf[STRLEN];
        int        on= TRUE;
        int        header= TRUE;
        
        for(s= servicelist_conf; s; s= s->next_conf) {
                
                if(s->type != TYPE_FILE) continue;
                
                if(header) {
                        
                        out_print(res,
                                  "<table id='header-row'>"
                                  "<tr>"
                                  "<th align='left' class='first'>File</th>"
                                  "<th align='left'>Status</th>"
                                  "<th align='right'>Size</th>"
                                  "<th align='right'>Permission</th>"
                                  "<th align='right'>UID</th>"
                                  "<th align='right'>GID</th>"
                                  "</tr>");
                        
                        header= FALSE;
                        
                }
                
                out_print(res,
                          "<tr %s>"
                          "<td><a href='%s'>%s</a></td>"
                          "<td align='left'>%s</td>",
                          on?"class='stripe'":"",
                          s->name, s->name, get_service_status_html(s, buf, sizeof(buf)));
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<td align='right'>-</td>"
                                  "<td align='right'>-</td>"
                                  "<td align='right'>-</td>"
                                  "<td align='right'>-</td>");
                        
                } else {
                        
                        out_print(res,
                                  "<td align='right'>%llu&nbsp;B</td>"
                                  "<td align='right'>%04o</td>"
                                  "<td align='right'>%d</td>"
                                  "<td align='right'>%d</td>",
                                  (unsigned long long)s->inf->priv.file.st_size,
                                  s->inf->st_mode & 07777,
                                  s->inf->st_uid,
                                  s->inf->st_gid);
                        
                }
                
                out_print(res, "</tr>");
                
                on= on?FALSE:TRUE;
                
        }
        
        if(!header)
                out_print(res, "</table>");
        
}


static void do_home_fifo(HttpRequest req, HttpResponse res) {
        
        Service_T  s;
        char       buf[STRLEN];
        int        on= TRUE;
        int        header= TRUE;
        
        for(s= servicelist_conf; s; s= s->next_conf) {
                
                if(s->type != TYPE_FIFO) continue;
                
                if(header) {
                        
                        out_print(res,
                                  "<table id='header-row'>"
                                  "<tr>"
                                  "<th align='left' class='first'>Fifo</th>"
                                  "<th align='left'>Status</th>"
                                  "<th align='right'>Permission</th>"
                                  "<th align='right'>UID</th>"
                                  "<th align='right'>GID</th>"
                                  "</tr>");
                        
                        header= FALSE;
                        
                }
                
                out_print(res,
                          "<tr %s>"
                          "<td><a href='%s'>%s</a></td>"
                          "<td align='left'>%s</td>",
                          on?"class='stripe'":"",
                          s->name, s->name, get_service_status_html(s, buf, sizeof(buf)));
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<td align='right'>-</td>"
                                  "<td align='right'>-</td>"
                                  "<td align='right'>-</td>");
                        
                } else {
                        
                        out_print(res,
                                  "<td align='right'>%o</td>"
                                  "<td align='right'>%d</td>"
                                  "<td align='right'>%d</td>",
                                  s->inf->st_mode & 07777,
                                  s->inf->st_uid,
                                  s->inf->st_gid);
                        
                }
                
                out_print(res, "</tr>");
                
                on= on?FALSE:TRUE;
                
        }
        
        if(!header)
                out_print(res, "</table>");
        
}


static void do_home_directory(HttpRequest req, HttpResponse res) {
        
        Service_T        s;
        char             buf[STRLEN];
        int              on= TRUE;
        int              header= TRUE;
        
        for(s= servicelist_conf; s; s= s->next_conf) {
                
                if(s->type != TYPE_DIRECTORY) continue;
                
                if(header) {
                        
                        out_print(res,
                                  "<table id='header-row'>"
                                  "<tr>"
                                  "<th align='left' class='first'>Directory</th>"
                                  "<th align='left'>Status</th>"
                                  "<th align='right'>Permission</th>"
                                  "<th align='right'>UID</th>"
                                  "<th align='right'>GID</th>"
                                  "</tr>");
                        
                        header= FALSE;
                        
                }
                
                out_print(res,
                          "<tr %s>"
                          "<td><a href='%s'>%s</a></td>"
                          "<td align='left'>%s</td>",
                          on?"class='stripe'":"",
                          s->name, s->name, get_service_status_html(s, buf, sizeof(buf)));
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<td align='right'>-</td>"
                                  "<td align='right'>-</td>"
                                  "<td align='right'>-</td>");
                        
                } else {
                        
                        out_print(res,
                                  "<td align='right'>%o</td>"
                                  "<td align='right'>%d</td>"
                                  "<td align='right'>%d</td>",
                                  s->inf->st_mode & 07777,
                                  s->inf->st_uid,
                                  s->inf->st_gid);
                        
                }
                
                out_print(res, "</tr>");
                
                on= on?FALSE:TRUE;
                
        }
        
        if(!header)
                out_print(res, "</table>");
        
}


static void do_home_host(HttpRequest req, HttpResponse res) {
        
        Service_T  s;
        Icmp_T     icmp;
        Port_T     port;
        char       buf[STRLEN];
        int        on= TRUE;
        int        header= TRUE;
        
        for(s= servicelist_conf; s; s= s->next_conf) {
                
                if(s->type != TYPE_HOST) continue;
                
                if(header) {
                        
                        out_print(res,
                                  "<table id='header-row'>"
                                  "<tr>"
                                  "<th align='left' class='first'>Host</th>"
                                  "<th align='left'>Status</th>"
                                  "<th align='right'>Protocol(s)</th>"
                                  "</tr>");
                        
                        header= FALSE;
                        
                }
                
                out_print(res,
                          "<tr %s>"
                          "<td><a href='%s'>%s</a></td>"
                          "<td align='left'>%s</td>",
                          on?"class='stripe'":"",
                          s->name, s->name, get_service_status_html(s, buf, sizeof(buf)));
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<td align='right'>-</td>");
                        
                } else {
                        
                        out_print(res,
                                  "<td align='right'>");
                        
                        if(s->icmplist) {
                                for(icmp= s->icmplist; icmp; icmp= icmp->next) {
                                        if(icmp != s->icmplist)
                                                out_print(res, "&nbsp;&nbsp;<b>|</b>&nbsp;&nbsp;");
                                        out_print(res, "<span class='%s'>[ICMP %s]</span>",
                                                  (icmp->is_available)?"":"red-text",
                                                  icmpnames[icmp->type]);
                                }
                        }
                        
                        if(s->icmplist && s->portlist)
                                out_print(res, "&nbsp;&nbsp;<b>|</b>&nbsp;&nbsp;");
                        
                        if(s->portlist) {
                                for(port= s->portlist; port; port= port->next) {
                                        if(port != s->portlist)
                                                out_print(res, "&nbsp;&nbsp;<b>|</b>&nbsp;&nbsp;");
                                        out_print(res, "<span class='%s'>[%s] at port %d</span>",
                                                  (port->is_available)?"":"red-text",
                                                  port->protocol->name, port->port);
                                }
                        }
                        
                        out_print(res, "</td>");
                        
                }
                
                out_print(res, "</tr>");
                
                on= on?FALSE:TRUE;
                
        }
        
        if(!header)
                out_print(res, "</table>");
        
}


/* ------------------------------------------------------------------------- */


static void print_alerts(HttpResponse res, Mail_T s) {
        
        Mail_T r;
        
        for(r= s; r; r= r->next) {
                out_print(res,
                          "<tr class='stripe'><td>Alert mail to</td>"
                          "<td>%s</td></tr>", r->to?r->to:"");
                out_print(res, "<tr><td>Alert on</td><td>");
                
                if(r->events == Event_Null) {
                        out_print(res, "No events");
                } else if(r->events == Event_All) {
                        out_print(res, "All events");
                } else {
                        if(IS_EVENT_SET(r->events, Event_Action))
                                out_print(res, "Action ");
                        if(IS_EVENT_SET(r->events, Event_Checksum))
                                out_print(res, "Checksum ");
                        if(IS_EVENT_SET(r->events, Event_Connection))
                                out_print(res, "Connection ");
                        if(IS_EVENT_SET(r->events, Event_Content))
                                out_print(res, "Content ");
                        if(IS_EVENT_SET(r->events, Event_Data))
                                out_print(res, "Data ");
                        if(IS_EVENT_SET(r->events, Event_Exec))
                                out_print(res, "Exec ");
                        if(IS_EVENT_SET(r->events, Event_Fsflag))
                                out_print(res, "Fsflags ");
                        if(IS_EVENT_SET(r->events, Event_Gid))
                                out_print(res, "Gid ");
                        if(IS_EVENT_SET(r->events, Event_Icmp))
                                out_print(res, "Icmp ");
                        if(IS_EVENT_SET(r->events, Event_Instance))
                                out_print(res, "Instance ");
                        if(IS_EVENT_SET(r->events, Event_Invalid))
                                out_print(res, "Invalid ");
                        if(IS_EVENT_SET(r->events, Event_Nonexist))
                                out_print(res, "Nonexist ");
                        if(IS_EVENT_SET(r->events, Event_Permission))
                                out_print(res, "Permission ");
                        if(IS_EVENT_SET(r->events, Event_Pid))
                                out_print(res, "PID ");
                        if(IS_EVENT_SET(r->events, Event_PPid))
                                out_print(res, "PPID ");
                        if(IS_EVENT_SET(r->events, Event_Resource))
                                out_print(res, "Resource ");
                        if(IS_EVENT_SET(r->events, Event_Size))
                                out_print(res, "Size ");
                        if(IS_EVENT_SET(r->events, Event_Status))
                                out_print(res, "Status ");
                        if(IS_EVENT_SET(r->events, Event_Timeout))
                                out_print(res, "Timeout ");
                        if(IS_EVENT_SET(r->events, Event_Timestamp))
                                out_print(res, "Timestamp ");
                        if(IS_EVENT_SET(r->events, Event_Uid))
                                out_print(res, "Uid ");
                }
                
                out_print(res, "</td></tr>");
                
                if(r->reminder) {
                        out_print(res,
                                  "<tr><td>Alert reminder</td><td>%u cycles</td></tr>",
                                  r->reminder);
                }
                
        }
        
}


static void print_buttons(HttpRequest req, HttpResponse res, Service_T s) {
        
        if(is_readonly(req)) {
                /*
                 * A read-only REMOTE_USER does not get access to these buttons
                 */
                return;
        }
        
        out_print(res, "<table id='buttons'><tr><td>");
        /* Start program */
        if(s->start)
                out_print(res, 
                          "<td><form method=POST action=%s>"
                          "<input type=hidden value='start' name=action>"
                          "<input type=submit value='Start service'></form></td>", s->name);
        /* Stop program */
        if(s->stop)
                out_print(res, 
                          "<td><form method=POST action=%s>"
                          "<input type=hidden value='stop' name=action>"
                          "<input type=submit value='Stop service'></form></td>", s->name);
        /* Restart program */
        if(s->start && s->stop)
                out_print(res, 
                          "<td><form method=POST action=%s>"
                          "<input type=hidden value='restart' name=action>"
                          "<input type=submit value='Restart service'></form></td>", s->name);
        /* (un)monitor */
        out_print(res, 
                  "<td><form method=POST action=%s>"
                  "<input type=hidden value='%s' name=action>"
                  "<input type=submit value='%s'></form></td></tr></table>",
                  s->name,
                  s->monitor ? "unmonitor" : "monitor",
                  s->monitor ? "Disable monitoring" : "Enable monitoring");
}


static void print_service_rules_port(HttpResponse res, Service_T s) {
        if(s->portlist) {
                char buf[STRLEN];
                Port_T        p;
                EventAction_T a;
                for(p= s->portlist; p; p= p->next) {
                        a= p->action;
                        if(p->family == AF_INET) {
                                out_print(res, "<tr><td>Port</td><td>If failed [%s:%d%s [%s via %s] with timeout %d seconds and retry %d time(s)] %s ", p->hostname, p->port, p->request ? p->request : "", p->protocol->name, Util_portTypeDescription(p), p->timeout, p->retry > 1 ? p->retry : 0, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                out_print(res, "then %s</td></tr>", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                if(p->SSL.certmd5 != NULL)
                                        out_print(res,
                                                  "<tr><td>Server certificate md5 sum</td><td>%s</td></tr>",
                                                  p->SSL.certmd5);
                        } else if(p->family == AF_UNIX) {
                                out_print(res, "<tr><td>Unix Socket</td><td>If failed [%s [%s] with timeout %ds and retry %d time(s)] %s ", p->pathname, p->protocol->name, p->timeout, p->retry > 1 ? p->retry : 0, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                out_print(res, "then %s</td></tr>", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                        }
                }
        }
}


static void print_service_rules_icmp(HttpResponse res, Service_T s) {
        if(s->icmplist) {
                char buf[STRLEN];
                Icmp_T        i;
                EventAction_T a;
                for(i= s->icmplist; i; i= i->next) {
                        a= i->action;
                        out_print(res, "<tr><td>ICMP</td><td>If failed [%s count %d with timeout %d seconds] %s ", icmpnames[i->type], i->count, i->timeout, Util_getEventratio(a->failed, buf, sizeof(buf)));
                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                        out_print(res, "then %s</td></tr>", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                }
        }
}


static void print_service_rules_perm(HttpResponse res, Service_T s) {
        if(s->perm) {
                char buf[STRLEN];
                EventAction_T a= s->perm->action;
                out_print(res, "<tr><td>Associated permission</td><td>If failed %o %s ", s->perm->perm, Util_getEventratio(a->failed, buf, sizeof(buf)));
                out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                out_print(res, "then %s</td></tr>", Util_describeAction(a->succeeded, buf, sizeof(buf)));
        }
}


static void print_service_rules_uid(HttpResponse res, Service_T s) {
        if(s->uid) {
                char buf[STRLEN];
                EventAction_T a= s->uid->action;
                out_print(res, "<tr><td>Associated UID</td><td>If failed %d %s ", (int)s->uid->uid, Util_getEventratio(a->failed, buf, sizeof(buf)));
                out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                out_print(res, "then %s</td></tr>", Util_describeAction(a->succeeded, buf, sizeof(buf)));
        }
}


static void print_service_rules_gid(HttpResponse res, Service_T s) {
        if(s->gid) {
                char buf[STRLEN];
                EventAction_T a= s->gid->action;
                out_print(res, "<tr><td>Associated GID</td><td>If failed %d %s ", (int)s->gid->gid, Util_getEventratio(a->failed, buf, sizeof(buf)));
                out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                out_print(res, "then %s</td></tr>", Util_describeAction(a->succeeded, buf, sizeof(buf)));
        }
}


static void print_service_rules_timestamp(HttpResponse res, Service_T s) {
        if(s->timestamplist) {
                char buf[STRLEN];
                Timestamp_T   t;
                EventAction_T a;
                for(t= s->timestamplist; t; t= t->next) {
                        a= t->action;
                        out_print(res, "<tr><td>Associated timestamp</td><td>");
                        if(t->test_changes) {
                                out_print(res, "If changed %s ", Util_getEventratio(a->failed, buf, sizeof(buf)));
                                out_print(res, "then %s", Util_describeAction(a->failed, buf, sizeof(buf)));
                        } else {
                                out_print(res, "If %s %d second(s) %s ", operatornames[t->operator], t->time, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                        }
                        out_print(res, "</td></tr>");
                }
        }
}


static void print_service_rules_filesystem(HttpResponse res, Service_T s) {
        char buf[STRLEN];
        
        if(s->type == TYPE_FILESYSTEM) {
                out_print(res, "<tr><td>Filesystem flags</td><td>If changed %s ", Util_getEventratio(s->action_FSFLAG->failed, buf, sizeof(buf)));
                out_print(res, "then %s</td></tr>", Util_describeAction(s->action_FSFLAG->failed, buf, sizeof(buf)));
        }
        
        if(s->filesystemlist) {
                Filesystem_T  dl;
                EventAction_T a;
                
                for(dl= s->filesystemlist; dl; dl= dl->next) {
                        
                        a= dl->action;
                        
                        if(dl->resource == RESOURCE_ID_INODE) {
                                out_print(res, "<tr><td>Inodes usage limit</td><td>");
                                if(dl->limit_absolute > -1) {
                                        out_print(res, "If %s %ld %s ", operatornames[dl->operator], dl->limit_absolute, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                } else {
                                        out_print(res, "If %s %.1f%% %s ", operatornames[dl->operator], dl->limit_percent / 10., Util_getEventratio(a->failed, buf, sizeof(buf)));
                                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                }
                                out_print(res, "</td></tr>");
                        } else if(dl->resource == RESOURCE_ID_SPACE) {
                                out_print(res, "<tr><td>Space usage limit</td><td>");
                                if(dl->limit_absolute > -1) {
                                        out_print(res, "If %s %ld blocks %s ", operatornames[dl->operator], dl->limit_absolute, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                } else {
                                        out_print(res, "If %s %.1f%% %s ", operatornames[dl->operator], dl->limit_percent / 10., Util_getEventratio(a->failed, buf, sizeof(buf)));
                                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                }
                                out_print(res, "</td></tr>");
                        }
                }
        }
}


static void print_service_rules_size(HttpResponse res, Service_T s) {
        if(s->sizelist) {
                char buf[STRLEN];
                Size_T        sl;
                EventAction_T a;
                
                for(sl= s->sizelist; sl; sl= sl->next) {
                        a= sl->action;
                        out_print(res, "<tr><td>Associated size</td><td>");
                        if(sl->test_changes) {
                                out_print(res, "If changed %s ", Util_getEventratio(a->failed, buf, sizeof(buf)));
                                out_print(res, "then %s", Util_describeAction(a->failed, buf, sizeof(buf)));
                        } else {
                                out_print(res, "If %s %llu byte(s) %s ", operatornames[sl->operator], sl->size, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                        }
                        out_print(res, "</td></tr>");
                }
        }
}

static void print_service_rules_match(HttpResponse res, Service_T s) {
        if(s->matchlist && s->type != TYPE_PROCESS) {
                char buf[STRLEN];
                Match_T       ml;
                EventAction_T a;
                for(ml= s->matchlist; ml; ml= ml->next) {
                        a= ml->action;
                        out_print(res, "<tr><td>Associated regex</td><td>If If %smatch \"%s\" %s ", ml->not ? "not " : "", ml->match_string, Util_getEventratio(a->failed, buf, sizeof(buf)));
                        out_print(res, "then %s</td></tr>", Util_describeAction(a->failed, buf, sizeof(buf)));
                }
        }
}


static void print_service_rules_checksum(HttpResponse res, Service_T s) {
        if(s->checksum) {
                char buf[STRLEN];
                Checksum_T     cs= s->checksum;
                EventAction_T  a= cs->action;
                out_print(res, "<tr><td>Associated regex</td><td>");
                if(cs->test_changes) {
                        out_print(res, "If changed %s %s ", checksumnames[cs->type], Util_getEventratio(a->failed, buf, sizeof(buf)));
                        out_print(res, "then %s", Util_describeAction(a->failed, buf, sizeof(buf)));
                } else {
                        out_print(res, "If failed %s(%s) %s ", cs->hash, checksumnames[cs->type], Util_getEventratio(a->failed, buf, sizeof(buf)));
                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                }
                out_print(res, "</td></tr>");
        }
}


static void print_service_rules_process(HttpResponse res, Service_T s) {
        if(s->type == TYPE_PROCESS) {
                char buf[STRLEN];
                out_print(res, "<tr><td>Pid</td><td>If changed %s ", Util_getEventratio(s->action_PID->failed, buf, sizeof(buf)));
                out_print(res, "then %s</td></tr>", Util_describeAction(s->action_PID->failed, buf, sizeof(buf)));
                out_print(res, "<tr><td>Ppid</td><td>If changed %s ", Util_getEventratio(s->action_PPID->failed, buf, sizeof(buf)));
                out_print(res, "then %s</td></tr>", Util_describeAction(s->action_PPID->failed, buf, sizeof(buf)));
        }
}


static void print_service_rules_program(HttpResponse res, Service_T s) {
        if(s->type == TYPE_PROGRAM) {
                char buf[STRLEN];
                Program_T p = s->program;
                EventAction_T a= p->action;
                out_print(res, "<tr><td>Test Exit value</td><td>if exit value %s %d within %d seconds ", operatorshortnames[p->operator], p->return_value, p->timeout);
                out_print(res, "then %s</td></tr>", Util_describeAction(a->failed, buf, sizeof(buf)));
        }
}


static void print_service_rules_resource(HttpResponse res, Service_T s) {
        if(s->resourcelist) {
                char buf[STRLEN];
                Resource_T    q;
                EventAction_T a;
                
                for (q= s->resourcelist; q; q= q->next) {
                        a= q->action;
                        out_print(res, "<tr><td>");
                        switch (q->resource_id) {
                                case RESOURCE_ID_CPU_PERCENT: 
                                        out_print(res, "CPU usage limit");
                                        break;
                                        
                                case RESOURCE_ID_TOTAL_CPU_PERCENT: 
                                        out_print(res, "CPU usage limit (incl. children)");
                                        break;
                                        
                                case RESOURCE_ID_CPUUSER: 
                                        out_print(res, "CPU user limit");
                                        break;
                                        
                                case RESOURCE_ID_CPUSYSTEM: 
                                        out_print(res, "CPU system limit");
                                        break;
                                        
                                case RESOURCE_ID_CPUWAIT: 
                                        out_print(res, "CPU wait limit");
                                        break;
                                        
                                case RESOURCE_ID_MEM_PERCENT: 
                                        out_print(res, "Memory usage limit");
                                        break;
                                        
                                case RESOURCE_ID_MEM_KBYTE: 
                                        out_print(res, "Memory amount limit");
                                        break;
                                        
                                case RESOURCE_ID_SWAP_PERCENT: 
                                        out_print(res, "Swap usage limit");
                                        break;
                                        
                                case RESOURCE_ID_SWAP_KBYTE: 
                                        out_print(res, "Swap amount limit");
                                        break;
                                        
                                case RESOURCE_ID_LOAD1: 
                                        out_print(res, "Load average (1min)");
                                        break;
                                        
                                case RESOURCE_ID_LOAD5: 
                                        out_print(res, "Load average (5min)");
                                        break;
                                        
                                case RESOURCE_ID_LOAD15: 
                                        out_print(res, "Load average (15min)");
                                        break;
                                        
                                case RESOURCE_ID_CHILDREN:
                                        out_print(res, "Children");
                                        break;
                                        
                                case RESOURCE_ID_TOTAL_MEM_KBYTE:
                                        out_print(res, "Memory amount limit (incl. children)");
                                        break;
                                        
                                case RESOURCE_ID_TOTAL_MEM_PERCENT:
                                        out_print(res, "Memory usage limit (incl. children)");
                                        break;
                        }
                        out_print(res, "</td><td>");
                        switch (q->resource_id) {
                                case RESOURCE_ID_CPU_PERCENT: 
                                case RESOURCE_ID_TOTAL_CPU_PERCENT:
                                case RESOURCE_ID_TOTAL_MEM_PERCENT:
                                case RESOURCE_ID_CPUUSER:
                                case RESOURCE_ID_CPUSYSTEM:
                                case RESOURCE_ID_CPUWAIT:
                                case RESOURCE_ID_MEM_PERCENT:
                                case RESOURCE_ID_SWAP_PERCENT:
                                        out_print(res, "If %s %.1f%% %s ", operatornames[q->operator], q->limit / 10., Util_getEventratio(a->failed, buf, sizeof(buf)));
                                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                        break;
                                        
                                case RESOURCE_ID_MEM_KBYTE:
                                case RESOURCE_ID_SWAP_KBYTE:
                                        out_print(res, "If %s %ldkB %s ", operatornames[q->operator], q->limit, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                        break;
                                        
                                case RESOURCE_ID_LOAD1:
                                case RESOURCE_ID_LOAD5:
                                case RESOURCE_ID_LOAD15:
                                        out_print(res, "If %s %.1f %s ", operatornames[q->operator], q->limit / 10.0, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                        break;
                                        
                                case RESOURCE_ID_CHILDREN:
                                case RESOURCE_ID_TOTAL_MEM_KBYTE:
                                        out_print(res, "If %s %ld %s ", operatornames[q->operator], q->limit, Util_getEventratio(a->failed, buf, sizeof(buf)));
                                        out_print(res, "then %s ", Util_describeAction(a->failed, buf, sizeof(buf)));
                                        out_print(res, "else if succeeded %s ", Util_getEventratio(a->succeeded, buf, sizeof(buf)));
                                        out_print(res, "then %s", Util_describeAction(a->succeeded, buf, sizeof(buf)));
                                        break;
                        }
                        out_print(res, "</td></tr>");
                }
        }
}


static void print_service_params_port(HttpResponse res, Service_T s) {
        
        if((s->type == TYPE_HOST ||
            s->type == TYPE_PROCESS) &&
           s-> portlist) {
                
                Port_T p;
                
                if(!Util_hasServiceStatus(s)) {
                        
                        for(p= s->portlist; p; p= p->next)
                                if(p->family == AF_INET) {
                                        out_print(res, "<tr><td>Port Response time</td><td>-</td></tr>");
                                } else if(p->family == AF_UNIX) {
                                        out_print(res, "<tr><td>Unix Socket Response time</td><td>-</td></tr>");
                                }
                        
                } else {
                        
                        for(p= s->portlist; p; p= p->next) {
                                if(p->family == AF_INET) {
                                        if(!p->is_available) {
                                                out_print(res,
                                                          "<tr><td>Port Response time</td>"
                                                          "<td class='red-text'>connection failed to %s:%d%s [%s via %s]</td>"
                                                          "</tr>",
                                                          p->hostname, p->port, p->request?p->request:"",
                                                          p->protocol->name, Util_portTypeDescription(p));
                                        } else {
                                                out_print(res,
                                                          "<tr><td>Port Response time</td>"
                                                          "<td>%.3fs to %s:%d%s [%s via %s]</td></tr>",
                                                          p->response, p->hostname, p->port, p->request?p->request:"",
                                                          p->protocol->name, Util_portTypeDescription(p));
                                        }
                                } else if(p->family == AF_UNIX) {
                                        if(!p->is_available) {
                                                out_print(res,
                                                          "<tr><td>Unix Socket Response time</td>"
                                                          "<td class='red-text'>connection failed to %s [%s]</td>"
                                                          "</tr>",
                                                          p->pathname, p->protocol->name);
                                        } else {
                                                out_print(res,
                                                          "<tr><td>Unix Socket Response time</td>"
                                                          "<td>%.3fs to %s [%s]</td></tr>",
                                                          p->response, p->pathname, p->protocol->name);
                                        }
                                }
                        }
                }
        }
}


static void print_service_params_icmp(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_HOST && s->icmplist) {
                
                Icmp_T i;
                
                if(!Util_hasServiceStatus(s)) {
                        
                        for(i= s->icmplist; i; i= i->next)
                                out_print(res, "<tr><td>ICMP Response time</td><td>-</td></tr>");
                        
                } else {
                        
                        for(i= s->icmplist; i; i= i->next) {
                                if(!i->is_available) {
                                        out_print(res, "<tr><td>ICMP Response time</td><td class='red-text'>connection failed [%s]</td></tr>", icmpnames[i->type]);
                                } else {
                                        out_print(res, "<tr><td>ICMP Response time</td><td>%.3fs [%s]</td></tr>", i->response, icmpnames[i->type]);
                                }
                        }
                }
        }
}


static void print_service_params_perm(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_FILE ||
           s->type == TYPE_FIFO ||
           s->type == TYPE_DIRECTORY ||
           s->type == TYPE_FILESYSTEM) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res, "<tr><td>Permission</td><td>-</td></tr>");
                        
                } else {
                        
                        out_print(res,
                                  "<tr><td>Permission</td><td class='%s'>%o</td></tr>",
                                  (s->error & Event_Permission)?"red-text":"",
                                  s->inf->st_mode & 07777);
                        
                }
        }
}


static void print_service_params_uid(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_FILE ||
           s->type == TYPE_FIFO ||
           s->type == TYPE_DIRECTORY ||
           s->type == TYPE_FILESYSTEM) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res, "<tr><td>UID</td><td>-</td></tr>");
                        
                } else {
                        
                        out_print(res,
                                  "<tr><td>UID</td><td class='%s'>%d</td></tr>",
                                  (s->error & Event_Uid)?"red-text":"",
                                  (int)s->inf->st_uid);
                        
                }
        }
}


static void print_service_params_gid(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_FILE ||
           s->type == TYPE_FIFO ||
           s->type == TYPE_DIRECTORY ||
           s->type == TYPE_FILESYSTEM) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res, "<tr><td>GID</td><td>-</td></tr>");
                        
                } else {
                        
                        out_print(res,
                                  "<tr><td>GID</td><td class='%s'>%d</td></tr>",
                                  (s->error & Event_Gid)?"red-text":"",
                                  (int)s->inf->st_gid);
                        
                }
        }
}


static void print_service_params_timestamp(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_FILE ||
           s->type == TYPE_FIFO ||
           s->type == TYPE_DIRECTORY) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res, "<tr><td>Timestamp</td><td>-</td></tr>");
                        
                } else {
                        char t[32];
                        out_print(res,
                                  "<tr><td>Timestamp</td><td class='%s'>%s</td></tr>",
                                  (s->error & Event_Timestamp)?"red-text":"", Time_string(s->inf->timestamp, t));
                }
        }
}


static void print_service_params_filesystem(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_FILESYSTEM) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<tr><td>Filesystem flags</td><td>-</td></tr>");
                        out_print(res,
                                  "<tr><td>Blocks total</td><td>-</td></tr>");
                        out_print(res,
                                  "<tr><td>Blocks free for non superuser</td><td>-</td></tr>");
                        out_print(res,
                                  "<tr><td>Blocks free total</td><td>-</td></tr>");
                        out_print(res,
                                  "<tr><td>Block size</td><td>-</td></tr>");
                        out_print(res,
                                  "<tr><td>Inodes total</td><td>-</td></tr>");
                        out_print(res,
                                  "<tr><td>Inodes free</td><td>-</td></tr>");
                        
                } else {
                        
                        out_print(res,
                                  "<tr><td>Filesystem flags</td><td>%#lx</td></tr>",
                                  s->inf->priv.filesystem.flags);
                        out_print(res,
                                  "<tr><td>Blocks total</td><td>%ld [%.1f MB]</td></tr>",
                                  s->inf->priv.filesystem.f_blocks,
                                  s->inf->priv.filesystem.f_bsize > 0 ? ((float) s->inf->priv.filesystem.f_blocks/1048576*s->inf->priv.filesystem.f_bsize) : 0);
                        out_print(res,
                                  "<tr><td>Blocks free for non superuser</td>"
                                  "<td>%ld [%.1f MB] [%.1f%%]</td></tr>",
                                  s->inf->priv.filesystem.f_blocksfree,
                                  s->inf->priv.filesystem.f_bsize > 0 ? ((float)s->inf->priv.filesystem.f_blocksfree / (float)1048576 * (float)s->inf->priv.filesystem.f_bsize) : 0,
                                  s->inf->priv.filesystem.f_blocks > 0 ? ((float)100 * (float)s->inf->priv.filesystem.f_blocksfree / (float)s->inf->priv.filesystem.f_blocks) : 0);
                        out_print(res,
                                  "<tr><td>Blocks free total</td>"
                                  "<td class='%s'>%ld [%.1f MB] [%.1f%%]</td></tr>",
                                  (s->error & Event_Resource)?"red-text":"",
                                  s->inf->priv.filesystem.f_blocksfreetotal,
                                  s->inf->priv.filesystem.f_bsize > 0 ? ((float)s->inf->priv.filesystem.f_blocksfreetotal / (float)1048576 * (float)s->inf->priv.filesystem.f_bsize) : 0,
                                  s->inf->priv.filesystem.f_blocks > 0 ? ((float)100 * (float)s->inf->priv.filesystem.f_blocksfreetotal / (float)s->inf->priv.filesystem.f_blocks) : 0);
                        out_print(res,
                                  "<tr><td>Block size</td><td>%ld B</td></tr>", s->inf->priv.filesystem.f_bsize);
                        
                        if(s->inf->priv.filesystem.f_files > 0) {
                                
                                out_print(res,
                                          "<tr><td>Inodes total</td><td>%ld</td></tr>", s->inf->priv.filesystem.f_files);
                                out_print(res,
                                          "<tr><td>Inodes free</td><td class='%s'>%ld [%.1f%%]</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          s->inf->priv.filesystem.f_filesfree,
                                          (float)100 * (float)s->inf->priv.filesystem.f_filesfree / (float)s->inf->priv.filesystem.f_files);
                                
                        }
                }
        }
}


static void print_service_params_size(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_FILE) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<tr><td>Size</td><td>-</td></tr>");
                        
                } else {
                        
                        out_print(res,
                                  "<tr><td>Size</td><td class='%s'>%llu B</td></tr>",
                                  (s->error & Event_Size)?"red-text":"",
                                  (unsigned long long) s->inf->priv.file.st_size);
                        
                }
        }
}

static void print_service_params_match(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_FILE) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<tr><td>Match regex</td><td>-</td></tr>");
                        
                } else {
                        
                        out_print(res,
                                  "<tr><td>Match regex</td><td class='%s'>%s</td></tr>",
                                  (s->error & Event_Content)?"red-text":"",
                                  (s->error & Event_Content)?"yes":"no");
                }
        }
}


static void print_service_params_checksum(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_FILE && s->checksum) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res, "<tr><td>Checksum</td><td>-</td></tr>");
                        
                } else {
                        
                        out_print(res,
                                  "<tr><td>Checksum</td><td class='%s'>%s(%s)</td></tr>",
                                  (s->error & Event_Checksum)?"red-text":"", s->inf->priv.file.cs_sum,
                                  checksumnames[s->checksum->type]);
                        
                }
        }
}


static void print_service_params_process(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_PROCESS) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<tr><td>Process id </td><td>-</td></tr>"
                                  "<tr><td>Parent process id </td><td>-</td></tr>"
                                  "<tr><td>Process uptime</td><td>-</td></tr>");
                        
                } else {
                        
                        char *uptime;
                        
                        out_print(res,
                                  "<tr><td>Process id </td><td>%d</td></tr>",
                                  s->inf->priv.process.pid > 0 ? s->inf->priv.process.pid : 0);
                        out_print(res,
                                  "<tr><td>Parent process id </td><td>%d</td></tr>",
                                  s->inf->priv.process.ppid > 0 ? s->inf->priv.process.ppid : 0);
                        
                        uptime= Util_getUptime(s->inf->priv.process.uptime, "&nbsp;");
                        out_print(res,
                                  "<tr><td>Process uptime</td><td>%s</td></tr>",
                                  uptime);
                        FREE(uptime);
                }
        }
}


static void print_service_params_resource(HttpResponse res, Service_T s) {
        
        if(Run.doprocess && (s->type == TYPE_PROCESS || s->type == TYPE_SYSTEM) ) {
                
                if(!Util_hasServiceStatus(s)) {
                        if(s->type == TYPE_PROCESS) {
                                out_print(res,
                                          "<tr><td>CPU usage</td><td>-</td></tr>"
                                          "<tr><td>Memory usage</td><td>-</td></tr>"
                                          "<tr><td>Children</td><td>-</td></tr>"
                                          "<tr><td>Total CPU usage (incl. children)</td><td>-</td></tr>"
                                          "<tr><td>Total memory usage (incl. children)</td><td>-</td></tr>");
                        } else if(s->type == TYPE_SYSTEM) {
                                out_print(res,
                                          "<tr><td>Load average</td><td>-</td></tr>"
                                          "<tr><td>CPU usage</td><td>-</td></tr>"
                                          "<tr><td>Memory usage</td><td>-</td></tr>");
                        }
                } else {
                        
                        if(s->type == TYPE_PROCESS) {
                                out_print(res,
                                          "<tr><td>Children</td><td class='%s'>%d</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          s->inf->priv.process.children);
                                out_print(res,
                                          "<tr><td>CPU usage</td><td class='%s'>%.1f%%  &nbsp;&nbsp;(Usage / Number of CPUs)</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          s->inf->priv.process.cpu_percent/10.0);
                                out_print(res,
                                          "<tr><td>Total CPU usage (incl. children)</td><td class='%s'>%.1f%%</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          s->inf->priv.process.total_cpu_percent/10.0);
                                out_print(res,
                                          "<tr><td>Memory usage</td><td class='%s'>%.1f%% [%ldkB]</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          s->inf->priv.process.mem_percent/10.0, s->inf->priv.process.mem_kbyte);
                                out_print(res,
                                          "<tr><td>Total memory usage (incl. children)</td><td class='%s'>%.1f%% [%ldkB]</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          s->inf->priv.process.total_mem_percent/10.0, s->inf->priv.process.total_mem_kbyte);
                        } else if(s->type == TYPE_SYSTEM) {
                                out_print(res,
                                          "<tr><td>Load average</td><td class='%s'>[%.2f] [%.2f] [%.2f]</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          systeminfo.loadavg[0],
                                          systeminfo.loadavg[1],
                                          systeminfo.loadavg[2]);
                                out_print(res,
                                          "<tr><td>CPU usage</td><td class='%s'>%.1f%%us %.1f%%sy"
#ifdef HAVE_CPU_WAIT
                                          " %.1f%%wa"
#endif
                                          "%s",
                                          (s->error & Event_Resource)?"red-text":"",
                                          systeminfo.total_cpu_user_percent > 0 ? systeminfo.total_cpu_user_percent/10. : 0,
                                          systeminfo.total_cpu_syst_percent > 0 ? systeminfo.total_cpu_syst_percent/10. : 0,
#ifdef HAVE_CPU_WAIT
                                          systeminfo.total_cpu_wait_percent > 0 ? systeminfo.total_cpu_wait_percent/10. : 0,
#endif
                                          "</td></tr>");
                                out_print(res,
                                          "<tr><td>Memory usage</td><td class='%s'>%ld kB [%.1f%%]</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          systeminfo.total_mem_kbyte,
                                          systeminfo.total_mem_percent/10.);
                                out_print(res,
                                          "<tr><td>Swap usage</td><td class='%s'>%ld kB [%.1f%%]</td></tr>",
                                          (s->error & Event_Resource)?"red-text":"",
                                          systeminfo.total_swap_kbyte,
                                          systeminfo.total_swap_percent/10.);
                        }
                }
        }
}


static void print_service_params_program(HttpResponse res, Service_T s) {
        
        if(s->type == TYPE_PROGRAM) {
                
                if(!Util_hasServiceStatus(s)) {
                        
                        out_print(res,
                                  "<tr><td>Last started</td><td>-</td></tr>"
                                  "<tr><td>Last Exit value</td><td>-</td></tr>");
                        
                } else {
                        if (s->program->started) {
                                char t[32];
                                out_print(res, "<tr><td>Last started</td><td>%s</td></tr>", Time_string(s->program->started, t));
                                out_print(res, "<tr><td>Last Exit value</td><td>%d</td></tr>", s->program->exitStatus);
                        } else {
                                out_print(res, "<tr><td>Last started</td><td>Not yet started</td></tr>");
                                out_print(res, "<tr><td>Last Exit value</td><td>N/A</td></tr>");
                        }
                }
        }
}


static int is_readonly(HttpRequest req) {
        
        if(req->remote_user) {
                Auth_T user_creds = Util_getUserCredentials(req->remote_user);
                return ( user_creds?user_creds->is_readonly:TRUE );
        }
        
        return FALSE;
        
}


/* ----------------------------------------------------------- Status output */


/* Print status in the given format. Text status is default. */
static void print_status(HttpRequest req, HttpResponse res, int version)
{
        Service_T s;
        short level = LEVEL_FULL;
        const char *stringFormat = get_parameter(req, "format");
        const char *stringLevel = get_parameter(req, "level");
        
        if(stringLevel && Util_startsWith(stringLevel, LEVEL_NAME_SUMMARY))
        {
                level = LEVEL_SUMMARY;
        }
        
        if(stringFormat && Util_startsWith(stringFormat, "xml"))
        {
                char *D = status_xml(NULL, level, version, socket_get_local_host(req->S));
                out_print(res, "%s", D);
                FREE(D);
                set_content_type(res, "text/xml");
        }
        else
        {
                char *uptime = Util_getUptime(Util_getProcessUptime(Run.pidfile), " ");
                out_print(res, "The Monit daemon %s uptime: %s\n\n", VERSION, uptime);
                FREE(uptime);
                
                for(s= servicelist_conf; s; s= s->next_conf)
                {
                        status_service_txt(s, res, level);
                }
                set_content_type(res, "text/plain");
        }
}


static void status_service_txt(Service_T s, HttpResponse res, short level) {
        char buf[STRLEN];
        if(level == LEVEL_SUMMARY)
        {
                char prefix[STRLEN];
                snprintf(prefix, STRLEN, "%s '%s'", servicetypes[s->type], s->name);
                out_print(res, "%-35s %s\n", prefix, get_service_status(s, buf, sizeof(buf)));
        }
        else
        {
                out_print(res,
                          "%s '%s'\n"
                          "  %-33s %s\n",
                          servicetypes[s->type], s->name,
                          "status", get_service_status(s, buf, sizeof(buf)));
                out_print(res,
                          "  %-33s %s\n",
                          "monitoring status", get_monitoring_status(s, buf, sizeof(buf)));
                
                if(Util_hasServiceStatus(s)) {
                        if(s->type == TYPE_FILE ||
                           s->type == TYPE_FIFO || 
                           s->type == TYPE_DIRECTORY || 
                           s->type == TYPE_FILESYSTEM) {
                                out_print(res,
                                          "  %-33s %o\n"
                                          "  %-33s %d\n"
                                          "  %-33s %d\n",
                                          "permission", s->inf->st_mode & 07777,
                                          "uid", (int)s->inf->st_uid,
                                          "gid", (int)s->inf->st_gid);
                        }
                        if(s->type == TYPE_FILE ||
                           s->type == TYPE_FIFO || 
                           s->type == TYPE_DIRECTORY) {
                                out_print(res,
                                          "  %-33s %s\n",
                                          "timestamp", Time_string(s->inf->timestamp, buf));
                        }
                        if(s->type == TYPE_FILE) {
                                out_print(res,
                                          "  %-33s %llu B\n",
                                          "size", (unsigned long long) s->inf->priv.file.st_size);
                                if(s->checksum) {
                                        out_print(res,
                                                  "  %-33s %s (%s)\n",
                                                  "checksum", s->inf->priv.file.cs_sum, 
                                                  checksumnames[s->checksum->type]);
                                }
                        }
                        if(s->type == TYPE_FILESYSTEM) {
                                out_print(res,
                                          "  %-33s %#lx\n"
                                          "  %-33s %ld B\n"
                                          "  %-33s %ld [%.1f MB]\n"
                                          "  %-33s %ld [%.1f MB] [%.1f%%]\n"
                                          "  %-33s %ld [%.1f MB] [%.1f%%]\n",
                                          "filesystem flags",
                                          s->inf->priv.filesystem.flags,
                                          "block size",
                                          s->inf->priv.filesystem.f_bsize,
                                          "blocks total",
                                          s->inf->priv.filesystem.f_blocks,
                                          s->inf->priv.filesystem.f_bsize > 0 ? ((float)s->inf->priv.filesystem.f_blocks / (float)1048576* (float)s->inf->priv.filesystem.f_bsize) : 0,
                                          "blocks free for non superuser",
                                          s->inf->priv.filesystem.f_blocksfree,
                                          s->inf->priv.filesystem.f_bsize > 0 ? ((float)s->inf->priv.filesystem.f_blocksfree / (float)1048576* (float)s->inf->priv.filesystem.f_bsize) : 0,
                                          s->inf->priv.filesystem.f_blocks > 0 ? ((float)100 * (float)s->inf->priv.filesystem.f_blocksfree / (float)s->inf->priv.filesystem.f_blocks) : 0,
                                          "blocks free total",
                                          s->inf->priv.filesystem.f_blocksfreetotal,
                                          s->inf->priv.filesystem.f_bsize > 0 ? ((float)s->inf->priv.filesystem.f_blocksfreetotal/(float)1048576* (float)s->inf->priv.filesystem.f_bsize) : 0,
                                          s->inf->priv.filesystem.f_blocks > 0 ? ((float)100 * (float)s->inf->priv.filesystem.f_blocksfreetotal / (float)s->inf->priv.filesystem.f_blocks) : 0);
                                if(s->inf->priv.filesystem.f_files > 0) {
                                        out_print(res,
                                                  "  %-33s %ld\n"
                                                  "  %-33s %ld [%.1f%%]\n",
                                                  "inodes total",
                                                  s->inf->priv.filesystem.f_files,
                                                  "inodes free",
                                                  s->inf->priv.filesystem.f_filesfree,
                                                  ((float)100*(float)s->inf->priv.filesystem.f_filesfree/ (float)s->inf->priv.filesystem.f_files));
                                }
                        }
                        if(s->type == TYPE_PROCESS) {
                                char *uptime= Util_getUptime(s->inf->priv.process.uptime, " ");
                                out_print(res,
                                          "  %-33s %d\n"
                                          "  %-33s %d\n"
                                          "  %-33s %s\n",
                                          "pid", s->inf->priv.process.pid > 0 ? s->inf->priv.process.pid : 0,
                                          "parent pid", s->inf->priv.process.ppid > 0 ? s->inf->priv.process.ppid : 0,
                                          "uptime", uptime);
                                FREE(uptime);
                                if(Run.doprocess)        {
                                        out_print(res,
                                                  "  %-33s %d\n"
                                                  "  %-33s %ld\n"
                                                  "  %-33s %ld\n"
                                                  "  %-33s %.1f%%\n"
                                                  "  %-33s %.1f%%\n"
                                                  "  %-33s %.1f%%\n"
                                                  "  %-33s %.1f%%\n",
                                                  "children", s->inf->priv.process.children,
                                                  "memory kilobytes", s->inf->priv.process.mem_kbyte,
                                                  "memory kilobytes total", s->inf->priv.process.total_mem_kbyte,
                                                  "memory percent", s->inf->priv.process.mem_percent/10.0,
                                                  "memory percent total", s->inf->priv.process.total_mem_percent/10.0,
                                                  "cpu percent", s->inf->priv.process.cpu_percent/10.0,
                                                  "cpu percent total", s->inf->priv.process.total_cpu_percent/10.0);
                                }
                        }
                        if(s->type == TYPE_HOST && s->icmplist) {
                                Icmp_T i;
                                for(i= s->icmplist; i; i= i->next) {
                                        out_print(res,
                                                  "  %-33s %.3fs [%s]\n",
                                                  "icmp response time", i->is_available ? i->response : 0.,
                                                  icmpnames[i->type]);
                                }
                        }
                        if((s->type == TYPE_HOST || s->type == TYPE_PROCESS) && s-> portlist) {
                                Port_T p;
                                for(p= s->portlist; p; p= p->next) {
                                        if(p->family == AF_INET) {
                                                out_print(res,
                                                          "  %-33s %.3fs to %s:%d%s [%s via %s]\n",
                                                          "port response time", p->is_available ? p->response : 0., 
                                                          p->hostname,
                                                          p->port, p->request?p->request:"", p->protocol->name,
                                                          Util_portTypeDescription(p));
                                        } else if(p->family == AF_UNIX) {
                                                out_print(res,
                                                          "  %-33s %.3fs to %s [%s]\n",
                                                          "unix socket response time", p->is_available ? p->response : 0.,
                                                          p->pathname, p->protocol->name);
                                        }
                                }
                        }
                        if(s->type == TYPE_SYSTEM && Run.doprocess) {
                                out_print(res,
                                          "  %-33s [%.2f] [%.2f] [%.2f]\n"
                                          "  %-33s %.1f%%us %.1f%%sy"
#ifdef HAVE_CPU_WAIT
                                          " %.1f%%wa"
#endif
                                          "\n"
                                          "  %-33s %ld kB [%.1f%%]\n"
                                          "  %-33s %ld kB [%.1f%%]\n",
                                          "load average",
                                          systeminfo.loadavg[0],
                                          systeminfo.loadavg[1],
                                          systeminfo.loadavg[2],
                                          "cpu",
                                          systeminfo.total_cpu_user_percent > 0 ? systeminfo.total_cpu_user_percent/10. : 0,
                                          systeminfo.total_cpu_syst_percent > 0 ? systeminfo.total_cpu_syst_percent/10. : 0,
#ifdef HAVE_CPU_WAIT
                                          systeminfo.total_cpu_wait_percent > 0 ? systeminfo.total_cpu_wait_percent/10. : 0,
#endif
                                          "memory usage",
                                          systeminfo.total_mem_kbyte,
                                          systeminfo.total_mem_percent/10.,
                                          "swap usage",
                                          systeminfo.total_swap_kbyte,
                                          systeminfo.total_swap_percent/10.);
                        }
                        if(s->type == TYPE_PROGRAM) {
                                if (s->program->started) {
                                        char t[32];
                                        out_print(res,
                                                  "  %-33s %s\n"
                                                  "  %-33s %d\n",
                                                  "last started", Time_string(s->program->started, t),
                                                  "last exit value", s->program->exitStatus);
                                } else
                                        out_print(res,
                                                  "  %-33s\n",
                                                  "not yet started");
                        }
                }
                out_print(res, "  %-33s %s\n\n", "data collected", Time_string(s->collected.tv_sec, buf));
        }
}


static char *get_monitoring_status(Service_T s, char *buf, int buflen) {
        ASSERT(s);
        ASSERT(buf);
        if (s->monitor == MONITOR_NOT)
                snprintf(buf, buflen, "Not monitored");
        else if (s->monitor & MONITOR_WAITING)
                snprintf(buf, buflen, "Waiting");
        else if (s->monitor & MONITOR_INIT)
                snprintf(buf, buflen, "Initializing");
        else if (s->monitor & MONITOR_YES)
                snprintf(buf, buflen, "Monitored");
        return buf;
}


static char *get_service_status(Service_T s, char *buf, int buflen) {
        EventTable_T *et = Event_Table;
        ASSERT(s);
        ASSERT(buf);
        if(s->monitor == MONITOR_NOT || s->monitor & MONITOR_INIT || s->monitor & MONITOR_WAITING) {
                get_monitoring_status(s, buf, buflen);
        } else if (s->error == 0) {
                snprintf(buf, buflen, "%s", statusnames[s->type]);
        } else {
                // In the case that the service has actualy some failure, error will be non zero. We will check the bitmap and print the description of the first error found
                while((*et).id) {
                        if(s->error & (*et).id) {
                                snprintf(buf, buflen, "%s", (s->error_hint & (*et).id) ? (*et).description_changed : (*et).description_failed);
                                break;
                        }
                        et++;
                }
        }
        if(s->doaction)
                snprintf(buf + strlen(buf), buflen - strlen(buf), " - %s pending", actionnames[s->doaction]);

        return buf;
}


static char *get_service_status_html(Service_T s, char *buf, int buflen) {
        ASSERT(s);
        ASSERT(buf);
        snprintf(buf, buflen, "<span class='%s-text'>", (s->monitor == MONITOR_NOT || s->monitor & MONITOR_INIT || s->monitor & MONITOR_WAITING) ? "gray" : ((! s->error) ? "green" : "red"));
        get_service_status(s, buf + strlen(buf), buflen - (int)strlen(buf));
        snprintf(buf + strlen(buf), buflen - strlen(buf), "</span>");
        return buf;
}
