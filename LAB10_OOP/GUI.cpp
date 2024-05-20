#include "GUI.h"

void parcare_gui::init_components() {
	

	QHBoxLayout* ly_main = new QHBoxLayout;

	this->setLayout(ly_main);

	// partea stanga
	QWidget* left = new QWidget;
	QVBoxLayout* ly_left = new QVBoxLayout;
	left->setLayout(ly_left);

	QWidget* form = new QWidget;
	QFormLayout* ly_form = new QFormLayout;
	form->setLayout(ly_form);
	edit_nr = new QLineEdit;
	edit_prod = new QLineEdit;
	edit_model = new QLineEdit;
	edit_tip = new QLineEdit;

	ly_form->addRow(lbl_nr, edit_nr);
	ly_form->addRow(lbl_prod, edit_prod);
	ly_form->addRow(lbl_model, edit_model);
	ly_form->addRow(lbl_tip, edit_tip);

	btn_add = new QPushButton{ "Adauga masina" };
	ly_form->addWidget(btn_add);

	btn_del = new QPushButton{ "Sterge masina" };
	ly_form->addWidget(btn_del);

	btn_mod = new QPushButton{ "Modifica masina" };
	ly_form->addWidget(btn_mod);

	

	QVBoxLayout* ly_sortare = new QVBoxLayout;
	this->grp_box->setLayout(ly_sortare);

	ly_sortare->addWidget(grp_box);
	ly_sortare->addWidget(radio_sort_nr);
	ly_sortare->addWidget(radio_sort_prod);
	ly_sortare->addWidget(radio_sort_tip);

	btn_sort = new QPushButton{ "Sorteaza" };
	ly_sortare->addWidget(btn_sort);

	
	ly_left->addWidget(form);
	ly_left->addWidget(grp_box);
	
	// pt filtrari
	QWidget* flt_form = new QWidget;
	QFormLayout* ly_form_flt = new QFormLayout;
	flt_form->setLayout(ly_form_flt);
	edit_filter_prod = new QLineEdit;
	edit_filter_tip = new QLineEdit;


	btn_flt_prod = new QPushButton{ "Flt dupa prod" };
	ly_form_flt->addRow(lbl_filter_crt2, edit_filter_prod);
	ly_form_flt->addWidget(btn_flt_prod);

	btn_flt_tip = new QPushButton{ "Flt dupa tip" };
	ly_form_flt->addRow(lbl_filter_crt3, edit_filter_tip);
	ly_form_flt->addWidget(btn_flt_tip);

	ly_left->addWidget(flt_form);


	// tabelul
	QWidget* right = new QWidget;
	QVBoxLayout* tab = new QVBoxLayout;
	right->setLayout(tab);

	int nr_lines = 20;
	int nr_col = 4;
	this->table_parcare = new QTableWidget{ nr_lines, nr_col };

	QStringList tab_header;
	tab_header << "   Numar Inmatriculare    " << "    Producator   " << "    Model    " << "Tip";
	this->table_parcare->horizontalHeader()->setStretchLastSection(true);
	this->table_parcare->setHorizontalHeaderLabels(tab_header);

	// optiune pt a se redimensiona celulele
	this->table_parcare->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tab->addWidget(table_parcare);


	// lista init
	lst_lista = new QTableWidget{ 20, 4 };
	QStringList tab_header1;
	tab_header1 << "   Numar Inmatriculare    " << "    Producator   " << "    Model    " << "Tip";
	this->lst_lista->horizontalHeader()->setStretchLastSection(true);
	this->lst_lista->setHorizontalHeaderLabels(tab_header1);
	add_lst = new QPushButton{ "Adauga" };
	grndm_lst = new QPushButton{ "Genereaza random" };
	empty_lst = new QPushButton{ "Goleste" };
	nr_inmatriculare = new QLineEdit;
	nr_masini = new QLineEdit;
	xprt = new QLineEdit;
	export_lst = new QPushButton{"Exporta Wishlist"};



	btn_undo = new QPushButton{ "Undo" };
	tab->addWidget(btn_undo);

	btn_reload = new QPushButton{ "Reload" };
	tab->addWidget(btn_reload);

	btn_lista = new QPushButton{ "Lista" };
	tab->addWidget(btn_lista);

	raport = new QPushButton{ "Raport" };
	tab->addWidget(raport);


	QWidget* rright = new QWidget;
	QVBoxLayout* ly_rr = new QVBoxLayout;
	rright->setLayout(ly_rr);

	parcare_lista = new QListWidget;
	t_br = new QPushButton{ "Break" };
	t_sdn = new QPushButton{ "Sedan" };
	t_suv = new QPushButton{ "SUV" };
	t_sprt = new QPushButton{ "Sport" };
	altele = new QPushButton{ "Altele" };
	ly_rr->addWidget(parcare_lista);

	ly_rr->addWidget(t_br);
	ly_rr->addWidget(t_sdn);
	ly_rr->addWidget(t_suv);
	ly_rr->addWidget(t_sprt);
	ly_rr->addWidget(altele);
	t_br->setVisible(false);
	t_sdn->setVisible(false);
	t_suv->setVisible(false);
	t_sprt->setVisible(false);




	for (int i = 0; i < srv.get_all_srv().size(); i++) {
		if (srv.get_all_srv().at(i).get_tip() == "Sport") {
			t_sprt->setVisible(true);
			break;
		}
	}

	for (int i = 0; i < srv.get_all_srv().size(); i++) {
		if (srv.get_all_srv().at(i).get_tip() == "Break") {
			t_br->setVisible(true);
			break;
		}
	}


	for (int i = 0; i < srv.get_all_srv().size(); i++) {
		if (srv.get_all_srv().at(i).get_tip() == "Sedan") {
			t_sdn->setVisible(true);
			break;
		}
	}

	for (int i = 0; i < srv.get_all_srv().size(); i++) {
		if (srv.get_all_srv().at(i).get_tip() == "SUV") {
			t_suv->setVisible(true);
			break;
		}
	}

	int alt = 0;
	for (auto masina : srv.get_all_srv()) {
		if (masina.get_tip() != "Break" && masina.get_tip() != "Sedan" && masina.get_tip() != "SUV" && masina.get_tip() != "Sport")
			alt++;
	}
	if (alt == 0)
		altele->setVisible(false);

	ly_main->addWidget(left);
	ly_main->addWidget(right);
	ly_main->addWidget(rright);
	
}

