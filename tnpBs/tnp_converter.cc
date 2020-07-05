#ifndef __OPTCUT__
#define __OPTCUT__

#include <iostream>
#include <map>
#include <string>
#include <TFile.h>
#include <TH1D.h>
#include <TSystem.h>

#include "tnp_weight_lowptPbPb.h"
#include "packtree.h"
//#include "ntuple.h"
#include "fitX.h"
#include "xjjcuti.h"

#include "tnpcc.h"

void tnp_converter(int CentMin, int CentMax, int RapBin)
{

	double RapMin;
	double RapMax;
	int index1;
	int index2;
	int index3;
	int index4;

	if(RapBin == 0){
		RapMin = 0; 
		RapMax = 0.5;
		index1 = 0;
		index2 = 0;
		index3 = 0;
		index4 = 5;

	}

	if(RapBin == 1){
		RapMin = 0.5; 
		RapMax = 1.0;
		index1 = 0;
		index2 = 5;
		index3 = 1;
		index4 = 0;

	
	}
	

	if(RapBin == 2){
		RapMin = 1.0; 
		RapMax = 1.5;
		index1 = 1;
		index2 = 0;
		index3 = 1;
		index4 = 5;

	
	}
	

	if(RapBin == 3){
		RapMin = 1.5; 
		RapMax = 2.0;

		index1 = 1;
		index2 = 5;
		index3 = 2;
		index4 = 0;

	
	}

	if(RapBin == 4){
		RapMin = 2.0; 
		RapMax = 2.4;
		index1 = 2;
		index2 = 0;
		index3 = 2;
		index4 = 4;

	
	}

	
	int nevt=-1;
	std::string inputname ="/export/d00/scratch/zzshi/CMSSW_7_5_8_patch3/Merge/2018Ana/Samples/FinalAnaSamples/PrivateMC-Data-Official-SemiFinal/MC_Bs_PbPb_TMVA_BDT_PbPb.root";
	TString outputname = Form("rootfiles/tnp_ntphi_Y%dp%d-%dp%d_Cent%d-%d.root",index1,index2,index3,index4,CentMin,CentMax);
	gSystem->Exec("mkdir -p rootfiles");

	std::cout<<"==> Opening files"<<std::endl;
	std::cout<<"input: "<<inputname<<std::endl;
	std::cout<<"output: "<<outputname.Data()<<std::endl;

	std::cout<<"==> Building histograms"<<std::endl;
	std::map<std::string, std::map<std::string, TH1D*>> hh;
	std::map<std::string, std::map<std::string, double>> scales;
	for(auto& tt : tnpcc::types)
	{
		for(auto& idxk : tnpcc::idxname)
		{
			hh[tt][idxk.second] = new TH1D(Form("htnp_%s_%s", tt.c_str(), idxk.second.c_str()), ";p_{T} (GeV/c);", tnpcc::nptbins, tnpcc::ptbins);
			hh[tt][idxk.second]->Sumw2();
		}
	}

	TFile* fin = TFile::Open(inputname.c_str());



	//Manually Introduced Trees//

	const int NCand = 20000;

	TTree * ntGen = (TTree * ) fin->Get("Bfinder/ntGen");
	TTree * ntphi = (TTree * ) fin->Get("Bfinder/ntphi");
	TTree * BDT1 = (TTree * ) fin->Get("BDT_pt_5_10");
	TTree * BDT2 = (TTree * ) fin->Get("BDT_pt_10_15");
	TTree * BDT3 = (TTree * ) fin->Get("BDT_pt_15_20");
	TTree * BDT4 = (TTree * ) fin->Get("BDT_pt_20_50");
	TTree * ntHi = (TTree * ) fin->Get("hiEvtAnalyzer/HiTree");
	TTree * ntSkim = (TTree * ) fin->Get("skimanalysis/HltTree");
	TTree * ntHlt = (TTree *) fin->Get("hltanalysis/HltTree");
	TTree * CentWeightTree = (TTree *) fin->Get("CentWeightTree");


	Double_t CentWeight;
	CentWeightTree->SetBranchAddress("CentWeight",&CentWeight);


	Int_t   Bsize;
	Float_t Btrk1Pt[NCand];
	Float_t Btrk2Pt[NCand];

	Float_t Btrk1PtErr[NCand];
	Float_t Btrk2PtErr[NCand];


	Float_t Bchi2cl[NCand];
	Float_t BsvpvDistance[NCand];
	Float_t BsvpvDisErr[NCand];
	Float_t Bpt[NCand];
	Float_t Btrk1Eta[NCand];
	Float_t Btrk2Eta[NCand];
	Float_t By[NCand];


	Float_t Bmass[NCand];


	Float_t Bmumumass[NCand];
	Float_t Bmu1eta[NCand];
	Float_t Bmu1pt[NCand];
	Float_t Bmu2eta[NCand];
	Float_t Bmu2pt[NCand];

	Bool_t Bmu1TMOneStationTight[NCand];
	Int_t Bmu1InPixelLayer[NCand];
	Int_t Bmu1InStripLayer[NCand];

	Bool_t Bmu2TMOneStationTight[NCand];	
	Int_t Bmu2InPixelLayer[NCand];
	Int_t Bmu2InStripLayer[NCand];


	Bool_t Bmu1isGlobalMuon[NCand];
	Bool_t Bmu2isGlobalMuon[NCand];


	Bool_t Bmu1isTrackerMuon[NCand];
	Bool_t Bmu2isTrackerMuon[NCand];

	Float_t Bmu1dxyPV[NCand];
	Float_t Bmu2dxyPV[NCand];

	Float_t Bmu1dzPV[NCand];
	Float_t Bmu2dzPV[NCand];

	Bool_t Btrk1highPurity[NCand];
	Bool_t Btrk2highPurity[NCand];

	Float_t Btktkmass[NCand];

	Float_t Btrk1PixelHit[NCand];
	Float_t Btrk2PixelHit[NCand];

	Float_t Btrk1StripHit[NCand];
	Float_t Btrk2StripHit[NCand];

	Float_t Btrk1Chi2ndf[NCand];
	Float_t Btrk2Chi2ndf[NCand];


	Float_t Btrk1nStripLayer[NCand];
	Float_t Btrk2nStripLayer[NCand];

	Float_t Btrk1nPixelLayer[NCand];
	Float_t Btrk2nPixelLayer[NCand];


	Double_t BDT_pt_5_10[NCand];
	Double_t BDT_pt_10_15[NCand];
	Double_t BDT_pt_15_20[NCand];
	Double_t BDT_pt_20_50[NCand];

	Float_t Bgen[NCand];

	int HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1;

	ntHlt->SetBranchAddress("HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1",&HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1);


	int run;
	int lumi;
	int evt;
	int hiBin;
	Float_t PVz;
	Int_t pclusterCompatibilityFilter;
	Int_t pprimaryVertexFilter;
	Int_t phfCoincFilter2Th4;

	ntHi->SetBranchAddress("hiBin",&hiBin);



	ntSkim->SetBranchAddress("pclusterCompatibilityFilter",&pclusterCompatibilityFilter);
	ntSkim->SetBranchAddress("pprimaryVertexFilter",&pprimaryVertexFilter);
	ntSkim->SetBranchAddress("phfCoincFilter2Th4",&phfCoincFilter2Th4);


	ntphi->SetBranchAddress("Bsize",&Bsize);
	ntphi->SetBranchAddress("PVz",&PVz);
	ntphi->SetBranchAddress("Btrk1Pt",Btrk1Pt);
	ntphi->SetBranchAddress("Btrk2Pt",Btrk2Pt);
	ntphi->SetBranchAddress("Btrk1PtErr",Btrk1PtErr);
	ntphi->SetBranchAddress("Btrk2PtErr",Btrk2PtErr);
	ntphi->SetBranchAddress("Bchi2cl",Bchi2cl);
	ntphi->SetBranchAddress("BsvpvDistance",BsvpvDistance);
	ntphi->SetBranchAddress("BsvpvDisErr",BsvpvDisErr);
	ntphi->SetBranchAddress("Bpt",Bpt);
	ntphi->SetBranchAddress("By",By);
	ntphi->SetBranchAddress("Btrk1Eta",Btrk1Eta);
	ntphi->SetBranchAddress("Btrk2Eta",Btrk2Eta);
	ntphi->SetBranchAddress("Bmass",Bmass);


	ntphi->SetBranchAddress("Bmumumass",Bmumumass);
	ntphi->SetBranchAddress("Bmu1eta",Bmu1eta);
	ntphi->SetBranchAddress("Bmu2eta",Bmu2eta);
	ntphi->SetBranchAddress("Bmu1pt",Bmu1pt);
	ntphi->SetBranchAddress("Bmu2pt",Bmu2pt);

	ntphi->SetBranchAddress("Bmu1TMOneStationTight",Bmu1TMOneStationTight);
	ntphi->SetBranchAddress("Bmu1InPixelLayer",Bmu1InPixelLayer);
	ntphi->SetBranchAddress("Bmu1InStripLayer",Bmu1InStripLayer);

	ntphi->SetBranchAddress("Bmu2TMOneStationTight",Bmu2TMOneStationTight);
	ntphi->SetBranchAddress("Bmu2InPixelLayer",Bmu2InPixelLayer);
	ntphi->SetBranchAddress("Bmu2InStripLayer",Bmu2InStripLayer);


	ntphi->SetBranchAddress("Bmu1isGlobalMuon",Bmu1isGlobalMuon);
	ntphi->SetBranchAddress("Bmu2isGlobalMuon",Bmu2isGlobalMuon);

	ntphi->SetBranchAddress("Bmu1isTrackerMuon",Bmu1isTrackerMuon);
	ntphi->SetBranchAddress("Bmu2isTrackerMuon",Bmu2isTrackerMuon);


	ntphi->SetBranchAddress("Bmu1dxyPV",Bmu1dxyPV);
	ntphi->SetBranchAddress("Bmu2dxyPV",Bmu2dxyPV);
	ntphi->SetBranchAddress("Bmu1dzPV",Bmu1dzPV);
	ntphi->SetBranchAddress("Bmu2dzPV",Bmu2dzPV);


	ntphi->SetBranchAddress("Btrk1highPurity",Btrk1highPurity);
	ntphi->SetBranchAddress("Btrk2highPurity",Btrk2highPurity);

	ntphi->SetBranchAddress("Btktkmass",Btktkmass);


	ntphi->SetBranchAddress("Btrk1PixelHit",Btrk1PixelHit);
	ntphi->SetBranchAddress("Btrk2PixelHit",Btrk2PixelHit);
	ntphi->SetBranchAddress("Btrk1StripHit",Btrk1StripHit);
	ntphi->SetBranchAddress("Btrk2StripHit",Btrk2StripHit);



	ntphi->SetBranchAddress("Btrk1Chi2ndf",Btrk1Chi2ndf);
	ntphi->SetBranchAddress("Btrk2Chi2ndf",Btrk2Chi2ndf);

	ntphi->SetBranchAddress("Bgen",Bgen);


	ntphi->SetBranchAddress("Btrk1nStripLayer",Btrk1nStripLayer);	
	ntphi->SetBranchAddress("Btrk2nStripLayer",Btrk2nStripLayer);
	ntphi->SetBranchAddress("Btrk1nPixelLayer",Btrk1nPixelLayer);
	ntphi->SetBranchAddress("Btrk2nPixelLayer",Btrk2nPixelLayer);

	BDT1->SetBranchAddress("BDT_pt_5_10",BDT_pt_5_10);
	BDT2->SetBranchAddress("BDT_pt_10_15",BDT_pt_10_15);
	BDT3->SetBranchAddress("BDT_pt_15_20",BDT_pt_15_20);
	BDT4->SetBranchAddress("BDT_pt_20_50",BDT_pt_20_50);


	float pthatweight;
	int Pass = 0;

	ntHi->SetBranchAddress("pthatweight",&pthatweight);

	int NEvents = ntphi->GetEntries();
	//NEvents = 100;
	std::cout<<"==> Scaning file"<<std::endl;
	//  int nentries = (nevt>0&&nevt<ntp->getnt()->GetEntries())?nevt:ntp->getnt()->GetEntries();
	for(int i=0; i<NEvents; i++)
	{
		if(i%1000 == 0) { xjjc::progressbar(i, NEvents); }
		ntHlt->GetEntry(i);
		ntphi->GetEntry(i);
		ntSkim->GetEntry(i);
		ntHi->GetEntry(i);
		BDT1->GetEntry(i);
		BDT2->GetEntry(i);
		BDT3->GetEntry(i);
		BDT4->GetEntry(i);
		CentWeightTree->GetEntry(i);

		float weight;

		//  if(!ntp->passedevtfil()) continue;
		for(int j=0; j<Bsize; j++)
		{
			// if(!(ntp->Bgen[j]>=23333 && ntp->BgencollisionId[j]==0)) continue;
			//     if(!(ntp->Bgen[j]==23333 && ntp->Btrk1Pt[j]>1.0 && ntp->Btrk2Pt[j]>1.0 && ntp->Bpt[j]>5.0 && (ntp->BsvpvDistance[j]/ntp->BsvpvDisErr[j])>2.0 && ntp->Bchi2cl[j]>0.05 && TMath::Abs(ntp->Btrk1Eta[j])<2.4 && TMath::Abs(ntp->Btrk2Eta[j])<2.4 && TMath::Abs(ntp->By[j])<2.4 && TMath::Abs(ntp->PVz)<15 && ntp->Bmass[j]>5 && ntp->Bmass[j]<6 && TMath::Abs(ntp->Bmumumass[j]-3.096916)<0.15 && ntp->Bmu1SoftMuID[j] && ntp->Bmu2SoftMuID[j] && ntp->Bmu1isAcc[j] && ntp->Bmu2isAcc[j] && ntp->Bmu1isTriggered[j] && ntp->Bmu2isTriggered[j] && ntp->Btrk1highPurity[j] && ntp->Btrk2highPurity[j]  && (ntp->Btrk1PixelHit[j]+ntp->Btrk1StripHit[j])>=11 && (ntp->Btrk2PixelHit[j]+ntp->Btrk2StripHit[j])>=11 && (ntp->Btrk1Chi2ndf[j]/(ntp->Btrk1nStripLayer[j]+ntp->Btrk1nPixelLayer[j]))<0.18 && (ntp->Btrk2Chi2ndf[j]/(ntp->Btrk2nStripLayer[j]+ntp->Btrk2nPixelLayer[j]))<0.18 && TMath::Abs(ntp->Btrk1PtErr[j]/ntp->Btrk1Pt[j])<0.1 && TMath::Abs(ntp->Btrk2PtErr[j]/ntp->Btrk2Pt[j])<0.1)) continue;
			//	  if(!( (ntp->Bpt[j]>7 && ntp->Bpt[j]<10 && ntp->BDT_7_10[j]>0.32) || (ntp->Bpt[j]>10 && ntp->Bpt[j]<15 && ntp->BDT_10_15[j]>0.29) || (ntp->Bpt[j]>15 && ntp->Bpt[j]<20 && ntp->BDT_15_20[j]>0.35) || (ntp->Bpt[j]>20 && ntp->Bpt[j]<50 && ntp->BDT_20_50[j]>0.33) ) ) continue;
			//	  if(!(TMath::Abs(ntp->By[j])>0.0 && TMath::Abs(ntp->By[j])<0.5)) continue;
			if(!((HLT_HIL3Mu0NHitQ10_L2Mu0_MAXdR3p5_M1to5_v1 == 1) && (Bpt[j] > 7 && Bpt[j] < 50) && (((hiBin < 181) && Btrk1Pt[j] > 0.9 && Btrk2Pt[j] > 0.9 && Bchi2cl[j] > 0.05 && BsvpvDistance[j]/BsvpvDisErr[j] > 2.0 && Bpt[j] > 5 && abs(Btrk1Eta[j]-0.0) < 2.4 && abs(Btrk2Eta[j]-0.0) < 2.4 && (TMath::Abs(By[j])<2.4&&TMath::Abs(Bmumumass[j]-3.096916)<0.15&&((abs(Bmu1eta[j])<1.2&&Bmu1pt[j]>3.5)||(abs(Bmu1eta[j])>1.2&&abs(Bmu1eta[j])<2.1&&Bmu1pt[j]>(5.47-1.89*abs(Bmu1eta[j])))||(abs(Bmu1eta[j])>2.1&&abs(Bmu1eta[j])<2.4&&Bmu1pt[j]>1.5))&&((abs(Bmu2eta[j])<1.2&&Bmu2pt[j]>3.5)||(abs(Bmu2eta[j])>1.2&&abs(Bmu2eta[j])<2.1&&Bmu2pt[j]>(5.47-1.89*abs(Bmu2eta[j])))||(abs(Bmu2eta[j])>2.1&&abs(Bmu2eta[j])<2.4&&Bmu2pt[j]>1.5))&&Bmu1TMOneStationTight[j]&&Bmu2TMOneStationTight[j]&&Bmu1InPixelLayer[j]>0&&(Bmu1InPixelLayer[j]+Bmu1InStripLayer[j])>5&&Bmu2InPixelLayer[j]>0&&(Bmu2InPixelLayer[j]+Bmu2InStripLayer[j])>5&&Bmu1dxyPV[j]<0.3&&Bmu2dxyPV[j]<0.3&&Bmu1dzPV[j]<20&&Bmu2dzPV[j]<20&&Bmu1isTrackerMuon[j]&&Bmu2isTrackerMuon[j]&&Bmu1isGlobalMuon[j]&&Bmu2isGlobalMuon[j]&&Btrk1highPurity[j]&&Btrk2highPurity[j]&&abs(Btrk1Eta[j])<2.4&&abs(Btrk2Eta[j])<2.4&&Btrk1Pt[j]>1.&&Btrk2Pt[j]>1.&&abs(Btktkmass[j]-1.019455)<0.015) && (abs(PVz)<15&&pclusterCompatibilityFilter == 1 &&pprimaryVertexFilter == 1) && (Btrk1PixelHit[j] + Btrk1StripHit[j] > 10) && (Btrk2PixelHit[j] + Btrk2StripHit[j] > 10) && (Btrk1PtErr[j]/Btrk1Pt[j] < 0.1)&& (Btrk2PtErr[j]/Btrk2Pt[j] < 0.1) && Btrk1Chi2ndf[j]/(Btrk1nStripLayer[j]+Btrk1nPixelLayer[j]) < 0.18 && Btrk2Chi2ndf[j]/(Btrk2nStripLayer[j]+Btrk2nPixelLayer[j]) < 0.18&&((Bpt[j]>5&&Bpt[j]<10&&BDT_pt_5_10[j]>0.32 )||(Bpt[j]>10&&Bpt[j]<15&&BDT_pt_10_15[j]> 0.29)||(Bpt[j]>15&&Bpt[j]<20&&BDT_pt_15_20[j]>0.35)||(Bpt[j]>20&&Bpt[j]<50&&BDT_pt_20_50[j]>0.33))&&abs(PVz)<15&&pclusterCompatibilityFilter == 1 &&pprimaryVertexFilter == 1 && phfCoincFilter2Th4 == 1) && (Bmass[j] > 5 &&Bmass[j] < 6 && hiBin >= CentMin * 2&& hiBin <= CentMax * 2 && Bgen[j] == 23333 )) )) continue;
			//if(!(TMath::Abs(By[j])>RapMin && TMath::Abs(By[j])<RapMax)) continue;
				

			Pass = Pass + 1;

			weight = pthatweight * CentWeight * ((0.163562 * TMath::Exp(- 0.021039 * (PVz - 0.426587)*(PVz - 0.426587)))/(0.159629 * TMath::Exp(- 0.020014 * (PVz - 0.589381)*(PVz - 0.589381))));

			for(auto& idxk : tnpcc::idxname)
			{
				scales["nominal"][idxk.second] = 1.;
				scales["muid"][idxk.second] = tnp_weight_muid_pbpb(Bmu1pt[j], Bmu1eta[j], idxk.first)                 * tnp_weight_muid_pbpb(Bmu2pt[j], Bmu2eta[j], idxk.first); 
				scales["trk"][idxk.second]  = tnp_weight_trk_pbpb(Bmu1eta[j], idxk.first)                                  * tnp_weight_trk_pbpb(Bmu2eta[j], idxk.first); 
				scales["trg"][idxk.second]  = tnp_weight_trg_pbpb(Bmu1pt[j], Bmu1eta[j], tnpcc::filterId, idxk.first) * tnp_weight_trg_pbpb(Bmu2pt[j],Bmu2eta[j], tnpcc::filterId, idxk.first); 
				scales["total"][idxk.second] = scales["muid"][idxk.second] * scales["trk"][idxk.second] * scales["trg"][idxk.second];

				//
				for(auto& tt : tnpcc::types)
				{
					//cout << "weight = " << weight << "   scales = " << scales[tt][idxk.second] << endl;
					hh[tt][idxk.second]->Fill(Bpt[j], weight*scales[tt][idxk.second]);
				}
			}
			// <==
		}
	}
	xjjc::progressbar_summary(NEvents);
	
	cout << "Pass = " << Pass << endl;
	std::cout<<"==> Writing into output file"<<std::endl;
	TFile* outf = new TFile(outputname.Data(), "recreate");
	outf->cd();
	for(auto& ht : hh)
	{
		for(auto& hk : ht.second)
		{
			std::cout<<"\e[2m"<<"writing \e[0m"<<hk.second->GetName()<<" \e[36;1m("<<(int)hk.second->GetEntries()<<")\e[0m"<<std::endl;
			hk.second->Write();
		}
	}
	outf->Close();
	std::cout<<"==> Output file"<<std::endl;
	std::cout<<outputname.Data()<<std::endl;
}

#endif

// +++++++++++++++++++++++++++++++++++++++
// - Trigger: (tnp_weight_trg_pbpb)
//   * filterId = 0: Jpsi L2 filter
//   * filterId = 1: Jpsi L3 filter
//   * filterId = 2: Upsi L2 filter
//   * filterId = 3: Upsi L3 filter
//   * idx = 0:  nominal
//   * idx = -1: syst variation, +1 sigma
//   * idx = -2: syst variation, -1 sigma
//   * idx = +1: stat variation, +1 sigma
//   * idx = +2: stat variation, -1 sigma
// - MuID: (tnp_weight_muid_pbpb)
//   * idx = 0:  nominal
//   * idx = -1: syst variation, +1 sigma
//   * idx = -2: syst variation, -1 sigma
//   * idx = +1: stat variation, +1 sigma
//   * idx = +2: stat variation, -1 sigma
// - Inner tracking: (tnp_weight_trk_pbpb)
//   * idx = 0:  nominal
//   * idx = -1: syst variation, +1 sigma
//   * idx = -2: syst variation, -1 sigma
//   * idx = +1: stat variation, +1 sigma
//   * idx = +2: stat variation, -1 sigma
// +++++++++++++++++++++++++++++++++++++++
