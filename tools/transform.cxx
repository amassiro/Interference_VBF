
void transform(std::string in, std::string out) {
 TFile* fin  = new TFile(in.c_str(), "READ");
 TFile* fout = new TFile(out.c_str(),"RECREATE");

 TF1* f_S  = (TF1*) fin -> Get ("func_mg_1");
 TF1* f_SI = (TF1*) fin -> Get ("func_ph_2");

 fout->cd();

 TGraph* g_S  = new TGraph (f_S);
 TGraph* g_SI = new TGraph (f_SI);

 g_S  -> SetName("S");
 g_SI -> SetName("SI");

 g_S -> Write();
 g_SI-> Write();

}