void parcare_gui::connect_sig_slots() {
	QObject::connect(btn_add, &QPushButton::clicked, this, &parcare_gui::gui_add);
	QObject::connect(btn_del, &QPushButton::clicked, this, &parcare_gui::gui_del);
	QObject::connect(btn_mod, &QPushButton::clicked, this, &parcare_gui::gui_mod);

	QObject::connect(btn_undo, &QPushButton::clicked, [&]() {
		try {
			this->srv.undo();
			this->reload_parcare(this->srv.get_all_srv());
			QMessageBox::information(this, "INFO", QString::fromStdString("Undo realizat."));
		}
		catch (parcare_exception& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_mesaj()));
		}
	});

	QObject::connect(btn_reload, &QPushButton::clicked, [&]() {
		try {
			this->reload_parcare(this->srv.get_all_srv());
			QMessageBox::information(this, "INFO", QString::fromStdString("Reload realizat."));
		}
		catch (parcare_exception& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_mesaj()));
		}
		});

	QObject::connect(btn_sort, &QPushButton::clicked, [&]() {
		if (this->radio_sort_nr->isChecked())
			this->reload_parcare(srv.sorteaza_nr_inm());
		if (this->radio_sort_prod->isChecked())
			this->reload_parcare(srv.sorteaza_prod());
		if (this->radio_sort_tip->isChecked())
			this->reload_parcare(srv.sorteaza_tip());
	});

	QObject::connect(btn_flt_prod, &QPushButton::clicked, [&]() {
		try {
			string prod = edit_filter_prod->text().toStdString();
			this->reload_parcare(srv.filtreaza_p(prod));

			QMessageBox::information(this, "INFO", QString::fromStdString("Filtrare efectuata."));
		}
		catch (parcare_exception& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_mesaj()));
		}
	});

	QObject::connect(btn_flt_tip, &QPushButton::clicked, [&]() {
		try {
			string tip = edit_filter_tip->text().toStdString();
			this->reload_parcare(srv.filtreaza_t(tip));

			QMessageBox::information(this, "Warning", QString::fromStdString("Filtrare efectuata."));
		}
		catch (parcare_exception& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_mesaj()));
		}
	});

	QObject::connect(btn_lista, &QPushButton::clicked, [&]() {
		QWidget* lst_wndw = new QWidget;
		QFormLayout* ly_lst = new QFormLayout;
		lst_wndw->setLayout(ly_lst);

		ly_lst->addRow("Numar Inmatriculare", nr_inmatriculare);
		ly_lst->addWidget(add_lst);

		ly_lst->addRow(lbl_rndm, nr_masini);
		ly_lst->addWidget(grndm_lst);

		ly_lst->addRow(xprt, export_lst);
		ly_lst->addWidget(empty_lst);

		ly_lst->addRow(lst_lista);


		lst_wndw->show();
	});

	QObject::connect(add_lst, &QPushButton::clicked, [&]() {
		try {
			string nr = nr_inmatriculare->text().toStdString();
			nr_inmatriculare->clear();
			this->srv.adauga_ls(nr);

			this->reload_lst(srv.get_all_lst());
		}
		catch (parcare_exception& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_mesaj()));
		}
	});

	QObject::connect(empty_lst, &QPushButton::clicked, [&]() {
		this->srv.goleste_lst();
		this->reload_lst(srv.get_all_lst());
	}); 

	QObject::connect(grndm_lst, &QPushButton::clicked, [&]() {
		int nr = nr_masini->text().toInt();
		
		this->srv.gnr_rndm(nr);

		this->reload_lst(srv.get_all_lst());
	});

	QObject::connect(export_lst, &QPushButton::clicked, [&]() {
		string nume = xprt->text().toStdString();
		xprt->clear();

		this->srv.write_to_file(nume);
		QMessageBox::information(this, "INFO", "Lista salvata!");
	});

	QObject::connect(raport, &QPushButton::clicked, [&]() {
		QWidget* rprt = new QWidget;
		QFormLayout* ly = new QFormLayout;
		rprt->setLayout(ly);

		QTableWidget* tbl_raport = new QTableWidget{ 20, 2 };
		QStringList tab_header1;
		tab_header1 << "   Numar Inmatriculare    " << "    Producator   " << "    Model    " << "Tip";
		tbl_raport->horizontalHeader()->setStretchLastSection(true);
		tbl_raport->setHorizontalHeaderLabels(tab_header1);

		ly->addWidget(tbl_raport);
		std::map<string, valueDTO> mp = srv.raport();
		int nr_linie = 0;
		for (auto& str : mp) {
			string ss = str.first;
			int ii = str.second.get_value();
			string g = std::to_string(ii);
			tbl_raport->setItem(nr_linie, 0, new QTableWidgetItem(QString::fromStdString(ss)));
			tbl_raport->setItem(nr_linie, 1, new QTableWidgetItem(QString::fromStdString(g)));
			nr_linie++;
		}
		rprt->show();
	});

	
	QObject::connect(t_br, &QPushButton::clicked, [&]() {
		this->reload_parcare(srv.filtreaza_t("Break"));
	});

	QObject::connect(t_sdn, &QPushButton::clicked, [&]() {
		this->reload_parcare(srv.filtreaza_t("Sedan"));
		});

	QObject::connect(t_suv, &QPushButton::clicked, [&]() {
		this->reload_parcare(srv.filtreaza_t("SUV"));
		});

	QObject::connect(t_sprt, &QPushButton::clicked, [&]() {
		this->reload_parcare(srv.filtreaza_t("Sport"));
		});

	QObject::connect(altele, &QPushButton::clicked, [&]() {
		vector<Masina> srt;

		for (auto masina : srv.get_all_srv()) {
			if (masina.get_tip() != "Break" && masina.get_tip() != "Sedan" && masina.get_tip() != "SUV" && masina.get_tip() != "Sport")
				srt.push_back(masina);
		}
		this->reload_parcare(srt);
	});

}

