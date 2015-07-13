struct person_data;

struct person {
	void (*set_name)(struct person_data* p_pd, const char* p_name);
	const char* (*get_name)(struct person_data* p_pd);
	struct person_data* pd;
};

struct person* create(const char* p_name);
void destroy(struct person* p_person);

