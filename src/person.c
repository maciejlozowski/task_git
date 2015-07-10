#include "person.h"
#include <stdlib.h>
#include <string.h>

struct person_data {
	char* name;
};

static void set_name(struct person_data* p_pd, const char* p_name)
{
	if (p_pd) {
		if (p_pd->name)
			free(p_pd->name);
		if (p_name) {
			p_pd->name = (char*) malloc((strlen(p_name)+1) * sizeof(char));
			strcpy(p_pd->name, p_name);
		} else {
			p_pd->name = 0;
		}
	}
}

static const char* get_name(struct person_data* p_pd)
{
	if (p_pd)
		return p_pd->name;
	return 0;
}

struct person* create(const char* p_name)
{
	struct person* result = (struct person*) malloc(sizeof(struct person));
	result->set_name = &set_name;
	result->get_name = &get_name;

	result->pd = (struct person_data*) malloc(sizeof(struct person_data));
	if (p_name) {
		result->pd->name = (char*) malloc((strlen(p_name)+1) * sizeof(char));
		strcpy(result->pd->name, p_name);
	} else {
		result->pd->name = 0;
	}

	return result;
}

void destroy(struct person* p_person)
{
	if (p_person) {
		if (p_person->pd->name)
			free(p_person->pd->name);
		free(p_person->pd);
		free(p_person);
	}
}