void parcare_gui::reload_parcare(std::vector<Masina> parc) {
	this->table_parcare->clearContents();
	this->table_parcare->setRowCount(parc.size());
	this->parcare_lista->clear();
	int nr_linie = 0;
	for (auto& masina : parc) {
		this->table_parcare->setItem(nr_linie, 0, new QTableWidgetItem(QString::fromStdString(masina.get_nr())));
		this->table_parcare->setItem(nr_linie, 1, new QTableWidgetItem(QString::fromStdString(masina.get_producator())));
		this->table_parcare->setItem(nr_linie, 2, new QTableWidgetItem(QString::fromStdString(masina.get_model())));
		this->table_parcare->setItem(nr_linie, 3, new QTableWidgetItem(QString::fromStdString(masina.get_tip())));
		string bam_bam = masina.get_nr() + " | " + masina.get_producator() + " | " + masina.get_model() + " | " + masina.get_tip();
		this->parcare_lista->addItem(QString::fromStdString(bam_bam));
		
		nr_linie++;
	}
}

void parcare_gui::reload_lst(std::vector<Masina> lst) {
	this->lst_lista->clearContents();
	this->lst_lista->setRowCount(lst.size());

	int nr_linie = 0;
	for (auto& masina : lst) {
		this->lst_lista->setItem(nr_linie, 0, new QTableWidgetItem(QString::fromStdString(masina.get_nr())));
		this->lst_lista->setItem(nr_linie, 1, new QTableWidgetItem(QString::fromStdString(masina.get_producator())));
		this->lst_lista->setItem(nr_linie, 2, new QTableWidgetItem(QString::fromStdString(masina.get_model())));
		this->lst_lista->setItem(nr_linie, 3, new QTableWidgetItem(QString::fromStdString(masina.get_tip())));
		nr_linie++;
	}
}

