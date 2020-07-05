#include <map>
#include <vector>
#include <string>

namespace tnpcc
{
  const int filterId = 1; // * filterId = 1: Jpsi L3 filter
  std::map<int, std::string> idxname = {
    std::pair<int, std::string>(-1, "syst_u"),
    std::pair<int, std::string>(-2, "syst_d"),
    std::pair<int, std::string>(+1, "stat_u"),
    std::pair<int, std::string>(+2, "stat_d"),
    std::pair<int, std::string>(0, "nominal"),
  };
  const std::vector<std::string> types = {"nominal", "trg", "trk", "muid", "total"};
  std::map<std::string, Color_t> typecolor = {
    std::pair<std::string, Color_t>("nominal", kBlack),
    std::pair<std::string, Color_t>("trg", xjjroot::mycolor_middle["azure"]),
    std::pair<std::string, Color_t>("trk", xjjroot::mycolor_middle["red"]),
    std::pair<std::string, Color_t>("muid", xjjroot::mycolor_middle["green"]),
    std::pair<std::string, Color_t>("total", xjjroot::mycolor_middle["yellow"]),
  };
  std::map<std::string, Style_t> idxstyle = {
    std::pair<std::string, Style_t>("syst_u", 2),
    std::pair<std::string, Style_t>("syst_d", 2),
    std::pair<std::string, Style_t>("stat_u", 4),
    std::pair<std::string, Style_t>("stat_d", 4),
    std::pair<std::string, Style_t>("nominal", 1),
  };
  std::vector<std::string> err({"stat", "syst"});
  //float ptbins[] = {15., 50.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  //float ptbins[] = {5., 7., 10., 15., 20., 30., 50., 60.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  //float ptbins[] = {5., 7., 10., 15., 20., 30., 40., 50., 60.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  //float ptbins[] = {5., 10., 15., 20., 30., 40., 50.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  //float ptbins[] = {7., 10., 15., 20., 30., 50.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  //float ptbins[] = {5., 10., 15., 20., 50.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  //float ptbins[] = {5., 50.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  double ptbins[] = {5., 5.5, 6., 6.5, 7., 7.5, 8., 8.5, 9., 9.5, 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50., 51., 52., 53., 54., 55., 56., 57., 58., 59., 60.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  //double ptbins[] = {5., 6., 7., 8., 9., 10., 11., 12., 13., 14., 15., 16., 17., 18., 19., 20., 21., 22., 23., 24., 25., 26., 27., 28., 29., 30., 31., 32., 33., 34., 35., 36., 37., 38., 39., 40., 41., 42., 43., 44., 45., 46., 47., 48., 49., 50., 51., 52., 53., 54., 55., 56., 57., 58., 59., 60.}; int nptbins = sizeof(ptbins)/sizeof(ptbins[0]) - 1;
  double Ybins[] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.4}; int nYbins = sizeof(Ybins)/sizeof(Ybins[0]) - 1;
}
