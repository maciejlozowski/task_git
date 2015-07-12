#include "person.h"
#include <stdlib.h>
#include <string.h>

struct person_data {
	char* name;
};

static void set_name(struct person* self, const char* p_name)
{
	//struct person_data* pd = (struct person_data*) malloc(sizeof(struct person_data)); //my
	//self->pd = (struct person_data*) malloc(sizeof(struct person_data));
	//struct rec *ptr_one;
	//ptr_one =(struct rec *) malloc (sizeof(struct rec));
	//free(ptr_one);

	if (self->pd) {
		if (self->pd->name)
			free(self->pd->name);
		if (p_name) {
			self->pd->name = (char*) malloc((strlen(p_name)) * sizeof(char));
			strcpy(self->pd->name, p_name); //+1 niepotrzebne ?
		} else {
			self->pd->name = 0;
		}
	}
}

static const char* get_name(struct person* self)
{
	if (self->pd)
		return self->pd->name;
	return 0;
}

struct person* create(const char* p_name) //pobieramy jako argument ciag charow
{
	struct person* result = (struct person*) malloc(sizeof(struct person)); //alokujemy pamiec dla wskaznika na strukture person
	
	result->pd = malloc(sizeof(char) * 10);//

	result->set_name = &set_name; // jako ze set_name i get_name sa static musimy przypisac adresy do nich dla result->set_name, zeby lapal go w mainie (static maja zasieg lokalny w pliku)
	result->get_name = &get_name; // 

	if (p_name) { //jesli p_name jest ustawiony to alokujemy pamiec dla pola pd->name
		result->pd->name = (char*) malloc((strlen(p_name)) * sizeof(char));
		strcpy(result->pd->name, p_name); //kopiujemy do pd->name slowo zawarte w p_name
	}

	return result;
}

void destroy(struct person* p_person)
{
	if (p_person) {
		if (p_person->pd->name){
			free(p_person->pd->name);
			free(p_person->pd);			
			}
		free(p_person);
		p_person = NULL; //my
	}
}

