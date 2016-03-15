#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words);
    bool judge(const std::string &, const std::string &);
};

std::vector<std::vector<int>> Solution::palindromePairs(std::vector<std::string> &words)
{
    std::vector<std::vector<int>> resultVec;
    std::vector<int> tempVec;
    for (unsigned int i = 0; i < words.size(); ++i)
        for (unsigned int j = i + 1; j < words.size(); ++j) {
            if (i == j)
                continue;
            if (judge(words.at(i), words.at(j))) {
                tempVec.push_back(i);
                tempVec.push_back(j);
                std::vector<int> tempObj = tempVec;
                resultVec.push_back(tempObj);
                tempVec.clear();
            }
            if (judge(words.at(j), words.at(i))) {
                tempVec.push_back(j);
                tempVec.push_back(i);
                std::vector<int> tempObj = tempVec;
                resultVec.push_back(tempObj);
                tempVec.clear();                
            }
        }
    return resultVec;
}
bool Solution::judge(const std::string &a, const std::string &b)
{
    //std::cout<<"a.size="<<a.size()<<", b.size="<<b.size()<<std::endl;

    if (a.size() == 0 && b.size() == 0)
        return true;
    std::string c = a + b;
    std::string::size_type c_len = c.size();
    //std::cout<<"c.size() = "<<c_len<<std::endl;
    
    unsigned int half = static_cast<int>((c_len-1) / 2);
    for (unsigned int i = 0; i <= half; ++i) {
        //std::cout<<"i = "<< i <<", c.size()-i = "<<c.size()-i<<std::endl;
        if (i == c.size() - i - 1)
            continue;
        if (c.at(i) != c.at(c.size() - i - 1))
            return false;
    }
    return true;
}


