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

/*
   TString infilename1 = Form("rootfiles/tnp_ntKp_Y0p0-0p5_Cent%.0f-%.0f.root",centmin,centmax);
   TString infilename2 = Form("rootfiles/tnp_ntKp_Y0p5-1p0_Cent%.0f-%.0f.root",centmin,centmax);
   TString infilename3 = Form("rootfiles/tnp_ntKp_Y1p0-1p5_Cent%.0f-%.0f.root",centmin,centmax);
   TString infilename4 = Form("rootfiles/tnp_ntKp_Y1p5-2p0_Cent%.0f-%.0f.root",centmin,centmax);
   TString infilename5 = Form("rootfiles/tnp_ntKp_Y2p0-2p4_Cent%.0f-%.0f.root",centmin,centmax);
   */

void numberdetailed(Double_t centmin = 0., Double_t centmax = 90.)
{
	gStyle->SetOptStat(0);

	//TFile* infile = TFile::Open(inputname.c_str());


	const int NRapBins = 5; 

	TString infilename[NRapBins] ={Form("rootfiles/tnp_ntphi_Y0p0-0p5_Cent%.0f-%.0f.root",centmin,centmax),Form("rootfiles/tnp_ntphi_Y0p5-1p0_Cent%.0f-%.0f.root",centmin,centmax),Form("rootfiles/tnp_ntphi_Y1p0-1p5_Cent%.0f-%.0f.root",centmin,centmax),Form("rootfiles/tnp_ntphi_Y1p5-2p0_Cent%.0f-%.0f.root",centmin,centmax),Form("rootfiles/tnp_ntphi_Y2p0-2p4_Cent%.0f-%.0f.root",centmin,centmax)};



	TString outname = Form("TNP2D_Bs_Cent_detailed%.0f-%.0f",centmin,centmax);


	TH1D* htnp_nominal_nominal[NRapBins];

	TH1D* htnp_total_nominal[NRapBins];
	TH1D* htnp_total_stat_d[NRapBins];
	TH1D* htnp_total_stat_u[NRapBins];
	TH1D* htnp_total_syst_d[NRapBins];
	TH1D* htnp_total_syst_u[NRapBins];

	TH1D* htnp_muid_nominal[NRapBins];
	TH1D* htnp_muid_stat_d[NRapBins];
	TH1D* htnp_muid_stat_u[NRapBins];
	TH1D* htnp_muid_syst_d[NRapBins];
	TH1D* htnp_muid_syst_u[NRapBins];

	TH1D* htnp_trg_nominal[NRapBins];
	TH1D* htnp_trg_stat_d[NRapBins];
	TH1D* htnp_trg_stat_u[NRapBins];
	TH1D* htnp_trg_syst_d[NRapBins];
	TH1D* htnp_trg_syst_u[NRapBins];

	TH1D* htnp_trk_nominal[NRapBins];
	TH1D* htnp_trk_stat_d[NRapBins];
	TH1D* htnp_trk_stat_u[NRapBins];
	TH1D* htnp_trk_syst_d[NRapBins];
	TH1D* htnp_trk_syst_u[NRapBins];

	TFile* infile[NRapBins];

	for(int i = 0; i < NRapBins; i++){

		infile[i] = new TFile(infilename[i].Data());
		htnp_nominal_nominal[i] =  (TH1D*) infile[i]->Get("htnp_nominal_nominal");

		htnp_total_nominal[i] =  (TH1D*) infile[i]->Get("htnp_total_nominal");
		htnp_total_stat_d[i] =  (TH1D*) infile[i]->Get("htnp_total_stat_d");
		htnp_total_stat_u[i] =  (TH1D*) infile[i]->Get("htnp_total_stat_u");
		htnp_total_syst_d[i] =  (TH1D*) infile[i]->Get("htnp_total_syst_d");
		htnp_total_syst_u[i] =  (TH1D*) infile[i]->Get("htnp_total_syst_u");

		htnp_muid_nominal[i] =  (TH1D*) infile[i]->Get("htnp_muid_nominal");
		htnp_muid_stat_d[i] =  (TH1D*) infile[i]->Get("htnp_muid_stat_d");
		htnp_muid_stat_u[i] =  (TH1D*) infile[i]->Get("htnp_muid_stat_u");
		htnp_muid_syst_d[i] =  (TH1D*) infile[i]->Get("htnp_muid_syst_d");
		htnp_muid_syst_u[i] =  (TH1D*) infile[i]->Get("htnp_muid_syst_u");

		htnp_trg_nominal[i] =  (TH1D*) infile[i]->Get("htnp_trg_nominal");
		htnp_trg_stat_d[i] =  (TH1D*) infile[i]->Get("htnp_trg_stat_d");
		htnp_trg_stat_u[i] =  (TH1D*) infile[i]->Get("htnp_trg_stat_u");
		htnp_trg_syst_d[i] =  (TH1D*) infile[i]->Get("htnp_trg_syst_d");
		htnp_trg_syst_u[i] =  (TH1D*) infile[i]->Get("htnp_trg_syst_u");

		htnp_trk_nominal[i] =  (TH1D*) infile[i]->Get("htnp_trk_nominal");
		htnp_trk_stat_d[i] =  (TH1D*) infile[i]->Get("htnp_trk_stat_d");
		htnp_trk_stat_u[i] =  (TH1D*) infile[i]->Get("htnp_trk_stat_u");
		htnp_trk_syst_d[i] =  (TH1D*) infile[i]->Get("htnp_trk_syst_d");
		htnp_trk_syst_u[i] =  (TH1D*) infile[i]->Get("htnp_trk_syst_u");

	}


	const int npt = 60;
	const int nY = 5;
	double ptbin[npt+1] = {5., 5.5, 6., 6.5, 7., 7.5, 8., 8.5, 9., 9.5, 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50., 51., 52., 53., 54., 55., 56., 57., 58., 59., 60.};
	//double ptbin[npt+1] = {5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50., 51., 52., 53., 54., 55., 56., 57., 58., 59., 60.};
	double Ybin[nY+1] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.4};
	double scale[npt][nY], syst_d[npt][nY], syst_u[npt][nY], stat_d[npt][nY], stat_u[npt][nY], total_d[npt][nY], total_u[npt][nY];
	double scalemuid[npt][nY], syst_dmuid[npt][nY], syst_umuid[npt][nY], stat_dmuid[npt][nY], stat_umuid[npt][nY], total_dmuid[npt][nY], total_umuid[npt][nY];
	double scaletrg[npt][nY], syst_dtrg[npt][nY], syst_utrg[npt][nY], stat_dtrg[npt][nY], stat_utrg[npt][nY], total_dtrg[npt][nY], total_utrg[npt][nY];
	double scaletrk[npt][nY], syst_dtrk[npt][nY], syst_utrk[npt][nY], stat_dtrk[npt][nY], stat_utrk[npt][nY], total_dtrk[npt][nY], total_utrk[npt][nY];


	TFile* outfile = new TFile(Form("%s.root",outname.Data()), "recreate");
	TH2D* tnp_scale = new TH2D("tnp_scale","",npt,ptbin,nY,Ybin);
	TH2D* tnp_total_d = new TH2D("tnp_total_d","",npt,ptbin,nY,Ybin);
	TH2D* tnp_total_u = new TH2D("tnp_total_u","",npt,ptbin,nY,Ybin);

	TH2D* tnp_muid_scale = new TH2D("tnp_muid_scal","",npt,ptbin,nY,Ybin);
	TH2D* tnp_muid_d = new TH2D("tnp_muid_d","",npt,ptbin,nY,Ybin);
	TH2D* tnp_muid_u = new TH2D("tnp_muid_u","",npt,ptbin,nY,Ybin);

	TH2D* tnp_trg_scale = new TH2D("tnp_trg_scal","",npt,ptbin,nY,Ybin);
	TH2D* tnp_trg_d = new TH2D("tnp_trg_d","",npt,ptbin,nY,Ybin);
	TH2D* tnp_trg_u = new TH2D("tnp_trg_u","",npt,ptbin,nY,Ybin);

	TH2D* tnp_trk_scale = new TH2D("tnp_trk_scal","",npt,ptbin,nY,Ybin);
	TH2D* tnp_trk_d = new TH2D("tnp_trk_d","",npt,ptbin,nY,Ybin);
	TH2D* tnp_trk_u = new TH2D("tnp_trk_u","",npt,ptbin,nY,Ybin);


	for(int i=0;i<npt;i++)
	{
		for(int j=0;j<nY;j++)
		{
			scale[i][j]=0;
			syst_d[i][j]=0;
			syst_u[i][j]=0;
			stat_d[i][j]=0;
			stat_u[i][j]=0;
			total_d[i][j]=0;
			total_u[i][j]=0;

			scalemuid[i][j]=0;
			syst_dmuid[i][j]=0;
			syst_umuid[i][j]=0;
			stat_dmuid[i][j]=0;
			stat_umuid[i][j]=0;
			total_dmuid[i][j]=0;
			total_umuid[i][j]=0;


			scaletrg[i][j]=0;
			syst_dtrg[i][j]=0;
			syst_utrg[i][j]=0;
			stat_dtrg[i][j]=0;
			stat_utrg[i][j]=0;
			total_dtrg[i][j]=0;
			total_utrg[i][j]=0;

			scaletrk[i][j]=0;
			syst_dtrk[i][j]=0;
			syst_utrk[i][j]=0;
			stat_dtrk[i][j]=0;
			stat_utrk[i][j]=0;
			total_dtrk[i][j]=0;
			total_utrk[i][j]=0;

		}
	}

	for(int i=0;i<npt;i++)
	{


		for(int j =0; j < NRapBins; j++){
			if(htnp_nominal_nominal[j]->GetBinContent(i+1)!=0){

				scale[i][j]=htnp_total_nominal[j]->GetBinContent(i+1)/htnp_nominal_nominal[j]->GetBinContent(i+1);
				syst_d[i][j]=TMath::Abs(htnp_total_syst_d[j]->GetBinContent(i+1)-htnp_total_nominal[j]->GetBinContent(i+1))/htnp_total_nominal[j]->GetBinContent(i+1);
				syst_u[i][j]=TMath::Abs(htnp_total_syst_u[j]->GetBinContent(i+1)-htnp_total_nominal[j]->GetBinContent(i+1))/htnp_total_nominal[j]->GetBinContent(i+1);
				stat_d[i][j]=TMath::Abs(htnp_total_stat_d[j]->GetBinContent(i+1)-htnp_total_nominal[j]->GetBinContent(i+1))/htnp_total_nominal[j]->GetBinContent(i+1);
				stat_u[i][j]=TMath::Abs(htnp_total_stat_u[j]->GetBinContent(i+1)-htnp_total_nominal[j]->GetBinContent(i+1))/htnp_total_nominal[j]->GetBinContent(i+1);
				total_d[i][j]=sqrt(stat_d[i][j]*stat_d[i][j]+syst_d[i][j]*syst_d[i][j]);
				total_u[i][j]=sqrt(stat_u[i][j]*stat_u[i][j]+syst_u[i][j]*syst_u[i][j]);

				scalemuid[i][j]=htnp_muid_nominal[j]->GetBinContent(i+1)/htnp_nominal_nominal[j]->GetBinContent(i+1);
				syst_dmuid[i][j]=TMath::Abs(htnp_muid_syst_d[j]->GetBinContent(i+1)-htnp_muid_nominal[j]->GetBinContent(i+1))/htnp_muid_nominal[j]->GetBinContent(i+1);
				syst_umuid[i][j]=TMath::Abs(htnp_muid_syst_u[j]->GetBinContent(i+1)-htnp_muid_nominal[j]->GetBinContent(i+1))/htnp_muid_nominal[j]->GetBinContent(i+1);
				stat_dmuid[i][j]=TMath::Abs(htnp_muid_stat_d[j]->GetBinContent(i+1)-htnp_muid_nominal[j]->GetBinContent(i+1))/htnp_muid_nominal[j]->GetBinContent(i+1);
				stat_umuid[i][j]=TMath::Abs(htnp_muid_stat_u[j]->GetBinContent(i+1)-htnp_muid_nominal[j]->GetBinContent(i+1))/htnp_muid_nominal[j]->GetBinContent(i+1);
				total_dmuid[i][j]=sqrt(stat_dmuid[i][j]*stat_dmuid[i][j]+syst_dmuid[i][j]*syst_dmuid[i][j]);
				total_umuid[i][j]=sqrt(stat_umuid[i][j]*stat_umuid[i][j]+syst_umuid[i][j]*syst_umuid[i][j]);

				scaletrg[i][j]=htnp_trg_nominal[j]->GetBinContent(i+1)/htnp_nominal_nominal[j]->GetBinContent(i+1);
				syst_dtrg[i][j]=TMath::Abs(htnp_trg_syst_d[j]->GetBinContent(i+1)-htnp_trg_nominal[j]->GetBinContent(i+1))/htnp_trg_nominal[j]->GetBinContent(i+1);
				syst_utrg[i][j]=TMath::Abs(htnp_trg_syst_u[j]->GetBinContent(i+1)-htnp_trg_nominal[j]->GetBinContent(i+1))/htnp_trg_nominal[j]->GetBinContent(i+1);
				stat_dtrg[i][j]=TMath::Abs(htnp_trg_stat_d[j]->GetBinContent(i+1)-htnp_trg_nominal[j]->GetBinContent(i+1))/htnp_trg_nominal[j]->GetBinContent(i+1);
				stat_utrg[i][j]=TMath::Abs(htnp_trg_stat_u[j]->GetBinContent(i+1)-htnp_trg_nominal[j]->GetBinContent(i+1))/htnp_trg_nominal[j]->GetBinContent(i+1);
				total_dtrg[i][j]=sqrt(stat_dtrg[i][j]*stat_dtrg[i][j]+syst_dtrg[i][j]*syst_dtrg[i][j]);
				total_utrg[i][j]=sqrt(stat_utrg[i][j]*stat_utrg[i][j]+syst_utrg[i][j]*syst_utrg[i][j]);

				scaletrk[i][j]=htnp_trk_nominal[j]->GetBinContent(i+1)/htnp_nominal_nominal[j]->GetBinContent(i+1);
				syst_dtrk[i][j]=TMath::Abs(htnp_trk_syst_d[j]->GetBinContent(i+1)-htnp_trk_nominal[j]->GetBinContent(i+1))/htnp_trk_nominal[j]->GetBinContent(i+1);
				syst_utrk[i][j]=TMath::Abs(htnp_trk_syst_u[j]->GetBinContent(i+1)-htnp_trk_nominal[j]->GetBinContent(i+1))/htnp_trk_nominal[j]->GetBinContent(i+1);
				stat_dtrk[i][j]=TMath::Abs(htnp_trk_stat_d[j]->GetBinContent(i+1)-htnp_trk_nominal[j]->GetBinContent(i+1))/htnp_trk_nominal[j]->GetBinContent(i+1);
				stat_utrk[i][j]=TMath::Abs(htnp_trk_stat_u[j]->GetBinContent(i+1)-htnp_trk_nominal[j]->GetBinContent(i+1))/htnp_trk_nominal[j]->GetBinContent(i+1);
				total_dtrk[i][j]=sqrt(stat_dtrk[i][j]*stat_dtrk[i][j]+syst_dtrk[i][j]*syst_dtrk[i][j]);
				total_utrk[i][j]=sqrt(stat_utrk[i][j]*stat_utrk[i][j]+syst_utrk[i][j]*syst_utrk[i][j]);

			}

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

			tnp_muid_scale->SetBinContent(i+1,j+1,scalemuid[i][j]);
			tnp_muid_d->SetBinContent(i+1,j+1,total_dmuid[i][j]);
			tnp_muid_u->SetBinContent(i+1,j+1,total_umuid[i][j]);

			tnp_trg_scale->SetBinContent(i+1,j+1,scaletrg[i][j]);
			tnp_trg_d->SetBinContent(i+1,j+1,total_dtrg[i][j]);
			tnp_trg_u->SetBinContent(i+1,j+1,total_utrg[i][j]);

			tnp_trk_scale->SetBinContent(i+1,j+1,scaletrk[i][j]);
			tnp_trk_d->SetBinContent(i+1,j+1,total_dtrk[i][j]);
			tnp_trk_u->SetBinContent(i+1,j+1,total_utrk[i][j]);

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


	tnp_muid_scale->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_muid_scale->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_muid_scale->GetYaxis()->SetTitleOffset(1.5);
	tnp_muid_scale->GetXaxis()->CenterTitle();
	tnp_muid_scale->GetYaxis()->CenterTitle();

	tnp_muid_d->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_muid_d->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_muid_d->GetYaxis()->SetTitleOffset(1.5);
	tnp_muid_d->GetXaxis()->CenterTitle();
	tnp_muid_d->GetYaxis()->CenterTitle();

	tnp_muid_u->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_muid_u->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_muid_u->GetYaxis()->SetTitleOffset(1.5);
	tnp_muid_u->GetXaxis()->CenterTitle();
	tnp_muid_u->GetYaxis()->CenterTitle();



	tnp_trg_scale->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_trg_scale->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_trg_scale->GetYaxis()->SetTitleOffset(1.5);
	tnp_trg_scale->GetXaxis()->CenterTitle();
	tnp_trg_scale->GetYaxis()->CenterTitle();

	tnp_trg_d->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_trg_d->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_trg_d->GetYaxis()->SetTitleOffset(1.5);
	tnp_trg_d->GetXaxis()->CenterTitle();
	tnp_trg_d->GetYaxis()->CenterTitle();

	tnp_trg_u->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_trg_u->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_trg_u->GetYaxis()->SetTitleOffset(1.5);
	tnp_trg_u->GetXaxis()->CenterTitle();
	tnp_trg_u->GetYaxis()->CenterTitle();



	tnp_trk_scale->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_trk_scale->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_trk_scale->GetYaxis()->SetTitleOffset(1.5);
	tnp_trk_scale->GetXaxis()->CenterTitle();
	tnp_trk_scale->GetYaxis()->CenterTitle();

	tnp_trk_d->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_trk_d->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_trk_d->GetYaxis()->SetTitleOffset(1.5);
	tnp_trk_d->GetXaxis()->CenterTitle();
	tnp_trk_d->GetYaxis()->CenterTitle();

	tnp_trk_u->GetXaxis()->SetTitle("B^{+} p_{T} (GeV/c)");
	tnp_trk_u->GetYaxis()->SetTitle("B^{+} |y|");
	tnp_trk_u->GetYaxis()->SetTitleOffset(1.5);
	tnp_trk_u->GetXaxis()->CenterTitle();
	tnp_trk_u->GetYaxis()->CenterTitle();


	TCanvas* ctnp = new TCanvas("","",600,600);
	ctnp->cd();
	tnp_scale->Draw("COLZ");
	ctnp->SaveAs(Form("NewPlots/png/%s.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s.pdf",outname.Data()));

	tnp_total_d->Draw("COLZ"); 
	ctnp->SaveAs(Form("NewPlots/png/%s_down.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_down.pdf",outname.Data()));

	tnp_total_u->Draw("COLZ"); 
	ctnp->SaveAs(Form("NewPlots/png/%s_up.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_up.pdf",outname.Data())); 



	tnp_muid_scale->Draw("COLZ");
	ctnp->SaveAs(Form("NewPlots/png/%s_muid.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_muid.pdf",outname.Data()));

	tnp_muid_d->Draw("COLZ"); 
	ctnp->SaveAs(Form("NewPlots/png/%s_down_muid.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_down_muid.pdf",outname.Data()));

	tnp_muid_u->Draw("COLZ"); 
	ctnp->SaveAs(Form("NewPlots/png/%s_up_muid.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_up_muid.pdf",outname.Data())); 


	tnp_trg_scale->Draw("COLZ");
	ctnp->SaveAs(Form("NewPlots/png/%s_trg.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_trg.pdf",outname.Data()));

	tnp_trg_d->Draw("COLZ"); 
	ctnp->SaveAs(Form("NewPlots/png/%s_down_trg.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_down_trg.pdf",outname.Data()));

	tnp_trg_u->Draw("COLZ"); 
	ctnp->SaveAs(Form("NewPlots/png/%s_up_trg.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_up_trg.pdf",outname.Data())); 



	tnp_trk_scale->Draw("COLZ");
	ctnp->SaveAs(Form("NewPlots/png/%s_trk.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_trk.pdf",outname.Data()));

	tnp_trk_d->Draw("COLZ"); 
	ctnp->SaveAs(Form("NewPlots/png/%s_down_trk.png",outname.Data()));
	ctnp->SaveAs(Form("%s_down_trk.pdf",outname.Data()));

	tnp_trk_u->Draw("COLZ"); 
	ctnp->SaveAs(Form("NewPlots/png/%s_up_trk.png",outname.Data()));
	ctnp->SaveAs(Form("NewPlots/pdf/%s_up_trk.pdf",outname.Data())); 



	outfile->cd();
	tnp_scale->Write();
	tnp_total_d->Write();
	tnp_total_u->Write();

	tnp_muid_scale->Write();
	tnp_muid_d->Write();
	tnp_muid_u->Write();

	tnp_trg_scale->Write();
	tnp_trg_d->Write();
	tnp_trg_u->Write();


	tnp_trk_scale->Write();
	tnp_trk_d->Write();
	tnp_trk_u->Write();



	outfile->Close();

	return;
}

int main()
{
	numberdetailed();
	return 1;
}
