#include "license_pbs.h" /* See here for the software license */
#include <stdlib.h>
#include <stdio.h> /* sprintf */

#include "pbs_job.h" /* all_jobs, job */
#include "server.h" /* server */
#include "array.h" /* job_array */
#include "batch_request.h" /* batch_request */
#include "attribute.h" /* pbs_attribute */
#include "work_task.h" /* work_task, all_tasks */
#include "queue.h" /* pbs_queue */
#include "node_func.h" /* node_info */


const char *msg_deletejob = "Job deleted";
struct all_jobs alljobs;
const char *msg_delrunjobsig = "Job sent signal %s on delete";
struct server server;
const char *msg_manager = "%s at request of %s@%s";
int LOGLEVEL = 7; /* force logging code to be exercised as tests run */
long keep_seconds;
int  bad_queue;
int  bad_relay;
int  signal_issued;
int  nanny = 1;
int  br_freed;
int  alloc_work = 1;

batch_request *alloc_br(int type)
  {
  if (alloc_work)
    return((batch_request *)calloc(1, sizeof(batch_request)));
  else
    return(NULL);
  }

job_array *get_jobs_array(job **pjob)
  {
  fprintf(stderr, "The call to get_jobs_array needs to be mocked!!\n");
  exit(1);
  }

void account_record(int acctype, job *pjob, const char *text)
  {
  fprintf(stderr, "The call to acctype needs to be mocked!!\n");
  exit(1);
  }

int job_save(job *pjob, int updatetype, int mom_port)
  {
  fprintf(stderr, "The call to job_save needs to be mocked!!\n");
  exit(1);
  }

int svr_job_purge(job *pjob)
  {
  pjob->ji_qs.ji_state = JOB_STATE_COMPLETE;
  return(0);
  }

void chk_job_req_permissions(job **pjob_ptr, struct batch_request *preq)
  {
  fprintf(stderr, "The call to chk_job_req_permissions needs to be mocked!!\n");
  exit(1);
  }

void svr_mailowner(job *pjob, int mailpoint, int force, const char *text)
  {
  fprintf(stderr, "The call to svr_mailowner needs to be mocked!!\n");
  exit(1);
  }

long attr_ifelse_long(pbs_attribute *attr1, pbs_attribute *attr2, long deflong)
  {
  return(keep_seconds);
  }

void on_job_exit(struct work_task *ptask)
  {
  fprintf(stderr, "The call to on_job_exit needs to be mocked!!\n");
  exit(1);
  }

pbs_queue *get_jobs_queue(job **pjob)
  {
  static pbs_queue pque;

  pque.qu_qs.qu_type = QTYPE_Execution;

  if (bad_queue)
    return(NULL);
  else
    return(&pque);
  }

void reply_ack(struct batch_request *preq) {}

void free_nodes(job *pjob) 
  {
  pjob->ji_wattr[JOB_ATR_exec_host].at_val.at_str = NULL;
  }

void free_br(struct batch_request *preq)
  {
  br_freed = TRUE;
  }

struct work_task *set_task(enum work_type type, long event_id, void (*func)(struct work_task *), void *parm, int get_lock)
  {
  return(NULL);
  }

void req_reject(int code, int aux, batch_request *preq, const char *HostName, const char *Msg) { }

job *next_job(struct all_jobs *aj, int *iter)
  {
  fprintf(stderr, "The call to next_job needs to be mocked!!\n");
  exit(1);
  }

void delete_task(struct work_task *ptask) { }

int svr_chk_owner(struct batch_request *preq, job *pjob)
  {
  return(0);
  }

int job_abt(struct job **pjobp, const char *text)
  {
  if (pjobp != NULL)
    *pjobp = NULL;

  return(0);
  }

int issue_signal(job **pjob_ptr, const char *signame, void (*func)(struct batch_request *), void *extra)
  {
  signal_issued = TRUE;
  return(PBSE_NONE);
  }

void set_resc_assigned(job *pjob, enum batch_op op) { }

void release_req(struct work_task *pwt) { }

char *pbse_to_txt(int err)
  {
  return(strdup("bob"));
  }

 work_task *next_task(all_tasks *at, int *iter)
  {
  fprintf(stderr, "The call to next_task needs to be mocked!!\n");
  exit(1);
  }

batch_request *cpy_stage(batch_request *preq, job *pjob, enum job_atr ati, int direction)
  {
  return((batch_request *)calloc(1, sizeof(batch_request)));
  }

int svr_setjobstate(job *pjob, int newstate, int newsubstate, int  has_queue_mute)
  {
  pjob->ji_qs.ji_state = newstate;
  pjob->ji_qs.ji_substate = newsubstate;
  return(0);
  }

job *svr_find_job(char *jobid, int get_subjob)
  {
  if (strcmp(jobid, "1.napali") == 0)
    {
    job *pjob = (job *)calloc(1, sizeof(job));
    strcpy(pjob->ji_qs.ji_jobid, jobid);
    pjob->ji_qs.ji_state = JOB_STATE_RUNNING;
    return(pjob);
    }

  return(NULL);
  }

int unlock_queue(struct pbs_queue *the_queue, const char *id, const char *msg, int logging)
  {
  return(0);
  }

void svr_evaljobstate(job *pjob, int *newstate, int *newsub, int forceeval)
  {
  fprintf(stderr, "The call to svr_evaljobstate needs to be mocked!!\n");
  exit(1);
  }

int insert_task(all_tasks *at, work_task *wt)
  {
  fprintf(stderr, "The call to insert_task needs to be mocked!!\n");
  exit(1);
  }


char *threadsafe_tokenizer(char **str, const char *delims)
  {
  fprintf(stderr, "The call to threadsafe_tokenizer needs to be mocked!!\n");
  exit(1);
  }

int get_svr_attr_l(int index, long *l)
  {
  if (nanny)
    *l = 1;

  return(0);
  }

batch_request *get_remove_batch_request(

  char *br_id)

  {
  return(NULL);
  }

int get_batch_request_id(

  batch_request *preq)

  {
  return(0);
  }

int unlock_ji_mutex(job *pjob, const char *id, const char *msg, int logging)
  {
  return(0);
  }

int unlock_ai_mutex(job_array *pa, const char *id, const char *msg, int logging)
  {
  return(0);
  }

void on_job_exit_task(struct work_task *ptask) {}

int enqueue_threadpool_request(void *(*func)(void *), void *arg)
  {
  return(0);
  }

void log_err(int l, const char *func_name, const char *msg) {}
void log_event(int type, int otype, const char *func_name, const char *msg) {}

int relay_to_mom(job **pjob_ptr, batch_request   *request, void (*func)(struct work_task *))
  {
  return(bad_relay);
  }