void printRes(std::vector<std::vector<int>> &elem)
{
    std::cout<<"show: "<<std::endl;
    for (unsigned int i = 0; i < elem.size(); i++) {
        for (auto it : elem.at(i))
            std::cout << it << ", ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

int main()
{
    Solution tempObj;

    std::vector<std::string> tempData1 = {"bat", "tab", "cat"};
    std::vector<std::string> tempData2 = {"abcd", "dcba", "lls", "s", "sssll"};

    std::vector<std::vector<int>> result2;
    //std::vector<std::vector<int>> result2;

    result2 = tempObj.palindromePairs(tempData2);

    printRes(result2);

    //printRes(result2);
    return 0;
}

//std::vector<std::string> data3 = {"jeibbei","ejigddgfaccaeaefj","dibgebic","ceafffbddjafdd","ciieaefjfadcc","b","bdjcjcdaecg","abidfjfbfgdghabbj","jgfi","ccjgg","deciiggdjchfa","bbddf","bcjejjfibjgiffbdc","eb","dea","hgibfedfhafi","hfjj","gicaeacdfg","daaaa","ej","icahhehghgc","gdhig","afdcbjbf","ehhjadffbjjbbifddhee","hefeg","babjfeb","heieifgjdeggigbigah","idgib","ajjfcehgbghcd","bhjigjaagiacbiagb","ifhgdebjefefjc","ibcjh","eij","hjbgadhha","c","hbjhdb","bibeadagceajbfhbfff","bd","dda","ggeabib","ggicfdcdbcdfdiffdb","ggdhjhbbjfcbdaibbhji","gbghehjb","hbdecgf","ffbb","dghfedeghafcggg","aeficcbjjee","efbdcfcgaedgjfc","babihg","aai","jhbhh","hdccajghfjaac","hidaccecfhjhcfjaac","ijdcdahjehhefbdjfggd","aibhjhafcf","icjejdijgddb","gefcege","ffibafabj","ihbf","bc","icjdcg","fdfcfbgdhfjibecgidij","daeebcjadjfgib","gafbd","jhajceicjbgehebheh","fagjigi","bcgegggbjd","hhchd","hchaj","efefgbacff","bbifiihggegff","f","hfdfbbf","gaa","chj","jacdbhcca","gjgc","jffaaj","gacbgaiiiajcedb","agdgagf","jjd","jgdgedjdhacdbig","ceagfcgf","bfifgfa","faicdhacaa","hhgfcgabhhhgcci","cddadaijjgjjb","fjjciacciga","fic","dahebafcgjbchahagbd","ihjahjidiaicecfhjj","cc","ae","dhbigecf","fhifcbhhhcac","fcjjdjhbi","ghiedjfdi","bjbfbajjjjgehaijd","gdbhb","fhhggabajghjggeigdi","cdj","hej","hagcdd","ebacaa","gf","hhfeiafhaga","aeedbdfbichhef","iaf","cbgghaic","ifcfeaf","hhjeeecaddj","dbiajbc","haeedbe","difgbfgjfjbgbahjge","gcfjd","ehdhi","bbbgjhbcfdgb","jgfefdcgcchgcdddfgdi","fcafhbjdhbffhj","edfbbaadgefijbi","ibgbbbhbf","e","hjfciccjcicdgbfbhae","i","giacigehdcchf","hdcajahagbaafhcjgggj","ic","jdjicejfeeeabibj","aebfgbg","gcffiahh","gghhcchfcidijjc","cccchcjdfidii","idfgjiacegdjedejfha","gfhiifcaecfjajhhhj","iehcachfffcdaaiai","a","fi","befibffchdf","fhehjfdiaajdcje","gdfhi","hg","bhchdaffgihdigfii","hgjiib","hfjggdbideiaaaah","chjjaaih","ggbgh","aeejajccjdfdjeagjbcc","fehigdgcihicdgdiif","jcceigfi","ccigfb","hgecbbiag","bcedbdfibaj","cebdjajhb","faicieaaahfijicfhaf","aagaeaagbedi","hjighdgiehajfgddijc","bdghhbghcg","dhicidgacbhhfffgh","bahgg","gabeijjhfididjeaace","dhcgbaja","diagiibfbfjbccfaiibg","ah","bgcgchfcdaiebhbgic","jjfefbha","h","jhai","hjhcdbcfjfa","fifaeiaccb","jdeidjajbgfggjhegjh","dehacfgejidbdecfigcj","bhdehccbecefgjfbc","icedfcceeciba","ch","eiciefgddbgghihcejff","bbfccdeiaffffi","dd","ei","fhehghdcijddfjadd","jhcbjaiijgad","agigggahcibiihhh","gjdcifjd","gchcbgabiebcbbae","gighbgejjiijedcg","dadcgibgieehijfd","jffgcdbjadcaidcggeg","dghcdhegiejbbgcfa","gbeggfjidgfiicfdhhc","bafadggc","ajhiagea","jgcdihagcaf","cebcfagd","deajhfebdbaadeb","deeahiegfejga","cdfa","hdhhbecdciaijif","igcajhdcje","ebaijgfaaigigggfaac","gfbjciejhfbabgadhig","aebfeajbbgdhechbd","jfegjbhhdeiiggegdg","aajbfhhfij","begdbhcbiehdcb","haiefjji","gjjfefadjiijdcafih","aidicifbadbgcc","iidbgaajhebgja","ddb","ihhb","eidabcegbjecbfehe","adhgjhjaaidbf","hchijbjb","bjdibjdachdbjg","hefdaaiajeaichgcjeda","eccgeadhee","becdiihedf","jhhhcbagbh","aiibjgje","jhh","aejjbcjgihbajja","ihjgcbh","baajdcifabadadc","dba","jhcjjachcjjddcgjg","dhcceeh","jaajabiidicajb","hbiaahdhj","jgacbidgigfdc","affeh","jbiecgcieajfjifiedbh","gga","ef","ddhhjjadc","agfejge","chdijeajh","jgahcedjdgbga","bfech","hdbjgbgehjeeghigai","ijgbicdfda","ejdhigd","fggiijhjaig","dcaegjcjibfah","ggcjhadcefgh","ahccdghjihdfef","fa","bgajedcdchdjfaabbh","dfhddidijjcibcjgc","dgegehfcgddjdi","hcedfhacaba","ihgefhchdegigg","ccaehjef","bfaigicbe","diffciaghcdiahb","fbbgafddddffe","aadejejcj","jdjaabfh","eggjdchcdfeeiabfcdfe","dhjhfhgee","hidgjdcegd","dghgda","fgdfbahfefbbdajbcfi","djedidhjfibigffcfjff","edgeiifbfagfdfj","hddgijijcabfdef","gbjbdbccicfbiebajffi","hgajahedigiagegcbaef","jfhahgfdicdcf","cfgjaifdaaddbcieeb","ejgiid","fgeddj","jiacbecachaid","ehjbfbjcbhc","jdfagibbebbeafcafe","edbagehejdaibh","deigdheibjcbghce","bdcchdjgbdadhbei","ccehaebd","idhhecfgcjejdgccc","ccfegdejhiaehchhijjb","hahihbcgggbdci","jjb","efdfbbcfb","g","bbadgdgchgcagafgf","fhc","hhefa","cfggaa","hafhebcejf","edch","hfbb","hbfebbgghfijihdffddd","fbf","eaghegbfiabejgcdaaf","jgjgcgdjgc","baafhgi","dfcdfhd","hjdeijia","chbfahef","acjjggfghfafa","hhcb","jhhf","ihaiegeifacdgiifgih","hiifgfjhidbciag","ecghfbcfg","hgaigbidf","cbediiciifiedheg","cbdbihbaijgbehgjae","hje","fbhbfic","cjjj","gdigii","gidj","ffibigjgbb","jbddibf","gbcicf","gagjagfgjcehddidffh","iggbd","degdbfaia","j","hdcajihhfjee","iahbafjjcc","bhiggh","jcgiagebjgijifahbe","ccgh","iafggaj","djfbgdbcjbajdbajhi","acaiachcgcedbghidi","adfhidf","hiea","fdge","ecc","gg","dchaghfeaibffgdeh","d","gbfgadjg","fcjggfbfdaei","ejfheehcigjibgjadec","jghdgfbhfdfdiagf","aejeecgchadh","jecidbbgcfad","dgegaaeia","hecdcbhdfjfbe","gehddjcd","dbefbbjjgbhhgb","heeh","afcee","egiajbeg","bghbcaab","ceejhd","abgggjd","fjhadgea","hfafgcaede","bfffeihefebdj","gihhcfbhhdiffhf","feaigcbaedfd","hgidcdfifaaf","dcideigbicd","bcda","deebchahedebbbdfc","ccjci","dhefjchhiaddhae","gbicceadjbjggbigfii","eigbhcceecefi","ccciaegedda","ihhgdfcjidchf","bdaifehjhafgeddbfjcf","ecbijejjegheihjiegd","hggdeadafhja","iigbhdea","jdjjidhfcfdfj","aggca","ejdfagjhdieaijhg","eijegfagbiihgfgbij","fhccbdghaeghfecdfajj","geca","eh","cfjeiaab","bgcff","jdaaihjhefejbid","dbifbchgbcedhiajccdi","aefch","iabgdajidjebjgdgf","hcacdacegje","fjgddcaibibffhjajhhi","deijefjeadihac","cgcgcdcfcficjechccje","ehbgcaiageehjdggcd","bfabeiifjhjic","cbaddhbjj","hiifbjaggibh","dgjchagdicdhiebihge","ihfifh","ih","jgfcfbafjeigficebg","ieefiggch","jdebd","fadcjie","fhhggiddeicggdifcg","ffbdgigcihffgbbdhbi","daabcjea","jadijejgfcg","gbhjfbi","iehbcgihfhbjib","cjfjaddia","acihjaihacdc","dicabhdihdhajaab","dfdbjhahcheabghf","hheggffgahcg","gbabcgibhhci","bahdhhcdf","hfeifjfif","dhgiajfgcgbbbg","ebjfcaccbjdjfajgeifd","ebheigajdbjbabhebice","gfdjic","ahdggebjg","acibh","giajbgabgaccbhhhfh","eiii","ahhccijg","hfjcicgfgbhiidi","bcgfgfeidfdafeadjcd","egcfgd","aeedjejeiigchhihifea","jbcegdebeceg","jedcfc","gddhebgij","ibdfe","dhefhfagec","edihfgh","djieagd","bjebjejjecdbhahej","hicei","fida","cb","dibiheecibc","ccjhcbgcdjfaj","ceggfacij","igidhfjhdgijfhgf","hjbhd","efdij","icdfcgbgchegfajagcjc","feafbag","eghafbiagjfhie","hiegfadfcfbf","gfgdjhijbhiecfgffjdf","hdedecdgeb","bbghbbacjadjcbdfjj","cfajihbbfejhc","gefehgg","eiec","cagjjagefafi","cafefffhdchhichdi","jaafb","aegbgfccdbhghfadb","ifhdgeaagf","hehhbcficfb","hicggdici","efjf","heaadjhaafjjaegbbi","hhhghf","ahjdccceaejgdgiicifi","jhghb","edcefibhhf","hihhbgeeejidhaaegdga","ihahibdgfchaece","ffajcgbejaechhidfgfc","dbjcacdaijiaeaigc","hifdcgjijccjjiah","edi","ahcdjbjjj","cdedbcbdgaehibcgcfjh","jecddicfa","cjbgibg","bijgfaafccgiabadgihc","ehjc","hdcgbeeajhdicgac","fghedgfffhga","geaejcdjefgeihcjhjed","cffdbagifafgjd","dbgabjdcicchcfj","eahbbbj","jfcjjd","ghijjfhjg","bjhejejhafgbbi","hcbbb","ijhacdjhdbfbdbchh","ijh","ibbgjeibicgcjhjab","fbd","ihcefadh","abdhfdhebegjdg","bfedchfiijffcigi","jabcdifhjb","aagiiafhebffacajgbej","hch","cefgcjcidghegcc","jceeh","afdfifafajdbfdjihah","ejdichbe","cjhahcgihh","fjccddaicdii","di","gia","acdd","gijfdeadjfb","jgfieed","hjcecdcidhjdchg","adaidj","cbcajdgcb","ghhjggcgaiahg","icafacfdieidddd","ifhib","iaggdbd","ibjcf","cahdieigjfahiddd","bbeheebjdhhhbice","hgbfbfhbidfcabehhcdf","aecjiiai","aaaehiicj","adajedfadaajhgje","djajffdageijdba","jbajhhdcbbfhcgcfc","igaddhgebjghd","hddicdhgjaafdeafbg","cgffigabddicbceegdee","aeeacjjgffbdda","agcifeecaij","biaicbfhai","jbagfc","bjbffhcabdehd","ecgcdadchfbiabbe","dggdafhigigidcciagig","bi","fbigaebf","hifahca","dhdfdfhcchejeejejj","ebbf","hj","ibhedbgd","gchcgd","dghgcaieeca","fgdgfgbcja","id","bfaiighhbdg","hf","dabgggieabjhh","ifb","hcagdabbehhfg","iedihjbgccijb","cadcgab","dge","fifehihfgcajffdhgcgg","eggcbfcghbdhfchajg","hicbjdjg","geefjbhifcdjcada","bghbabfjiacbhage","ie","ehjecafeijhhhhii","ddcbdadbaagbf","cifgibahaijhaiib","abhg","jcceigihigibchcg","dabegbfgeahhbgc","hjabbedacgac","eechdagieff","ij","ieidijhccjehjhbibh","hjbdcjgcj","hiebgghjfifdbdafcg","eebeh","jfghjjicghhgaahcbihb","bggjfhbch","jdcd","bicddacgbbjag","hhbhj","fdj","ffcgeeeedcjiijeagcd","cfchhf","jged","dbihdicfciegddhcfi","iggadgbdfdd","chdf","ahdjidai","ceadddhgdbdgedbfh","jghcbeghca","addecc","efh","gdbagijaib","dgiijabahag","ehigech","ddgahheedecfj","hddbghdjfj","cfbhhididdeigga","dgebh","jiceheh","jdejghhfcacacdci","gfbdegcefcgcgbd","caag","fhcchajhdfccj","eagafhchfde","ahadbejefeeihcheif","jcjgbfdaffeejhijc","cfdggaggcgdiac","jibdjjig","jeigjgaigaggifdbbbi","hcd","ecibhebahgdcadcahcff","bigeebgdidjc","hhbighhjdcffaacahcj","gcafjjefhdeed","jgjfhigffga","ahba","gijbfbjajiehd","cheegcdbeceddcg","gfg","hdj","ahiicagacbfggfa","badjbbdefjagcbdcjb","ba","hjddj","fbggebgfcdafdaggidf","biiadcceifjhcbg","gfejgddfdibgcajeadi","ehaggfcdeddddjdecb","igbbfjdc","acgbbcgdhcgcjfjgi","jej","efjahg","afajcgbjijjde","dahabh","aihjeecdh","fjbcahcgaigieeibfah","ifeiceeajiifhac","edic","dijbddjihegebdifhb","fdgbbbaebigc","ibabbicdgjejhcdgd","gfhheebibdifbdffbi","eadaebggifaiheacejd","fjjceibiighdid","jhdhjedcce","bibaiaahfdhg","bfdcdbac","acebacdicfdccdj","edbcgaffceabii","jigibfgegfbhdegj","dhibeaiiedbifdaf","gecbfijhecijigacecb","aeedbdihifbdg","figcdeghgfc","ddaechabebbhghfi","adaajcccdcfchbfj","ahedfdhjiaadggadfg","ciegdbbgbefhcidii","fdbdf","ieacbdfhhi","ce","fcjcjiei","geghhaagedhhagj","eafci","gde","ebf","efhjfabeajgigfhjj","icahcjebbfjbahecc","cehadibejgf","bibbcjjbb","iecdhagaefbhecd","ccff","gccjdgdbjhj","achijbid","bhhaiefgechfbbc","ijghageeeg","gcbdfjbif","gffdgchgaggiifdj","fajgebjjjfgdhg","cdc","badaidddadej","ijbdebfdgjccfadcjd","hffjcgeheibcgdcbfc","cbjcjbgca","ajaebffjiigdeij","dhdaccijccibghjhcb","bddf","hcdiechbafidbaaj","aehaijfdbhcfed","dachcaee","jaagaged","efhfibag","caei","ejgfihfdjjcddid","gedej","hacbejb","acecag","bai","cggecjfddhcaehead","beafhd","hcaibbjjf","chaibeijfagicf","hffhacjjffijgebh","cgaccfbfeajgcfgbcba","fibafci","ciih","baihjjbebh","abh","dfaabdgiadcbbjeg","jheificidgjbf","jjfccggbjbjcbh","gcf","bceagfefgdebd","jbib","daefaf","hheachd","fffhfhghfe","dgfadgb","ji","ibihcbjffffjfaada","jgceeddihdcceabdeg","hfbei","hjbgahhahb" };
