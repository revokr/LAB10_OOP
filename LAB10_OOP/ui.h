#include "teste.h"

class UI {
private:
	service srv;
public:
	/*
		Constructor implicit
	*/
	UI(service srv) : srv{ srv } {}

	/*
		ruleaza aplicatia
	*/
	void run();

	/*
		afiseaza meniul
	*/
	void meniu();


	/*
		adauga o masina in lista
	*/
	void adauga_ui();

	/*
		sterge o masina din lista
	*/
	void sterge_ui();

	/*
		modifica o masina din lista
	*/
	void modifica_ui(string nr);

	/*
		cauta o masina din lista
	*/
	void cauta_ui();

	/*
		printeaza toate elementele din lista
	*/
	void print_ui(vector<Masina> vct);

	/*
		filtreaza masinile din lista dupa producator
	*/
	void filtreaza_p_ui();

	/*
		filtreaza masinile din lista dupa tip
	*/
	void filtreaza_t_ui();

	/*
		sorteaza masinile din lista dupa nr_inmatriculare
	*/
	void sorteaza_nr_inm_ui();

	/*
		sorteaza masinile din lista dupa producator
	*/
	void sorteaza_prod_ui();

	/*
		sorteaza masinile din lista dupa tip
	*/
	void sorteaza_tip_ui();

	void report_type();

	void adauga_lst(string nr);

	void gnr_random(unsigned long long nr);

	void lst_run();

	void write_to_file();

};