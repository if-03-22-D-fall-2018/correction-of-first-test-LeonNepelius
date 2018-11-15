/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			grade_list.c
 * Author:			P. Bauer
 * Due Date:		November 18, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of grade_list.h.
 * ----------------------------------------------------------
 */
#include "process_list.h"
void init_process_list(ProcessList *pl)
{
  pl->length = 0;
}

int get_length(const ProcessList *pl){
  return pl->length;
}

bool add_entry(ProcessList *pl, struct ProcessListEntry *e)
{
  if (get_length(pl) >= MAX_LIST_ENTRIES)
  {
    return false;
  }
  pl->processes[get_length(pl)] = e;
  pl->length += 1;
  return true;
}

bool add_entries(ProcessList *pl, struct ProcessListEntry *e[], int n)
{
  if (get_length(pl) >= MAX_LIST_ENTRIES)
  {
    return false;
  }
  for (int i = 0; i < n; i++) {
    pl->processes[get_length(pl)] = e[i];
    pl->length += 1;
  }
  return true;
}

int get_process_with_id(const ProcessList *pl, int id, struct ProcessListEntry *result_list[])
{
  if (get_length(pl) == 0)
  {
    return 0;
  }
    for (int i = 0; i < get_length(pl); i++) {
      if (pl->processes[i]->pid == id)
      {
        result_list[0] = pl->processes[i];
        return 1;
      }
  }

  return 0;
}

int get_processes_with_state(const ProcessList *pl, enum ProcessState state, struct ProcessListEntry *result_list[])
{
  int entries = 0;
  int counter = 0;
  if (get_length(pl) == 0)
  {
    return 0;
  }
    for (int i = 0; i < get_length(pl); i++) {
      if (pl->processes[i]->state == state)
      {
        result_list[counter] = pl->processes[i];
        counter++;
        entries++;
      }
  }

  return entries;
}

struct ProcessListEntry *get_process_with_highest_cpu_consumption(const ProcessList *pl)
{
  struct ProcessListEntry* pl2 = pl->processes[0];
  if (get_length(pl) == 0)
  {
    return 0;
  }
  if (get_length(pl) == 1)
  {
    return pl->processes[0]; //TODO Added return before pl->processes[0]
  }
    for (int j = 0; j < get_length(pl); j++) {
      if (pl2->cpu_usage < pl->processes[j]->cpu_usage)
      {
        pl2 = pl->processes[j];
      }
  }
  return pl2;
}

struct ProcessListEntry *get_process_with_lowest_cpu_consumption(const ProcessList *pl)
{
  struct ProcessListEntry* pl2 = pl->processes[0];
  if (get_length(pl) == 0)
  {
    return 0;
  }
  if (get_length(pl) == 1)
  {
    return pl->processes[0]; //TODO Added return before pl->processes[0] warnings cleared
  }
    for (int j = 0; j < get_length(pl); j++) {
      if (pl2->cpu_usage > pl->processes[j]->cpu_usage)
      {
        pl2 = pl->processes[j];
      }
  }
  return pl2;
}

int get_top_n_processes_cpu(const ProcessList *pl, int n, struct ProcessListEntry *result_list[])
{
  if(n > get_length(pl))
  {
    return MAX_LIST_ENTRIES;
  }
  return 0;
}

int get_bottom_n_processes_cpu(const ProcessList *pl, int n, struct ProcessListEntry *result_list[])
{
  if(n > get_length(pl))
  {
    return MAX_LIST_ENTRIES;
  }
  return 0;
}
