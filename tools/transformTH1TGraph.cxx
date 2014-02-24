
void transformTH1TGraph(std::string in, std::string out) {
 TFile* fin  = new TFile(in.c_str(), "READ");
 TFile* fout = new TFile(out.c_str(),"RECREATE");

 TH1F* h_SI_over_S  = (TH1F*) fin -> Get ("h_mWeightMap");

//  std::cout << " h_SI_over_S -> GetEntries() = " << h_SI_over_S -> GetEntries() << std::endl;

 fout->cd();

 TGraph* g_SI_over_S  = new TGraph (h_SI_over_S);

 g_SI_over_S -> SetName("SI");

 TGraph* g_S = (TGraph*) g_SI_over_S->Clone ("S");
 for(int i = 0; i < g_S->GetN(); i++){
  Double_t x;
  Double_t y;
  g_S->GetPoint(i, x, y);
  g_S->SetPoint(i, x, 1);
//   std::cout << " x = " << x << std::endl;
 }
 g_S  -> SetName("S");
 g_S -> Write();
 g_SI_over_S-> Write();

}