void parcare_gui::gui_add() {
	try {
		string nr = edit_nr->text().toStdString();
		string prod = edit_prod->text().toStdString();
		string model = edit_model->text().toStdString();
		string tip = edit_tip->text().toStdString();

		edit_nr->clear();
		edit_prod->clear();
		edit_tip->clear();
		edit_model->clear();

		this->srv.adauga_srv(nr, prod, model, tip);
		this->reload_parcare(this->srv.get_all_srv());

		QMessageBox::information(this, "INFO", QString::fromStdString("Masina adaugata."));
	}
	catch (parcare_exception& ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_mesaj()));
	}

}

void parcare_gui::gui_del() {
	try {
		string nr = edit_nr->text().toStdString();
		string prod = edit_prod->text().toStdString();
		string model = edit_model->text().toStdString();
		string tip = edit_tip->text().toStdString();

		edit_nr->clear();
		edit_prod->clear();
		edit_tip->clear();
		edit_model->clear();

		this->srv.sterge_srv(nr);
		this->reload_parcare(this->srv.get_all_srv());

		QMessageBox::information(this, "INFO", QString::fromStdString("Masina stearsa."));
	}
	catch (parcare_exception& ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_mesaj()));
	}

}

void parcare_gui::gui_mod() {
	try {
		string nr = edit_nr->text().toStdString();
		string prod = edit_prod->text().toStdString();
		string model = edit_model->text().toStdString();
		string tip = edit_tip->text().toStdString();

		edit_nr->clear();
		edit_prod->clear();
		edit_tip->clear();
		edit_model->clear();

		this->srv.modifica_srv(nr, prod, model, tip);
		this->reload_parcare(this->srv.get_all_srv());

		QMessageBox::information(this, "INFO", QString::fromStdString("Masina modificata."));
	}
	catch (parcare_exception& ex) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_mesaj()));
	}
}

