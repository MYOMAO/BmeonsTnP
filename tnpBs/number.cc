#include <iostream>
#include "tnp_weight_lowptPbPb.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraphAsymmErrors.h>
#include <TSystem.h>
#include <TLegend.h>
#include "xjjrootuti.h"
#include "xjjcuti.h"
#include <string>
#include "tnpcc.h"

Double_t centmin = 30.;
Double_t centmax = 90.;
TString infilename1 = Form("rootfiles/tnp_ntKp_Y0p0-0p5_Cent%.0f-%.0f.root",centmin,centmax);
TString infilename2 = Form("rootfiles/tnp_ntKp_Y0p5-1p0_Cent%.0f-%.0f.root",centmin,centmax);
TString infilename3 = Form("rootfiles/tnp_ntKp_Y1p0-1p5_Cent%.0f-%.0f.root",centmin,centmax);
TString infilename4 = Form("rootfiles/tnp_ntKp_Y1p5-2p0_Cent%.0f-%.0f.root",centmin,centmax);
TString infilename5 = Form("rootfiles/tnp_ntKp_Y2p0-2p4_Cent%.0f-%.0f.root",centmin,centmax);
TString outname = Form("TNP2D_Bplus_Cent%.0f-%.0f",centmin,centmax);

void number()
{
  gStyle->SetOptStat(0);
  
  //TFile* infile = TFile::Open(inputname.c_str());
 
  TFile* infile1 = new TFile(infilename1.Data());
  TH1D* htnp_nominal_nominal1 = (TH1D*) infile1->Get("htnp_nominal_nominal");
  TH1D* htnp_total_nominal1 = (TH1D*) infile1->Get("htnp_total_nominal");
  TH1D* htnp_total_stat_d1 = (TH1D*) infile1->Get("htnp_total_stat_d");
  TH1D* htnp_total_stat_u1 = (TH1D*) infile1->Get("htnp_total_stat_u");
  TH1D* htnp_total_syst_d1 = (TH1D*) infile1->Get("htnp_total_syst_d");
  TH1D* htnp_total_syst_u1 = (TH1D*) infile1->Get("htnp_total_syst_u");

  TFile* infile2 = new TFile(infilename2.Data());
  TH1D* htnp_nominal_nominal2 = (TH1D*) infile2->Get("htnp_nominal_nominal");
  TH1D* htnp_total_nominal2 = (TH1D*) infile2->Get("htnp_total_nominal");
  TH1D* htnp_total_stat_d2 = (TH1D*) infile2->Get("htnp_total_stat_d");
  TH1D* htnp_total_stat_u2 = (TH1D*) infile2->Get("htnp_total_stat_u");
  TH1D* htnp_total_syst_d2 = (TH1D*) infile2->Get("htnp_total_syst_d");
  TH1D* htnp_total_syst_u2 = (TH1D*) infile2->Get("htnp_total_syst_u");

  TFile* infile3 = new TFile(infilename3.Data());
  TH1D* htnp_nominal_nominal3 = (TH1D*) infile3->Get("htnp_nominal_nominal");
  TH1D* htnp_total_nominal3 = (TH1D*) infile3->Get("htnp_total_nominal");
  TH1D* htnp_total_stat_d3 = (TH1D*) infile3->Get("htnp_total_stat_d");
  TH1D* htnp_total_stat_u3 = (TH1D*) infile3->Get("htnp_total_stat_u");
  TH1D* htnp_total_syst_d3 = (TH1D*) infile3->Get("htnp_total_syst_d");
  TH1D* htnp_total_syst_u3 = (TH1D*) infile3->Get("htnp_total_syst_u");

  TFile* infile4 = new TFile(infilename4.Data());
  TH1D* htnp_nominal_nominal4 = (TH1D*) infile4->Get("htnp_nominal_nominal");
  TH1D* htnp_total_nominal4 = (TH1D*) infile4->Get("htnp_total_nominal");
  TH1D* htnp_total_stat_d4 = (TH1D*) infile4->Get("htnp_total_stat_d");
  TH1D* htnp_total_stat_u4 = (TH1D*) infile4->Get("htnp_total_stat_u");
  TH1D* htnp_total_syst_d4 = (TH1D*) infile4->Get("htnp_total_syst_d");
  TH1D* htnp_total_syst_u4 = (TH1D*) infile4->Get("htnp_total_syst_u");

  TFile* infile5 = new TFile(infilename5.Data());
  TH1D* htnp_nominal_nominal5 = (TH1D*) infile5->Get("htnp_nominal_nominal");
  TH1D* htnp_total_nominal5 = (TH1D*) infile5->Get("htnp_total_nominal");
  TH1D* htnp_total_stat_d5 = (TH1D*) infile5->Get("htnp_total_stat_d");
  TH1D* htnp_total_stat_u5 = (TH1D*) infile5->Get("htnp_total_stat_u");
  TH1D* htnp_total_syst_d5 = (TH1D*) infile5->Get("htnp_total_syst_d");
  TH1D* htnp_total_syst_u5 = (TH1D*) infile5->Get("htnp_total_syst_u");

  int npt = 60, nY = 5;
  double ptbin[npt+1] = {5., 5.5, 6., 6.5, 7., 7.5, 8., 8.5, 9., 9.5, 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50., 51., 52., 53., 54., 55., 56., 57., 58., 59., 60.};
  //double ptbin[npt+1] = {5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50., 51., 52., 53., 54., 55., 56., 57., 58., 59., 60.};
  double Ybin[nY+1] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.4};
  double scale[npt][nY], syst_d[npt][nY], syst_u[npt][nY], stat_d[npt][nY], stat_u[npt][nY], total_d[npt][nY], total_u[npt][nY];
  TFile* outfile = new TFile(Form("%s.root",outname.Data()), "recreate");
  TH2D* tnp_scale = new TH2D("tnp_scale","",npt,ptbin,nY,Ybin);
  TH2D* tnp_total_d = new TH2D("tnp_total_d","",npt,ptbin,nY,Ybin);
  TH2D* tnp_total_u = new TH2D("tnp_total_u","",npt,ptbin,nY,Ybin);

  for(int i=0;i<npt;i++)
    {
      for(int j=0;j<npt;j++)
	{
	  scale[i][j]=0;
	  syst_d[i][j]=0;
	  syst_u[i][j]=0;
	  stat_d[i][j]=0;
	  stat_u[i][j]=0;
	  total_d[i][j]=0;
	  total_u[i][j]=0;
	}
    }

  for(int i=0;i<npt;i++)
    {
      if(htnp_nominal_nominal1->GetBinContent(i+1)!=0)
	{
	  scale[i][0]=htnp_total_nominal1->GetBinContent(i+1)/htnp_nominal_nominal1->GetBinContent(i+1);
	  syst_d[i][0]=TMath::Abs(htnp_total_syst_d1->GetBinContent(i+1)-htnp_total_nominal1->GetBinContent(i+1))/htnp_total_nominal1->GetBinContent(i+1);
	  syst_u[i][0]=TMath::Abs(htnp_total_syst_u1->GetBinContent(i+1)-htnp_total_nominal1->GetBinContent(i+1))/htnp_total_nominal1->GetBinContent(i+1);
	  stat_d[i][0]=TMath::Abs(htnp_total_stat_d1->GetBinContent(i+1)-htnp_total_nominal1->GetBinContent(i+1))/htnp_total_nominal1->GetBinContent(i+1);
	  stat_u[i][0]=TMath::Abs(htnp_total_stat_u1->GetBinContent(i+1)-htnp_total_nominal1->GetBinContent(i+1))/htnp_total_nominal1->GetBinContent(i+1);
	  total_d[i][0]=sqrt(stat_d[i][0]*stat_d[i][0]+syst_d[i][0]*syst_d[i][0]);
	  total_u[i][0]=sqrt(stat_u[i][0]*stat_u[i][0]+syst_u[i][0]*syst_u[i][0]);
	}
      
      if(htnp_nominal_nominal2->GetBinContent(i+1)!=0)
	{
	  scale[i][1]=htnp_total_nominal2->GetBinContent(i+1)/htnp_nominal_nominal2->GetBinContent(i+1);
	  syst_d[i][1]=TMath::Abs(htnp_total_syst_d2->GetBinContent(i+1)-htnp_total_nominal2->GetBinContent(i+1))/htnp_total_nominal2->GetBinContent(i+1);
	  syst_u[i][1]=TMath::Abs(htnp_total_syst_u2->GetBinContent(i+1)-htnp_total_nominal2->GetBinContent(i+1))/htnp_total_nominal2->GetBinContent(i+1);
	  stat_d[i][1]=TMath::Abs(htnp_total_stat_d2->GetBinContent(i+1)-htnp_total_nominal2->GetBinContent(i+1))/htnp_total_nominal2->GetBinContent(i+1);
	  stat_u[i][1]=TMath::Abs(htnp_total_stat_u2->GetBinContent(i+1)-htnp_total_nominal2->GetBinContent(i+1))/htnp_total_nominal2->GetBinContent(i+1);
	  total_d[i][1]=sqrt(stat_d[i][1]*stat_d[i][1]+syst_d[i][1]*syst_d[i][1]);
	  total_u[i][1]=sqrt(stat_u[i][1]*stat_u[i][1]+syst_u[i][1]*syst_u[i][1]);
	}

      if(htnp_nominal_nominal3->GetBinContent(i+1)!=0)
	{
	  scale[i][2]=htnp_total_nominal3->GetBinContent(i+1)/htnp_nominal_nominal3->GetBinContent(i+1);
	  syst_d[i][2]=TMath::Abs(htnp_total_syst_d3->GetBinContent(i+1)-htnp_total_nominal3->GetBinContent(i+1))/htnp_total_nominal3->GetBinContent(i+1);
	  syst_u[i][2]=TMath::Abs(htnp_total_syst_u3->GetBinContent(i+1)-htnp_total_nominal3->GetBinContent(i+1))/htnp_total_nominal3->GetBinContent(i+1);
	  stat_d[i][2]=TMath::Abs(htnp_total_stat_d3->GetBinContent(i+1)-htnp_total_nominal3->GetBinContent(i+1))/htnp_total_nominal3->GetBinContent(i+1);
	  stat_u[i][2]=TMath::Abs(htnp_total_stat_u3->GetBinContent(i+1)-htnp_total_nominal3->GetBinContent(i+1))/htnp_total_nominal3->GetBinContent(i+1);
	  total_d[i][2]=sqrt(stat_d[i][2]*stat_d[i][2]+syst_d[i][2]*syst_d[i][2]);
	  total_u[i][2]=sqrt(stat_u[i][2]*stat_u[i][2]+syst_u[i][2]*syst_u[i][2]);
	}

      if(htnp_nominal_nominal4->GetBinContent(i+1)!=0)
	{
	  scale[i][3]=htnp_total_nominal4->GetBinContent(i+1)/htnp_nominal_nominal4->GetBinContent(i+1);
	  syst_d[i][3]=TMath::Abs(htnp_total_syst_d4->GetBinContent(i+1)-htnp_total_nominal4->GetBinContent(i+1))/htnp_total_nominal4->GetBinContent(i+1);
	  syst_u[i][3]=TMath::Abs(htnp_total_syst_u4->GetBinContent(i+1)-htnp_total_nominal4->GetBinContent(i+1))/htnp_total_nominal4->GetBinContent(i+1);
	  stat_d[i][3]=TMath::Abs(htnp_total_stat_d4->GetBinContent(i+1)-htnp_total_nominal4->GetBinContent(i+1))/htnp_total_nominal4->GetBinContent(i+1);
	  stat_u[i][3]=TMath::Abs(htnp_total_stat_u4->GetBinContent(i+1)-htnp_total_nominal4->GetBinContent(i+1))/htnp_total_nominal4->GetBinContent(i+1);
	  total_d[i][3]=sqrt(stat_d[i][3]*stat_d[i][3]+syst_d[i][3]*syst_d[i][3]);
	  total_u[i][3]=sqrt(stat_u[i][3]*stat_u[i][3]+syst_u[i][3]*syst_u[i][3]);
	}

      if(htnp_nominal_nominal5->GetBinContent(i+1)!=0)
	{
	  scale[i][4]=htnp_total_nominal5->GetBinContent(i+1)/htnp_nominal_nominal5->GetBinContent(i+1);
	  syst_d[i][4]=TMath::Abs(htnp_total_syst_d5->GetBinContent(i+1)-htnp_total_nominal5->GetBinContent(i+1))/htnp_total_nominal5->GetBinContent(i+1);
	  syst_u[i][4]=TMath::Abs(htnp_total_syst_u5->GetBinContent(i+1)-htnp_total_nominal5->GetBinContent(i+1))/htnp_total_nominal5->GetBinContent(i+1);
	  stat_d[i][4]=TMath::Abs(htnp_total_stat_d5->GetBinContent(i+1)-htnp_total_nominal5->GetBinContent(i+1))/htnp_total_nominal5->GetBinContent(i+1);
	  stat_u[i][4]=TMath::Abs(htnp_total_stat_u5->GetBinContent(i+1)-htnp_total_nominal5->GetBinContent(i+1))/htnp_total_nominal5->GetBinContent(i+1);
	  total_d[i][4]=sqrt(stat_d[i][4]*stat_d[i][4]+syst_d[i][4]*syst_d[i][4]);
	  total_u[i][4]=sqrt(stat_u[i][4]*stat_u[i][4]+syst_u[i][4]*syst_u[i][4]);
	}
      
      //printf("ptbin %d: scale=%.2f, (in percent) syst_d=%.2f syst_u=%.2f stat_d=%.2f stat_u=%.2f total_d=%.2f total_u=%.2f\n",i,scale[i][0],syst_d[i][0]*100,syst_u[i][0]*100,stat_d[i][0]*100,stat_u[i][0]*100,total_d[i][0]*100,total_u[i][0]*100);
    }

  for(int i=0;i<npt;i++)
    {
      for(int j=0;j<nY;j++)
	{
	  tnp_scale->SetBinContent(i+1,j+1,scale[i][j]);
	  tnp_total_d->SetBinContent(i+1,j+1,total_d[i][j]);
	  tnp_total_u->SetBinContent(i+1,j+1,total_u[i][j]);
	}
    }

  tnp_scale->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
  tnp_scale->GetYaxis()->SetTitle("B^{+} |y|");
  tnp_scale->GetYaxis()->SetTitleOffset(1.5);
  tnp_scale->GetXaxis()->CenterTitle();
  tnp_scale->GetYaxis()->CenterTitle();

  tnp_total_d->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
  tnp_total_d->GetYaxis()->SetTitle("B^{+} |y|");
  tnp_total_d->GetYaxis()->SetTitleOffset(1.5);
  tnp_total_d->GetXaxis()->CenterTitle();
  tnp_total_d->GetYaxis()->CenterTitle();

  tnp_total_u->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
  tnp_total_u->GetYaxis()->SetTitle("B^{+} |y|");
  tnp_total_u->GetYaxis()->SetTitleOffset(1.5);
  tnp_total_u->GetXaxis()->CenterTitle();
  tnp_total_u->GetYaxis()->CenterTitle();

  TCanvas* ctnp = new TCanvas("","",600,600);
  ctnp->cd();
  tnp_scale->Draw("COLZ");
  ctnp->SaveAs(Form("%s.png",outname.Data(),centmin,centmax));
  ctnp->SaveAs(Form("%s.pdf",outname.Data(),centmin,centmax));

  tnp_total_d->Draw("COLZ"); 
  ctnp->SaveAs(Form("%s_down.png",outname.Data(),centmin,centmax));
  ctnp->SaveAs(Form("%s_down.pdf",outname.Data(),centmin,centmax));

  tnp_total_u->Draw("COLZ"); 
  ctnp->SaveAs(Form("%s_up.png",outname.Data(),centmin,centmax));
  ctnp->SaveAs(Form("%s_up.pdf",outname.Data(),centmin,centmax)); 
  
  outfile->cd();
  tnp_scale->Write();
  tnp_total_d->Write();
  tnp_total_u->Write();
  outfile->Close();

  return;
}

int main()
{
  number();
  return 1;
}
