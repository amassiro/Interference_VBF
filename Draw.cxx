
void Draw(int mass) {

 std::vector<string> name;

 name.push_back("WWlvlv_df");
 name.push_back("WWlvlv_sf");

 int TOT = name.size();

 TFile* fileInput[100];
 TGraph *g_S[100];
 TGraph *g_SI[100];
 TGraph *g_SI_over_S[100];

 TMultiGraph* mg_S = new TMultiGraph();
 TMultiGraph* mg_SI = new TMultiGraph();

 TMultiGraph* mg_SI_over_S = new TMultiGraph();

 TCanvas* cc_S  = new TCanvas("cc_S", "cc_S", 800,600);
 TCanvas* cc_SI = new TCanvas("cc_SI","cc_SI",800,600);
 TCanvas* cc_SI_over_S = new TCanvas("cc_SI_over_S","cc_SI_over_S",800,600);

 for (int i=0; i<TOT; i++) {
  TString fileName = Form ("data/%d/%s.root",mass,name.at(i).c_str());
  fileInput[i] = new TFile (fileName,"READ");
  g_S[i]  = (TGraph*) fileInput[i] -> Get ("S");
  g_SI[i] = (TGraph*) fileInput[i] -> Get ("SI");

  g_SI_over_S[i] = new TGraph();

  for (int iPoint = 0; iPoint < g_SI[i] -> GetN(); iPoint++) {
   double x_num;
   double y_num;
   g_SI[i] -> GetPoint (iPoint, x_num, y_num);

   double x_den;
   double y_den;
   g_S[i] -> GetPoint (iPoint, x_den, y_den);

   double ratio = 1;
   if (x_den==x_num && y_den!=0) ratio = y_num / y_den;

   g_SI_over_S[i] -> SetPoint (iPoint, x_num, ratio);


   g_S[i]  -> SetTitle (name.at(i).c_str());
   g_SI[i] -> SetTitle (name.at(i).c_str());
   g_SI_over_S[i] -> SetTitle (name.at(i).c_str());

   g_SI[i] -> SetLineColor (kRed + i );
   g_S[i] -> SetLineColor  (kBlue + i );
   g_SI_over_S[i] -> SetLineColor (kGreen + i*10 );

   g_S[i]  -> SetLineWidth (2);
   g_SI[i] -> SetLineWidth (2);
   g_SI_over_S[i] -> SetLineWidth (2);
  }

  mg_S  -> Add(g_S[i]);
  mg_SI -> Add(g_SI[i]);
  mg_SI_over_S -> Add(g_SI_over_S[i]);
 }

 TLegend* leg = new TLegend (0.5,0.5,0.9,0.9);
 leg -> SetFillColor(0);
 for (int i=0; i<TOT; i++) {
  leg -> AddEntry(g_SI_over_S[i], name.at(i).c_str(), "L");
 }

 cc_S->cd();
 mg_S->Draw("APL");
//  leg->Draw();
 cc_S->SetGrid();

 cc_SI->cd();
 mg_SI->Draw("APL");
//  leg->Draw();
 cc_SI->SetGrid();

 cc_SI_over_S->cd();
 mg_SI_over_S->Draw("APL");
 leg->Draw();
 cc_SI_over_S->SetGrid();

}