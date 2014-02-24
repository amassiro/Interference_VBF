
void transformTH1TGraph(std::string in, std::string out) {
 TFile* fin  = new TFile(in.c_str(), "READ");
 TFile* fout = new TFile(out.c_str(),"RECREATE");

 TH1F* h_SI_over_S  = (TH1F*) fin -> Get ("h_mWeightMap");

 fout->cd();

 TGraph* g_SI_over_S  = new TGraph (h_SI_over_S);

 g_SI_over_S -> SetName("SI");

 TGraph* g_S = (TGraph*) g_SI_over_S->Clone ("S");
 for(i=0; i<g_S->GetN(); i++){
  float x,y;
  g_S->GetPoint(i,x,y);
  g_S->SetPoint(i,x,1);
 }
 g_S  -> SetName("S");
 g_S -> Write();
 g_SI-> Write();

}

