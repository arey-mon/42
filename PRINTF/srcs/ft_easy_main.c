#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

/* REMAINING
- pass norminette
  deal count :
- if type == 'x' || 'X' P==aff arg_count should be + 1
- O3.0x || 03.0i >> width is not printed // case is zero==1 P==0, arg=='0'
*/

#define MAX 10020
#define MIN -2147483648

int main (void)
{
  int d = -1;
  int *p = &d;
   //char c = c;
   // char *pp = &c;
   //char a;
  // int x = 0x54;
  // int X = 0x98;
  //char *s = "1";
  //char *s = "quinze_characts";

/*DESTRUCTOR FALSE TESTS
// THIS IS RELATIVE TO x && X and arg==0 and P==0 || P == 1

printf("pr_ret = [%d]\n",

Diff for printf("Q%.5sdxZz%08.0dV8HpP", "", 0);
Diff for printf("d4s3%0i%014.0XjZT %2.*x%*dOTnzrSU%06.5ubyo", -1512177470, 0, -5, 0, 9, 2147483647, -2147483647);
Diff for printf("R4MoIEceyx57kpEAz9DL%*.0u%-16.1u", -10, -2147483647, 0);
Diff for printf("lsOwu%%%13x%014.0d62PltF%20d%-.2u", 2147483647, 0, 1756235986, -1161278665);


Diff for printf("7dGu%15.4sK51iePnsczn0RW%012.0dm", NULL, 0);
  printf: |7dGu           (nulK51iePnsczn0RW            m-- 46 --|
ftprintf: |7dGu           (nulK51iePnsczn0RWm-- 34 --|

Diff for printf("%*cSGXe4uo%-XJec%-10d7rk2%-.1u", 10, 'k', -2147483647, -2147483647, 0);
  printf: |         kSGXe4uo80000001Jec-21474836477rk20-- 44 --|
ftprintf: |         kSGXe4uo80000001Jec-21474836477rk20-- 45 --|

Diff for printf("of%-x%04.*dX1QEg6H%019.0u%020.*x%-*.1u2XU", 0, -10, 2147483647, 0, -3, 0, -10, 0);
  printf: |of02147483647X1QEg6H                   000000000000000000000         2XU-- 72 --|
ftprintf: |of02147483647X1QEg6H000000000000000000000         2XU-- 54 --|

Diff for printf("U556Y%0i%.3X%014.*d", -2147483647, 617766885, 0, 0);
  printf: |U556Y-214748364724D25FE5              -- 38 --|
ftprintf: |U556Y-214748364724D25FE5-- 24 --|

Diff for printf("TNKvGFTm0RVh%0.2X%.4s%-14xM9f%-.*u%18.4X", -589023509, NULL, 778162569, 10, -2147483647, 758206523);
  printf: |TNKvGFTm0RVhDCE436EB(nul2e61d189      M9f2147483649          2D31503B-- 69 --|
ftprintf: |TNKvGFTm0RVhDCE436EB(nul2e61d189      M9f2147483649          2D31503B-- 70 --|

Diff for printf("%-.*dCka%0.*i%0.4u792X6IhRBXH%-18.*u", 6, 2147483647, 7, 996716146, 2147483647, 1, 0);
  printf: |2147483647Cka9967161462147483647792X6IhRBXH0                 -- 61 --|
ftprintf: |2147483647Cka9967161462147483647792X6IhRBXH0                 -- 62 --|

Diff for printf("%-i33zaAs0%017.0x%0.0ubM1%-9.0u%-cIbgEYIS", 0, 0, 2147483647, 473364519, '0');
  printf: |033zaAs0                 2147483647bM14733645190IbgEYIS-- 55 --|
ftprintf: |033zaAs02147483647bM14733645190IbgEYIS-- 38 --|

Diff for printf("%0dfy2%-16.2X%c%-11.1uEuG%-.1u%-7.3u", -2147483647, -2147483647, '\0', -46140893, 0, 2147483647);
  printf: |-2147483647fy280000001        4248826403 EuG02147483647-- 56 --|
ftprintf: |-2147483647fy280000001        4248826403 EuG02147483647-- 57 --|

Diff for printf("%0x%.1u%dCG9o%-16.*uu8FhwX", -2147483647, 999049697, -2147483647, 10, 1992445896);
  printf: |80000001999049697-2147483647CG9o1992445896      u8FhwX-- 54 --|
ftprintf: |80000001999049697-2147483647CG9o1992445896      u8FhwX-- 55 --|

Diff for printf("%08.0u%.5X%c%d%%%-.1uoD%0.*d", 0, 2147483647, '\0', 2147483647, 2147483647, 5, 1500640843);
  printf: |        7FFFFFFF2147483647%2147483647oD1500640843-- 50 --|
ftprintf: |7FFFFFFF2147483647%2147483647oD1500640843-- 42 --|

Diff for printf("kF1JQ%0u%*.1s%04.0x%013d4%.3s", -35105856, 1, "OuT2Va194YWkBw1OEGCw3kOQDjcPKuLJVlHsr08h1jdvukKeLecxEFq U1btuXmhz869VAQK1R5F5OkIcYy5tRsiGvOxJI6Ttle9", 0, 2147483647, "nYL1nbAHIjmbLO4doWXMu3I6wFqMbGIqA2EMEYhm58Q MkAXtrODMjsJxG kcUZQHo4Ll8spFQVU2");
  printf: |kF1JQ4259861440O    00021474836474nYL-- 37 --|
ftprintf: |kF1JQ4259861440O00021474836474nYL-- 33 --|

Diff for printf("aoZ%-16cNtIRL%s gVij%-xc%017.0d", 's', NULL, 0, 0);
  printf: |aoZs               NtIRL(null) gVij0c                 -- 54 --|
ftprintf: |aoZs               NtIRL(null) gVij0c-- 37 --|

Diff for printf("%07.0i%%%-.*d%.3u", 0, 5, 2147483647, 0);

Diff for printf("OcBh%016dkjRb0rtCBGJYdb%015.0xz4HS0hOn", 0, 0);

Diff for printf("qj%-17dU JOEy95%-.1u", 2147483647, 0);

Diff for printf("%*.4x2vJciW%05.0Xqn1ojusk%5.*i%*cgLFzTT9y", -6, -2147483647, 0, -1, 0, -7, 'w');

Diff for printf("gq%05.0uo5pHIiTZ", 0);

Diff for printf("%09.0u%10sJaQ7mbFt%*c%16.0s%016uq", 0, NULL, -10, '\0', "apHq69YjUAoWiPDn24fA", -2147483647);

Diff for printf("GtQ%sjvWCM%-.1uhiDHp7OEtx9 5G%-.1x", NULL, 0, -2129279322);

Diff for printf("hnL%015.5u8 aF%-15iCrD%dzjAH4d2%0*.1u", -2147483647, 0, 2147483647, -2, 0);

Diff for printf("%13sly5QJ%0.4XsfVDC%07.0X%-20Xzuvc9HK", "RDrgHymqEkIrMoFJzy8N3tPolOL3ap9O V4JDC9A2AQDpNgABDWXuIt7yDsvfPwzsL3rVXsuPWvxpCS4P", 2147483647, 0, 2147483647);

Diff for printf("L9T2sJC%*sAJ%05.0dZ6OLhVjcnY7iD", 6, "", 0);

Diff for printf("%cw8a%11sZHmKfMJJqWq%%6BE%010.0i", '\0', "Ozc2ASfBH49mO8l2UH5DwFbab", 0);

Diff for printf("iqW%*iF Uq%-.1uuElx", 9, 0, 0);

Diff for printf("Ban%0.4X Xyn%03.0dsl", 2147483647, 0);

Diff for printf("giAPtIf0zT%-1xkw%-.1u", 752598152, 0);

Diff for printf("5Na6j%c%011.0u", '\0', 0);

Diff for printf("hkk%.3s%06.0xX6l", "IzZGhEgrbjc1Mvsl", 0);

Diff for printf("0RDEn6Q UQG9G75%016i%%SO%09.0dht", 2147483647, 0);

Diff for printf("%01u%06iEm%-.1u", -2147483647, 1795822385, 0);

Diff for printf("%-11.1u", 0);

Diff for printf("SLQ8%08.0x%-17.*i5U9%012xoZCQSQL%06.0XhgRl%11X", 0, 6, 1136268268, 821233827, -2147483647, -1654016125);

Diff for printf("oVtAWhafCKAS9%0.4xc3fJn%0*u%06.0xP%-d", -2147483647, -6, 0, 0, 2147483647);

Diff for printf("%%%-14.1uWJWO%%EM%1.3i2R", 0, 2147483647);


Diff for printf("%i%.3sK7ht%-*.*X%8s%-.1u%%", -1996454766, "", 3, 5, 0, NULL, 0);


Diff for printf("%czgL%05xU%.4XSt%011.0u", 'M', -2147483647, 2147483647, 0);


Diff for printf("%-c%-2X%-.*dXhemLzLnmh%-19.1uGxTAWdMLKYiCO", '\0', 446814258, -5, 2147483647, 0);

Diff for printf("%09.0X", 0);

Diff for printf("wdxoc%-15.3iBKb%16iZGL Q%014.0x", 0, -2147483647, 0);


Diff for printf("qQ%03.0ilD9I%%O1uHNmSJmV8JDC", 0);


Diff for printf("%-2i%%CYfN%018.0XjX788Tv7r%X", 0, 0, 2043979736);

Diff for printf("fOvL%020.0u%-6.3X%01ikFISLA3KY", 0, 0, -2147483647);

Diff for printf("%%2fu%19s%03.0XGDQOeV%.*x", "Y9P15sTwhVCveo3S0E1vCHrpvSeb BxbpV9RduV7 wc4iL6VaCXDQssMtpplQ4pbZ9rff", 0, 0, 0);


Diff for printf("%-*.5dcGZJ%%%%%6.*x%014.*umBy", 7, 0, 3, 2147483647, 0, 0);


Diff for printf("m1Ka%-c%*df%03.0uFH3X", '\0', 9, -2147483647, 0);

Diff for printf("%17d%0x5pHE%0*.*d", 686549370, -2147483647, 10, 0, 0);

Diff for printf("%019.*u%016.0x%-cerGV%-.1d", 4, -2147483647, 0, 'L', -2147483647);




// DESTRUCTOR CORRECTIONS
printf("pr_ret = [%d]\n",printf("%-19.*u", 10, -823078038));
ft_printf("%-19.*u", 10, -823078038);

printf("pr_ret = [%d]\n",printf("%7.5u%-20u%012.0u%-17.0s", 2147483647, 0, 0, "GvF0AG"));
ft_printf("%7.5u%-20u%012.0u%-17.0s", 2147483647, 0, 0, "GvF0AG");

printf("pr_ret = [%d]\n",printf("%0d%02.*X%.*ucvuLpttQhk", 0, 0, 0, 4, -2147483647));
ft_printf("%0d%02.*X%.*ucvuLpttQhk", 0, 0, 0, 4, -2147483647);

printf("pr_ret = [%d]\n",printf("%14.3usg%%m3ggI%-18.*u%%%.5sIJ8", -2147483647, 10, 2147483647, ""));
ft_printf("%14.3usg%%m3ggI%-18.*u%%%.5sIJ8", -2147483647, 10, 2147483647, "");

printf("pr_ret = [%d]\n",printf("eR%05.0uMA%-*.3d", 0, 8, 0));
ft_printf("eR%05.0uMA%-*.3d", 0, 8, 0);

printf("pr_ret = [%d]\n",printf("xMWZgpk%-sIg4xNhh%012.0u%7.4i", "uqC7adjMWAK7WDNsQgP", 0, 2147483647));
ft_printf("xMWZgpk%-sIg4xNhh%012.0u%7.4i", "uqC7adjMWAK7WDNsQgP", 0, 2147483647);

printf("pr_ret = [%d]\n",printf("i58%011.0X", 0));
ft_printf("i58%011.0X", 0);

printf("pr_ret = [%d]\n",printf("%05.0X60%*x%18Xb", 0, 7, 2147483647, -587819009));
ft_printf("%05.0X60%*x%18Xb", 0, 7, 2147483647, -587819009);

printf("pr_ret = [%d]\n",printf("Y%-11.5d%.0ico%-9cCYy%x%016.0i%X%-u", -2147483647, 0, 'G', -2147483647, 0, 0, 2147483647));
ft_printf("Y%-11.5d%.0ico%-9cCYy%x%016.0i%X%-u", -2147483647, 0, 'G', -2147483647, 0, 0, 2147483647);

printf("pr_ret = [%d]\n",printf("%01d %-.1uUB", 2147483647, 0));
ft_printf("%01d %-.1uUB", 2147483647, 0);

printf("pr_ret = [%d]\n",printf("%.2i%-.*u32%6cIuXIITLcIzhJu%.*u", -2147483647, 1, 0, 'M', -1, 0));
ft_printf("%.2i%-.*u32%6cIuXIITLcIzhJu%.*u", -2147483647, 1, 0, 'M', -1, 0);


printf("pr_ret = [%d]\n",printf("A18l6I5fy%ciSm8%06.0x%-.5i", '\0', 0, -2147483647));
ft_printf("A18l6I5fy%ciSm8%06.0x%-.5i", '\0', 0, -2147483647);

printf("pr_ret = [%d]\n",printf("tmhFk%017.0xCPbCAtI6%0d%-10u", 0, 2147483647, 1411305900));
ft_printf("tmhFk%017.0xCPbCAtI6%0d%-10u", 0, 2147483647, 1411305900);

printf("pr_ret = [%d]\n",printf("%0u%7i%011.0u%03xitqu2M8DIm2", 2147483647, 0, 0, -2147483647));
ft_printf("%0u%7i%011.0u%03xitqu2M8DIm2", 2147483647, 0, 0, -2147483647);

printf("pr_ret = [%d]\n",printf("Ncj%.0d%-.0X%013.0X", 1923379590, 0, 0));
ft_printf("Ncj%.0d%-.0X%013.0X", 1923379590, 0, 0);

printf("pr_ret = [%d]\n",printf("%01.0x SYat1%02i%.*i", 0, 1743322906, 8, -2147483647));
ft_printf("%01.0x SYat1%02i%.*i", 0, 1743322906, 8, -2147483647);

printf("pr_ret = [%d]\n",printf("%01.0x SYat1%02i%.*i", 0, 1743322906, 8, -2147483647));
ft_printf("%01.0x SYat1%02i%.*i", 0, 1743322906, 8, -2147483647);

printf("pr_ret = [%d]\n", printf("GwLlG%01.*X%-12.0xadHi3%d\n", 0, 0, -730787037, 2147483647));
ft_printf("GwLlG%01.*X%-12.0xadHi3%d\n", 0, 0, -730787037, 2147483647);

printf("pr_ret = [%d]\n",printf("%-.1x%-i8n2mFzQ5D%-8.1u", 0, -2147483647, 0));
ft_printf("%-.1x%-i8n2mFzQ5D%-8.1u", 0, -2147483647, 0);

printf("pr_ret = [%d]\n",printf("%01.0i%-uY", 0, -975876039));
ft_printf("%01.0i%-uY", 0, -975876039);

printf("pr_ret = [%d]\n",printf("GwLlG%01.*X%-12.0xadHi3%d", 0, 0, -730787037, 2147483647));
ft_printf("GwLlG%01.*X%-12.0xadHi3%d", 0, 0, -730787037, 2147483647);

printf("pr_ret = [%d]\n",printf("q%*X%c%4cjgVQ2%0*.0X", -10, -2147483647, 'M', 'c', 1, 0));
ft_printf("q%*X%c%4cjgVQ2%0*.0X", -10, -2147483647, 'M', 'c', 1, 0);

printf("pr_ret = [%d]\n",printf("HUPShGd3sAdK%8s%6u%03.0i", NULL, -1077550324, 0));
ft_printf("HUPShGd3sAdK%8s%6u%03.0i", NULL, -1077550324, 0);

printf("pr_ret = [%d]\n",printf("xA%017.0u%-.2x", 0, -2147483647));
ft_printf("xA%017.0u%-.2x", 0, -2147483647);

printf("pr_ret = [%d]\n",printf("hNjHX%0*.0u%.4s", 10, 0, NULL));
ft_printf("hNjHX%0*.0u%.4s", 10, 0, NULL);

printf("pr_ret = [%d]\n",printf("%-16xHNfaifOabJd%03.0X", 2147483647, 0));
ft_printf("%-16xHNfaifOabJd%03.0X", 2147483647, 0);

printf("pr_ret = [%d]\n",printf("5gj%010.0u", 0));
ft_printf("5gj%010.0u", 0);

printf("pr_ret = [%d]\n",printf("a5jklUB77qgfT%012.0iZtSe%4.*XE0", 0, 7, 0));
ft_printf("a5jklUB77qgfT%012.0iZtSe%4.*XE0", 0, 7, 0);

printf("pr_ret = [%d]\n", printf("%018.0i%-iaF8fjJyrt%10.3i\n", 0, 0, 2147483647));
ft_printf("%018.0i%-iaF8fjJyrt%10.3i\n", 0, 0, 2147483647);

printf("pr_ret = [%d]\n", printf("%018.0d%-iaF8fjJyrt%10.3i\n", 0, 0, 2147483647));
ft_printf("%018.0d%-iaF8fjJyrt%10.3i\n", 0, 0, 2147483647);

printf("pr_ret = [%d]\n",printf("1A%0ubfzt%csk%-10c%-.1u", -2147483647, 'a', 'S', 0));
ft_printf("1A%0ubfzt%csk%-10c%-.1u", -2147483647, 'a', 'S', 0);

printf("pr_ret = [%d]\n",printf("Sv%-4c89nrb%-10.1uh6X6zjPLHPhrJ", '\0', 0));
ft_printf("Sv%-4c89nrb%-10.1uh6X6zjPLHPhrJ", '\0', 0);

printf("pr_ret = [%d]\n",printf("%-20.1u", 0));
ft_printf("%-20.1u", 0);

printf("pr_ret = [%d]\n",printf("%-9.1u", 0));
ft_printf("%-9.1u", 0);

printf("pr_ret = [%d]\n",printf("%%%03xEneLf%-*.1u6rIvw", -2147483647, -1, 0));
ft_printf("%%%03xEneLf%-*.1u6rIvw", -2147483647, -1, 0);

printf("pr_ret = [%d]\n",printf("%iLqSR%07.3i%-.*uPUJ%%%i", -2147483647, 0, 1, 0, 2147483647));
ft_printf("%iLqSR%07.3i%-.*uPUJ%%%i", -2147483647, 0, 1, 0, 2147483647);

printf("pr_ret = [%d]\n",printf("%i%-2.1uuJNytj1TYz%-X%-*i", 2147483647, 0, 40195401, -8, -549353854));
ft_printf("%i%-2.1uuJNytj1TYz%-X%-*i", 2147483647, 0, 40195401, -8, -549353854);

printf("pr_ret = [%d]\n",printf("VPb3H%-dmPLLYrgA%-.1u", -247372838, 0));
ft_printf("VPb3H%-dmPLLYrgA%-.1u", -247372838, 0);

printf("pr_ret = [%d]\n",printf("UK%%pBjMKi%-7.1uJR2", 0));
ft_printf("UK%%pBjMKi%-7.1uJR2", 0);

printf("pr_ret = [%d]\n",printf("DVKKAqRj%-19.1uB%20.5u%-sz", 0, 0, "YTt5MUAVCVuKXWcwGa6UiB9DkuFGcMWuDyvzH5efkpjwc h0KwnX"));
ft_printf("DVKKAqRj%-19.1uB%20.5u%-sz", 0, 0, "YTt5MUAVCVuKXWcwGa6UiB9DkuFGcMWuDyvzH5efkpjwc h0KwnX");

printf("pr_ret = [%d]\n",printf("%-.*unqYH%-dlVjj", 10, 2147483647, 2147483647));
ft_printf("%-.*unqYH%-dlVjj", 10, 2147483647, 2147483647);

printf("pr_ret = [%d]\n",printf("dzrQ%0d%-.0dUKu%012d%-8.3s%-.1u", -277238533, 2147483647, 2147483647, NULL, 0));
ft_printf("dzrQ%0d%-.0dUKu%012d%-8.3s%-.1u", -277238533, 2147483647, 2147483647, NULL, 0);

printf("pr_ret = [%d]\n",printf("%7.4sI7Bu06%0.2d%-14.1uMBMnA%-12X%.*i", "rlEEGgOARRrDGJ2eBIp7JY8tXtYgBnnyMpTFFLBRF4uhXazpSKBPAJBE5xvEgWETWmU aB0yj", -1736645394, 0, 115931605, 4, -1897593652));
ft_printf("%7.4sI7Bu06%0.2d%-14.1uMBMnA%-12X%.*i", "rlEEGgOARRrDGJ2eBIp7JY8tXtYgBnnyMpTFFLBRF4uhXazpSKBPAJBE5xvEgWETWmU aB0yj", -1736645394, 0, 115931605, 4, -1897593652);

printf("pr_ret = [%d]\n",printf("A9 4%-.*X%-*.1u", 4, 2147483647, -5, 0));
ft_printf("A9 4%-.*X%-*.1u", 4, 2147483647, -5, 0);
printf("pr_ret = [%d]\n",printf("%-.1u%-19djyfGi%-*c", 0, 2147483647, 1, '\0'));
ft_printf("%-.1u%-19djyfGi%-*c", 0, 2147483647, 1, '\0');
printf("pr_ret = [%d]\n",printf("ZEiH2nsG%-11cUxh7AYot7%*c7juD%*.1u%15c", '\0', -7, '\0', -3, 0, 'V'));
ft_printf("ZEiH2nsG%-11cUxh7AYot7%*c7juD%*.1u%15c", '\0', -7, '\0', -3, 0, 'V');

printf("pr_ret = [%d]\n",printf("%%%-.1uqg 4S", 0));
ft_printf("%%%-.1uqg 4S", 0);
printf("pr_ret = [%d]\n",printf("mtc%-.1ubY8Jc%-17.1i%0*.0d%-3iF%0X", 0, 2147483647, -3, -402168208, -1948154387, 0));
ft_printf("mtc%-.1ubY8Jc%-17.1i%0*.0d%-3iF%0X", 0, 2147483647, -3, -402168208, -1948154387, 0);

// printf("pr_ret = [%d]\n",printf("%.*s%0.2x%1.2d7%-*.*u", 1, "", 1771257096, -1582485857, -1, 1, 0));
// ft_printf("%.*s%0.2x%1.2d7%-*.*u", 1, "", 1771257096, -1582485857, -1, 1, 0);

// printf("pr_ret = [%d]\n",printf("JlmQF2yJd%-*.1uVy8Yb%%%%x5Vccr", -9, 0));
// ft_printf("JlmQF2yJd%-*.1uVy8Yb%%%%x5Vccr", -9, 0);

printf("pr_ret = [%d]\n",printf("%%%03.0X%*cLu", 0, -4, '\0'));
ft_printf("%%%03.0X%*cLu", 0, -4, '\0');

printf("pr_ret = [%d]\n",printf("%%%03.0d%*cLu", 0, -4, '\0'));
ft_printf("%%%03.0d%*cLu", 0, -4, '\0');

printf("pr_ret = [%d]\n",printf("LSN%02.0xPcXYKz86%%", 0));
ft_printf("LSN%02.0xPcXYKz86%%", 0);

printf("pr_ret = [%d]\n",printf("%%%014.0d%.5dQyBk4TXpvVg9yQFQi3", 0, 0));
ft_printf("%%%014.0d%.5dQyBk4TXpvVg9yQFQi3", 0, 0);

printf("pr_ret = [%d]\n",printf("%cUMKX5oSFVcKdkmLm6%%e0oJ5%-.1u", '\0', 0));
ft_printf("%cUMKX5oSFVcKdkmLm6%%e0oJ5%-.1u", '\0', 0);

printf("pr_ret = [%d]\n",printf("3WIQF%015.0ulEP0p", 0));
ft_printf("3WIQF%015.0ulEP0p", 0);

printf("pr_ret = [%d]\n", printf("%014.0dtwQvXuxjh%c8BP4bCD%017.*X%%", 0, '\0', -6, 1539267469));
ft_printf("%014.0dtwQvXuxjh%c8BP4bCD%017.*X%%", 0, '\0', -6, 1539267469);

printf("pr_ret = [%d]\n", printf("MJ4LVrCr%%%03.0dahRQO6B1uO mNVlZYF", 0));
ft_printf("MJ4LVrCr%%%03.0dahRQO6B1uO mNVlZYF", 0);

printf("pr_ret = [%d]\n", printf("vZbqAtRF3%019.0u%%8IjJ6q%-*.*x", 0, 7, -3, 2147483647));
ft_printf("vZbqAtRF3%019.0u%%8IjJ6q%-*.*x", 0, 7, -3, 2147483647);

printf("pr_ret = [%d]\n", printf("%-*X%03.0x%%%020u%01x4", -5, 0, 0, 2147483647, -2147483647));
ft_printf("%-*X%03.0x%%%020u%01x4", -5, 0, 0, 2147483647, -2147483647);

printf("pr_ret = [%d]\n",printf("%08.0iVQh%*s%-18cha7s8%19c%0i%%%011X%0*.0X", 0, -4, NULL, 'Z', '\0', -2147483647, -1408586574, 5, 2147483647));
ft_printf("%08.0iVQh%*s%-18cha7s8%19c%0i%%%011X%0*.0X", 0, -4, NULL, 'Z', '\0', -2147483647, -1408586574, 5, 2147483647);

printf("pr_ret = [%d]\n",printf("%.2d%-4iN2Z70s5WDsJ%017.0d%0ugejq459hDR", -2147483647, 0, 0, 2147483647));
ft_printf("%.2d%-4iN2Z70s5WDsJ%017.0d%0ugejq459hDR", -2147483647, 0, 0, 2147483647);


printf("pr_ret = [%d]\n",printf("%-3.*dEFR%-c%019.*d3ipW0mngm%12.3x", 3, -2147483647, '\0', 0, 0, -175827749));
ft_printf("%-3.*dEFR%-c%019.*d3ipW0mngm%12.3x", 3, -2147483647, '\0', 0, 0, -175827749);

printf("pr_ret = [%d]\n",printf("g3d9z%6s%019.0x%-u6pqCbGv%06XiKp8ga", NULL, 0, 2147483647, 906267487));
ft_printf("g3d9z%6s%019.0x%-u6pqCbGv%06XiKp8ga", NULL, 0, 2147483647, 906267487);

printf("pr_ret = [%d]\n",printf("8%015.0X%cSy27ooCqSKRfwn2g%.*u%.1s", 0, '\0', 9, -2147483647, NULL));
ft_printf("8%015.0X%cSy27ooCqSKRfwn2g%.*u%.1s", 0, '\0', 9, -2147483647, NULL);

printf("pr_ret = [%d]\n",printf("q1bByfFrNh7tRqc4r91ew%05.0d4crlGwjOS", 0));
ft_printf("q1bByfFrNh7tRqc4r91ew%05.0d4crlGwjOS", 0);

printf("pr_ret = [%d]\n",printf(" V8p%03.0i%-c%07.0XLPQq2Y%-17.*d", 1371470525, '\0', 0, -8, 0));
ft_printf(" V8p%03.0i%-c%07.0XLPQq2Y%-17.*d", 1371470525, '\0', 0, -8, 0);

printf("pr_ret = [%d]\n",printf("SG%xfCI%011.0u%010.*d%8cyqJ", -2147483647, 0, -4, -2147483647, '\0'));
ft_printf("SG%xfCI%011.0u%010.*d%8cyqJ", -2147483647, 0, -4, -2147483647, '\0');

printf("pr_ret = [%d]\n",printf("7yPz %017.*uqg1 g%0i%X86ee5NqzIWaqFn2c cHL", 0, 0, 2147483647, 1019449659));
ft_printf("7yPz %017.*uqg1 g%0i%X86ee5NqzIWaqFn2c cHL", 0, 0, 2147483647, 1019449659);

printf("pr_ret = [%d]\n",printf("LtoL%14.0XUqNol%08.0x%*c%.*uj%-13XSU", 2147483647, 0, -10, 'f', 8, 2147483647, -542783664));
ft_printf("LtoL%14.0XUqNol%08.0x%*c%.*uj%-13XSU", 2147483647, 0, -10, 'f', 8, 2147483647, -542783664);

*/ //END OF DESTRUCTOR







/* TESTED OK
printf("COUNT ERRORS WITH P\n");
  // printf("pr_ret = [%d]\n",printf("%20.p", NULL));
  // ft_printf("%20.p", NULL);
  // printf("pr_ret = [%d]\n",printf("%2.p", NULL));
  // ft_printf("%2.p", NULL);
  // printf("pr_ret = [%d]\n",printf("%5.p", NULL));
  // ft_printf("%5.p", NULL);
  // printf("pr_ret = [%d]\n",printf("%.0p", 0));
  // ft_printf("%.0p", 0);
  // printf("pr_ret = [%d]\n",printf("%-60p", p));
  // ft_printf("%-60p", p);
*/
/* tested OK
  printf("pr_ret = [%d]\n",printf("%-.12i", 20000000));
  ft_printf("%-.12i", 20000000);
  printf("pr_ret = [%d]\n",printf("%-.12u", 20000000));
  ft_printf("%-.12u", 20000000);
  printf("pr_ret = [%d]\n",printf("%-.12i", -20000000));
  ft_printf("%-.12i", -20000000);
  printf("pr_ret = [%d]\n",printf("%-.12u", -20000000));
  ft_printf("%-.12u", -20000000);
  printf("pr_ret = [%d]\n",printf("%-.12d", 20000000));
  ft_printf("%-.12d", 20000000);
  printf("\nsome other testing\n");
  printf("pr_ret = [%d]\n",printf("%-.12i", 2000));
  ft_printf("%-.12i", 2000);
  printf("pr_ret = [%d]\n",printf("%-1.12i", 2000));
  ft_printf("%-1.12i", 2000);
  printf("pr_ret = [%d]\n",printf("%-.12x", 2000));
  ft_printf("%-.12x", 2000);
  printf("pr_ret = [%d]\n",printf("%-.12X", 2000));
  ft_printf("%-.12X", 2000);
  printf("pr_ret = [%d]\n",printf("%.12i", 2000));
  ft_printf("%.12i", 2000);
  printf("pr_ret = [%d]\n",printf("%.5i", 200000));
  ft_printf("%.5i", 200000);
  printf("pr_ret = [%d]\n",printf("%.6i", -3));
  ft_printf("%.6i", -3);
  printf("pr_ret = [%d]\n",printf("%.6d", -3));
  ft_printf("%.6d", -3);
  printf("pr_ret = [%d]\n",printf("%.20x", -3));
  ft_printf("%.20x", -3);
  printf("pr_ret = [%d]\n",printf("%.20X", -3));
  ft_printf("%.20X", -3);
  printf("pr_ret = [%d]\n",printf("%.6u", -3));
  ft_printf("%.6u", -3);
  */

/*
printf("COUNT SHOULD BE [TEST 2 : 89] [TEST 3 : 51] [TEST 4 : 49] [TEST 5 : 145] [TEST 6 : 108] [TEST 7 : 26] [TEST 8 : 20] [TEST 9 : 44] [TEST 10 : 36] [TEST 11 : 19]   -- \n");
ft_printf("%011.*u%020d%-15iELX%-.3u0HyU6%-.1i%14x%-.1s\n", 0, 2147483647, 2147483647, -739268403, 2147483647, -2147483647, 0, "");
printf("\n");
ft_printf("%-7.3XD z9zjh%-u%-iFG0nPO%0*.*u\n", 0, -1182612630, -1309537738, -2, -9, 1069647547);
ft_printf("%0u3Fwfj%.4XNdU8q%-.0x%013.*X%%%i\n", 2147483647, 0, 0, 0, -1063362535, -1552614380);
printf("\n");
ft_printf("gKUp6%14.5xV4SbK%-s%-7s8%%Pzef\n", 0, "6Z0ZWDC4yB1xzFhb7wDgFuj9m7w5FuGquY4T1bc0GLWlYtQm7D7EJWTzgM", "xedRvAUdFhSHWa0 kczpE1nOAN5f1VcbKtQrdqjSWyeb2SL4fR8i6niiM");
ft_printf("ptdgV%03x23%-.3X%%M8b3TL%2s\n", 0, -1337152678, "III0gPIR7EJFNQUKVTdUiNTvf  Ks1rr9PS3XsxUAZJ5VXLPvRjd9gNDkGjXuUefARyfb3KrbXbNepA3fKk");
printf("\n");
ft_printf("%8ic5ERt%03Xd%-.2Xs\n", 0, 0, 2147483647);
ft_printf("3RdIIQO7BLWlvAaL%.4x\n", 0);
printf("\n");
ft_printf("%8.3i%15X%014X%-2xqLO\n", 2147483647, 1733619810, 0, 0);
ft_printf("%-.5x%s%4u%-ctyziQRyVc27\n", 0, "ooI47zd3X", 2147483647, '\0');
*/

//printf("[TEST]\n");

// printf("pr_ret = [%d]\n", printf("%10.5i\n", -216));
// ft_printf("%10.5i\n", -216);
// printf("pr_ret = [%d]\n", printf("%10.5d\n", -216));
// ft_printf("%10.5d\n", -216);
// printf("pr_ret = [%d]\n", printf("%3.7i\n", -1234));
// ft_printf("%3.7i\n", -1234);
// printf("pr_ret = [%d]\n", printf("%3.7d\n", -1234));
// ft_printf("%3.7d\n", -1234);
// printf("pr_ret = [%d]\n", printf("%6.7d\n", -1234));
// ft_printf("%6.7d\n", -1234);
// printf("pr_ret = [%d]\n", printf("%-10.5i\n", -216));
// ft_printf("%-10.5i\n", -216);
// printf("pr_ret = [%d]\n", printf("%-10.5i\n", 216));
// ft_printf("%-10.5i\n", 216);
// printf("pr_ret = [%d]\n", printf("%10.5i\n", -216));
// ft_printf("%10.5i\n", -216);
// printf("pr_ret = [%d]\n", printf("%010.5i\n", -216));
// ft_printf("%010.5i\n", -216);
// printf("pr_ret = [%d]\n", printf("%010.5i\n", -216));
// ft_printf("%010.5i\n", -216);
// printf("pr_ret = [%d]\n", printf("%010.5d\n", -216));
// ft_printf("%010.5d\n", -216);
// printf("pr_ret = [%d]\n", printf("%c\n", '\0'));
// ft_printf("%c\n", '\0');
// printf("pr_ret = [%d]\n", printf("%5c\n", '\0'));
// ft_printf("%5c\n", '\0');
// printf("pr_ret = [%d]\n", printf("%c\n", 0));
// ft_printf("%c\n", 0);
// printf("pr_ret = [%d]\n", printf("%c\n", -0));
// ft_printf("%c\n", -0);


// printf("pr_ret = [%d]\n",printf("%-14u%-2.5s", 2147483647,  "ABCDEFGH"));
// ft_printf("%-14u%-2.5s", 2147483647, "ABCDEFGH");

/* IS OK FROM DESTRUCTOR
printf("pr_ret = [%d]\n",printf("rsqEsTx%-14u%-uA1z%-2.5s", 2147483647, 0, "jR0vFEeSMDWQKvv6FF5HSfh7UojqL66E4P5k0x"));
ft_printf("rsqEsTx%-14u%-uA1z%-2.5s", 2147483647, 0, "jR0vFEeSMDWQKvv6FF5HSfh7UojqL66E4P5k0x");

printf("pr_ret = [%d]\n",printf("PKk4Oe1sLd%%%18.5XGjN%17c%-.*u", 2147483647, 'K', 5, 0));
ft_printf("PKk4Oe1sLd%%%18.5XGjN%17c%-.*u", 2147483647, 'K', 5, 0);

printf("pr_ret = [%d]\n",printf("KszFYW6Ve%0.*d%-x%16c%*d", 3, -2147483647, 0, '\0', 9, 2147483647));
ft_printf("KszFYW6Ve%0.*d%-x%16c%*d", 3, -2147483647, 0, '\0', 9, 2147483647);

printf("pr_ret = [%d]\n",printf("LFS%*cJ0bs96 W%0*X4JB%-.0si", -6, 'j', -8, 0, ""));
ft_printf("LFS%*cJ0bs96 W%0*X4JB%-.0si", -6, 'j', -8, 0, "");
printf("pr_ret = [%d]\n",printf("T3HHRX3D8owUjjy3xd%u", 0));
ft_printf("T3HHRX3D8owUjjy3xd%u", 0);
printf("pr_ret = [%d]\n",printf("%%Vp6%-8X%%I8udRp", 0));
ft_printf("%%Vp6%-8X%%I8udRp", 0);
printf("pr_ret = [%d]\n",printf("%0*X%%z8%0.1iZJ6%14uI9", 8, -2147483647, 2147483647, 0));
ft_printf("%0*X%%z8%0.1iZJ6%14uI9", 8, -2147483647, 2147483647, 0);
printf("pr_ret = [%d]\n",printf("%0*X%%z8%0.1iZJ6%14uI9", 8, -2147483647, 2147483647, 0));
ft_printf("%0*X%%z8%0.1iZJ6%14uI9", 8, -2147483647, 2147483647, 0);

printf("pr_ret = [%d]\n",printf("15RNpe4jQ66D%%b%-X%-.*s%-.2u", 0, 9, "D5 LfhRsAfc5UMwjDzYi2D8NXLcl EwJtuwrsE25mvAPVXKuYDTLJiutxMhuLTXbRoFE6zL9jldGo", 2147483647));
ft_printf("15RNpe4jQ66D%%b%-X%-.*s%-.2u", 0, 9, "D5 LfhRsAfc5UMwjDzYi2D8NXLcl EwJtuwrsE25mvAPVXKuYDTLJiutxMhuLTXbRoFE6zL9jldGo", 2147483647);

printf("pr_ret = [%d]\n",printf("BE %xEWCCI%-*s%xfI4nE3ntG", 0, 3, "", 0));
ft_printf("BE %xEWCCI%-*s%xfI4nE3ntG", 0, 3, "", 0);
*/


/* TO BE TESTED
printf("pr_ret = [%d]\n",printf("%2c%0xL%0*.*uckfUhOPS0MRFwzTJ", 'U', -2147483647, 7, 10, 0));
printf("pr_ret = [%d]\n",printf("jWDdJY2X%1.1xbZ5kc%-*.4iBVOp mp%*.0X", 1701813699, -8, -2147483647, 9, 0));
printf("pr_ret = [%d]\n",printf("%-s9E%.2i5Uhok%-.*xx1%2.5d%-2ikzny", "DcKazu48rXF1T8M2ftP4VwlijJUZ CBNlhnTuhMYIKjsBXLq3W3AJgNy1Q6Nu51Pi8ItXkWrBks", 2147483647, 10, 2147483647, 0, 1832762735));
printf("pr_ret = [%d]\n",printf("%0.3XyQqR6 S%-18.5X%0X%-4.3s", 0, 2147483647, 2147483647, ""));
printf("pr_ret = [%d]\n",printf("7jj7beRIHou9tw5N3h AA%x%i", 0, 2147483647));
printf("pr_ret = [%d]\n",printf("%020iq%0xhOOLh6n2 H6 K", 2147483647, 0));
printf("pr_ret = [%d]\n",printf("%4.1urUM9%-.3ucYbzBGSPZ%-.*xj%cTn", 2147483647, 1712379655, -2, 0, '0'));
printf("pr_ret = [%d]\n",printf("FN%-cm%-*.5x%-15.0i%csHFYKa", '\0', -8, -1988966657, 1545830339, '\0'));
printf("pr_ret = [%d]\n",printf("tRy lF%0XSb%c%-.3sn2Te9%-.0i", 0, '\0', "lWmSPKcQlU7syhVBJTLtnoz6bHO3JXMgWHpFOUKDEXMWwW5He4z2", -2147483647));
printf("pr_ret = [%d]\n",printf("%-13.*i%0u8pg%-da%%P7%12doXVac", 0, -2146227665, 0, 2147483647, 0));
printf("pr_ret = [%d]\n",printf("9Sk0F%xxuH%-15uypU%-c", 2147483647, 0, '\0'));
printf("pr_ret = [%d]\n",printf("6HP%13XnTo0DwHBT%.*x%%%%e", 2147483647, 4, 0));
printf("pr_ret = [%d]\n",printf("js05c%6X%3cLdABs", 0, 'Y'));
printf("pr_ret = [%d]\n", printf(" HlX%sN79HFbhL%02u%15s", "FKLYaGp02ST gJoZCKyusvyRtAmkU8adCcVEnso4SOKo9u1Bg6Qug6M7MmnwlSn7c9YQ2sNKLylUz0VlwgGcubcHmIaes99yTch", 0, "wHMjwkEb8ZiwpED0C3tiEWU7WcmaoBjQv8ilh9jGrRMMf2WUL"));
*/



/* TESTED FINE FROM DESTRUCTOR
// printf("_______ TEST 1 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_%.4Xff\n", 0));
// ft_printf("ft_%.4Xff\n", 0);
// printf("\n");

// printf("_______ TEST 2 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_%0.5umyX0Pb%.1xtSANX\n", 0, 317680477));
// ft_printf("ft_%0.5umyX0Pb%.1xtSANX\n", 0, 317680477);
// printf("\n");

printf("_______ TEST 3 _______\n");
printf("pr_ret = [%d]\n",printf("pr_%15c%.3i%-.5d%cUqg4G%*.0xdJTqY%2.5i5zjw\n", 'O', -2147483647, 2147483647, '\0', -2, -2147483647, -303980740));
ft_printf("ft_%15c%.3i%-.5d%cUqg4G%*.0xdJTqY%2.5i5zjw\n", 'O', -2147483647, 2147483647, '\0', -2, -2147483647, -303980740);
printf("\n");

printf("_______ TEST 4 _______\n");
printf("pr_ret = [%d]\n",printf("pr_%0.3i%i%0.3X3b%s7WY%-20.3usn\n", -2147483647, 2147483647, 0, "", 2147483647));
ft_printf("ft_%0.3i%i%0.3X3b%s7WY%-20.3usn\n", -2147483647, 2147483647, 0, "", 2147483647);
printf("\n");

// printf("_______ TEST 5 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_%% Jqc88MWUPaRt7sLRQcmH%*.2s%08u\n", -3, "", 0));
// ft_printf("ft_%% Jqc88MWUPaRt7sLRQcmH%*.2s%08u\n", -3, "", 0);
// printf("\n");

// printf("_______ TEST 6 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_qgSE1a%%%s6F8kLE1tZOS%0.5d%*.2x\n", "sCt", 0, -4, 0));
// ft_printf("ft_qgSE1a%%%s6F8kLE1tZOS%0.5d%*.2x\n", "sCt", 0, -4, 0);
// printf("\n");

// printf("_______ TEST 7 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_%%%-11.4XpRVd%012uMG%i%5c\n", 0, -2002548801, 45374464, '\0'));
// ft_printf("ft_%%%-11.4XpRVd%012uMG%i%5c\n", 0, -2002548801, 45374464, '\0');
// printf("\n");

// printf("_______ TEST 8 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_pAKn6oLb%11xV5d09 CcbyE%.3dUI\n", 0, 1462484091));
// ft_printf("ft_pAKn6oLb%11xV5d09 CcbyE%.3dUI\n", 0, 1462484091);
// printf("\n");

// printf("_______ TEST 9 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_vpvpVQASeefCWMw%-15c%-5.2X%.3sqJkB%19X\n", 'C', 0, NULL, 0));
// ft_printf("ft_vpvpVQASeefCWMw%-15c%-5.2X%.3sqJkB%19X\n", 'C', 0, NULL, 0);
// printf("\n");
//
// printf("_______ TEST 10 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_ClAeIL%0x%16.3sV6%-*.5X%-19.5s%0d%-14.0s\n", -972991318, "0p3rgir2K3nj31u9w5DHSRUZ4jlqNZM76eNFDJGqwI6", -2, 0, NULL, 0, ""));
// ft_printf("ft_ClAeIL%0x%16.3sV6%-*.5X%-19.5s%0d%-14.0s\n", -972991318, "0p3rgir2K3nj31u9w5DHSRUZ4jlqNZM76eNFDJGqwI6", -2, 0, NULL, 0, "");
// printf("\n");

// printf("_______ TEST 11 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_%9.1uJ6Nk9%c\n", 0, '\0'));
// ft_printf("ft_%9.1uJ6Nk9%c\n", 0, '\0');
// printf("\n");

// printf("_______ TEST 12 _______\n");
// printf("pr_ret = [%d]\n",printf("%-2XWzQaW%19cf%16.*u%-7XU d3My\n", 2147483647, '\0', -8, 76139018, 0));
// ft_printf("%-2XWzQaW%19cf%16.*u%-7XU d3My\n", 2147483647, '\0', -8, 76139018, 0);
// printf("\n");

// printf("_______ TEST 13 _______\n");
// printf("pr_ret = [%d]\n",printf("pr_%-i%0.2XQupEyBVr1RzgZ1ZxRqVs\n", 0, 0));
// ft_printf("ft_%-i%0.2XQupEyBVr1RzgZ1ZxRqVs\n", 0, 0);
// printf("\n");

printf("_______ TEST 14 _______\n");
printf("pr_ret = [%d]\n",printf("pr_%0d %.*d\n", 56, -1, 0));
ft_printf("ft_%0d %.*d\n", 56, -1, 0);

printf("_______ TEST 15 -- check ret _______\n");
printf("pr_ret = [%d]\n",printf("pr_%4d%0Xrhkx2VDu68iG%-12s%s %-c\n", 2048193663, 2147483647, NULL, "OTYGO02P gwvKn14CKGQqlyZyW2Cl5nmFxBGpN7GXIimT mKUthX", 'Y'));
ft_printf("ft_%4d%0Xrhkx2VDu68iG%-12s%s %-c\n", 2048193663, 2147483647, NULL, "OTYGO02P gwvKn14CKGQqlyZyW2Cl5nmFxBGpN7GXIimT mKUthX", 'Y');
printf("\n");

printf("_______ TEST 16 _______\n");
printf("pr_ret = [%d]\n", printf("Sw9%017.*d%-.5i%-*u4BAT07pMa1%18.3XnX4M6\n", -9, -2147483647, 2147483647, 2, 0, 2147483647));
ft_printf("Sw9%017.*d%-.5i%-*u4BAT07pMa1%18.3XnX4M6\n", -9, -2147483647, 2147483647, 2, 0, 2147483647);
printf("\n");

// printf("_______ TEST 17 _______\n");
// printf("pr_ret = [%d]\n", printf("pr_pA1%-10X\n", 0));
// ft_printf("pr_pA1%-10X\n", 0);
// printf("\n");

printf("_______ TEST 18 -- check ret _______\n");
printf("pr_ret = [%d]\n", printf("pr_%19X%c%c%c8oXn5wN%%%xeYI%c\n", 1197922221, '\0', 'p', '\0', -2147483647, '\0'));
ft_printf("ft_%19X%c%c%c8oXn5wN%%%xeYI%c\n", 1197922221, '\0', 'p', '\0', -2147483647, '\0');
printf("\n");

// printf("_______ TEST 19 _______\n");
// printf("pr_ret = [%d]\n", printf("pr_%%%6.3uQxr\n", 0));
// ft_printf("ft_%%%6.3uQxr\n", 0);
// printf("\n");

// printf("_______ TEST 20 _______\n");
// printf("pr_ret = [%d]\n", printf("pr_gy3O%-16.4uQkvvN9\n", 0));
// ft_printf("ft_gy3O%-16.4uQkvvN9\n", 0);
// printf("\n");

// printf("_______ TEST 21 -- check ret _______\n");
// printf("pr_ret = [%d]\n", printf("pr_%-.5dk8xyx1\n", 0));
// ft_printf("ft_%-.5dk8xyx1\n", 0);
// printf("_______ TEST 21 -- CUTTED _______\n");
// printf("pr_ret = [%d]\n", printf("pr_%-.5d\n", 0));
// ft_printf("ft_%-.5d\n", 0);
// printf("_______ TEST 21 -- CUTTED _______\n");
// printf("pr_ret = [%d]\n", printf("pr_%.5d\n", 0));
// ft_printf("ft_%.5d\n", 0);

// printf("pr_ret = [%d]\n", printf("F5%.*X%-9x", 8, 0, 0));
// ft_printf("F5%.*X%-9x", 8, 0, 0);
//
// // printf("pr_ret = [%d]\n", printf("C6i%%E%xxFadHR35Cwvy\n", 0));
// // ft_printf("C6i%%E%xxFadHR35Cwvy\n", 0);

// printf("pr_ret = [%d]\n", printf("5EgQX%-.2d%.4d%5d%%%02.2u%%M", -940080534, 1297237183, 1777747364, 0));
// ft_printf("5EgQX%-.2d%.4d%5d%%%02.2u%%M", -940080534, 1297237183, 1777747364, 0);
// printf("pr_ret = [%d]\n",printf("%-u%-.4x2jevQ%-.1igQJ2C", 0, 510500194, 2147483647));
// ft_printf("%-u%-.4x2jevQ%-.1igQJ2C", 0, 510500194, 2147483647);
// printf("pr_ret = [%d]\n",printf(" lHJe5ClYg%03.5x%-14.*uhFoQ%0.1i", -1272534814, 9, 0, 2147483647));
// ft_printf(" lHJe5ClYg%03.5x%-14.*uhFoQ%0.1i", -1272534814, 9, 0, 2147483647);
// printf("pr_ret = [%d]\n",printf("%-.0s%019.*x%*.2sn%0uAxJc%.1uywahkgiVHX", "", -3, 2147483647, 9, "", 901948135, 0));
// ft_printf("%-.0s%019.*x%*.2sn%0uAxJc%.1uywahkgiVHX", "", -3, 2147483647, 9, "", 901948135, 0);
// printf("pr_ret = [%d]\n",printf("%08uK%6.2iKVbs%-.2i%.*u%16.5s", 0, 0, 1067034831, 2, 2147483647, ""));
// ft_printf("%08uK%6.2iKVbs%-.2i%.*u%16.5s", 0, 0, 1067034831, 2, 2147483647, "");
// printf("pr_ret = [%d]\n",printf("%-13.3x%-x0%c7i%-12sPUTQntF7L", -2147483647, 0, '\0', ""));
// ft_printf("%-13.3x%-x0%c7i%-12sPUTQntF7L", -2147483647, 0, '\0', "");
printf("pr_ret = [%d]\n",printf("15RNpe4jQ66D%%b%-X%-.*s%-.2u", 0, 9, "D5 LfhRsAfc5UMwjDzYi2D8NXLcl EwJtuwrsE25mvAPVXKuYDTLJiutxMhuLTXbRoFE6zL9jldGo", 2147483647));
ft_printf("15RNpe4jQ66D%%b%-X%-.*s%-.2u", 0, 9, "D5 LfhRsAfc5UMwjDzYi2D8NXLcl EwJtuwrsE25mvAPVXKuYDTLJiutxMhuLTXbRoFE6zL9jldGo", 2147483647);

printf("pr_ret = [%d]\n",printf("PS%-.0d%08u%05d%clupPoD%07.3x%-16X", 0, 0, 930075297, '\0', 0, 2147483647));
ft_printf("PS%-.0d%08u%05d%clupPoD%07.3x%-16X", 0, 0, 930075297, '\0', 0, 2147483647);

*/


/* RESULTS YOU WANT
Pointer is '0'$
0x0$
0x0$
0x0$
0x$
                 0x0$
0x0000000000$
        0x0000000000$
*/

// printf("%.5x\n", -2372);
// ft_printf("%.5x\n", -2372);
  // printf("pr_%*.*d\n", -9, 4, 1555);
  // ft_printf("ft_%*.*d\n", -9, 4, 1555);
  //
  // printf("pr_%*.*d\n", 9, 4, 1555);
  // ft_printf("ft_%*.*d\n", 9, 4, 1555);
  //
  // printf("pr_%-*.*d\n", 9, 4, 1555);
  // ft_printf("ft_%-*.*d\n", 9, 4, 1555);
  //
  // printf("pr_%-*.*d\n", 9, 5, 1555);
  // ft_printf("ft_%-*.*d\n", 9, 5, 1555);
  //
  // printf("pr_%-*d\n", 9, 1555);
  // ft_printf("ft_%-*d\n", 9, 1555);
  // ft_printf("%-5p%-5p%-5p\n", &a, &a, &a);
  // printf("pr_ret is [%d]\n", printf("%-5p%-5p%-5p\n", &a, &a, &a));
  // ft_printf("%-20p\n", &a);
  // ft_printf("%.p\n", 0);
  // ft_printf("%20p\n", 0);
   // ft_printf("%.10p\n", 0);
   // ft_printf("%20.10p\n", 0);
  //ft_printf("%2.9p\n", 1234);
  // printf("%2.9p\n", 1234);
  // printf("%10.9p\n", 1234);
  // printf("%2p\n", 1234);
  // printf("%2.p\n", 1234);
  // printf("%.9p\n", 1234);
  // ft_printf("%2.9p\n", 1234);
  // ft_printf("%10.9p\n", 1234);
  // ft_printf("%2p\n", 1234);
  // ft_printf("%2.p\n", 1234);
  // ft_printf("%.9p\n", 1234);
  // printf("Pointer is '0'\n");
  // printf("%p\n", 0);
  // printf("%0p\n", 0);
  // printf("%-p\n", 0);
  // printf("%.p\n", 0);
  // printf("%20p\n", 0);
  // printf("%.10p\n", 0);
  // printf("%20.10p\n", 0);
  // printf("_____\n");
  // printf("Pointer is NULL\n");
  // printf("%p\n", NULL);
  // printf("%0p\n", NULL);
  // printf("%-p\n", NULL);
  // printf("%.p\n", 0);
  // printf("%20p\n", NULL);
  // printf("%.10p\n", NULL);
  // printf("Pointer is 1\n");
  // printf("%p\n", 1);
  // printf("%0p\n", 1);
  // printf("%-p\n", 1);
  // printf("%.p\n", 0);
  // printf("%20p\n", 1);
  // printf("%.10p\n", 1);

// AFF ain't right here
  // ft_printf("%9.2p\n", 1234);
  // ft_printf("%3.2p\n", 124);

  //doesn't print OX
  // printf("%3.2p\n", 124);
  // ft_printf("%3.2p\n", 124);
  // printf("%3.2p\n", 12);
  // printf("%3.20p\n", &p);
  // printf("%20.3p\n", &p);
  //ft_printf("ft_%7.p\n", 0); //SEGFAULT
  // ft_printf("%7.p\n", NULL); //SEGFAULT

  // ft_printf("%3.2p\n", 14);
  // ft_printf("%3.2p\n", 1234);
  // ft_printf("ft_%7p\n", NULL);
 // len prints 0x$
   // len prints 0x$
  //printf("%7.p\n", NULL);
  // ft_printf("ft_%7.1p\n", NULL); // should print OxO >> prints 0x
  // printf("pr_%7.1p\n", NULL);
  // ft_printf("%7.2p\n", NULL); // len prints 0x$
  // printf("%7.2p\n", NULL);
  // ft_printf("%2p\n", NULL);
  // ft_printf("%5p\n", NULL);
  // ft_printf("%.p\n", NULL);
  // ft_printf("%.5p\n", NULL);

// printf("%4p\n", p);
// ft_printf("%4p\n", p);
// printf("%p\n", p);
// ft_printf("%p\n", p);
  // printf("pr_ret = [%d]\n", printf("%5.4p\n", NULL));

  // ft_printf("%7.2p\n", NULL);
  // ft_printf("%5.3p\n", NULL); //
  // ft_printf("%5.4p\n", NULL); //
  //printf("pr_ret = [%d]\n", printf("%5.3p\n", NULL));
  // ft_printf("%0.10p\n", NULL);
  // printf("pr_ret = [%d]\n", printf("%.10p\n", NULL));
  // ft_printf("%10p\n", NULL);
  // printf("pr_ret = [%d]\n", printf("%10p\n", NULL));
  // ft_printf("%.10p\n", NULL);
  // printf("pr_ret = [%d]\n", printf("%.10p\n", NULL));
  // ft_printf("%.p\n", NULL);
  // printf("pr_ret = [%d]\n", printf("%.p\n", NULL));

//ft_printf("C'est %c\n", -8000);

//printf("res should be : 11-10-9-10\n");
// ft_printf("%5.0d\n", 0);
// ft_printf("%.0d\n", 0);
// ft_printf("%-3.7d\n", 1234); //-1
// ft_printf("%-8.5d\n", -12);
// ft_printf("%-8.5d\n", 12);
// ft_printf("%3.7i\n", -1234);
// ft_printf("%3.7u\n", -1234);
// ft_printf("%.i\n", 0);
// ft_printf("%.0d\n", 0);
// ft_printf("%.d\n", 0);
// ft_printf("%.0x\n", 0);
// ft_printf("%.x\n", 0);
// ft_printf("%.0X\n", 0);
// ft_printf("%.X\n", 0);
// ft_printf("%.0p\n", 0);
// ft_printf("%.p\n", 0);
// ft_printf("%.0i\n", '0');
// ft_printf("%.c\n", '0');
// ft_printf("%.0s\n", "0");
// ft_printf("%.s\n", "0");

// ft_printf("%-5.5i\n", -123);
// ft_printf("%-8.5i\n", -123);
// ft_printf("%-3.8i\n", -12);
// ft_printf("%-3.8i\n", 12);
// ft_printf("%3.8i\n", -12);
/* LOTS OF ERRORS
// ft_printf("%p\n", p);
// ft_printf("%2p\n", NULL);
// ft_printf("%5p\n", NULL);
// ft_printf("%.p\n", NULL);
// ft_printf("%.5p\n", NULL);
// ft_printf("%2.5p\n", NULL);
// ft_printf("%7.5p\n", NULL);
// ft_printf("%20.2p\n", 1234); //-2
// printf("ret = [%d]\n", printf("%20.2p\n", 1234));
//printf("%.5p\n", NULL);

// NOT WORKING
// ft_printf("%010.5i\n", -1234); //-1
// ft_printf("%03.7i\n", -1234); //-1
// ft_printf("%.7i\n", -3); //-1
// ft_printf("%3.7i\n", -1234); //-1

// // printf("____FLAG 0____\n");
// printf("Res should be : 8-4-11-11-9-6\n");
// ft_printf("%07i\n", -14);
// ft_printf("%03i\n", -14);
// ft_printf("%010.5i\n", -1234); //-1
// ft_printf("%010.3i\n", -1234);
// ft_printf("%03.7i\n", -1234); //-1
// ft_printf("%03.3i\n", -1234);
// // -1 when P>=aff_count - only when flag 0 == 1

// printf("____NEG==1 ARG==POS____\n");
// printf("res should be : 5-11-11-11-11\n");
// ft_printf("%-0d\n", 1234);
// ft_printf("%-10d\n", 1234);
// ft_printf("%-10.d\n", 1234);
// ft_printf("%-10.2d\n", 1234);
//ft_printf("%-10.7d\n", 1234); //+1
// // +1 when P>aff - not happening if neg=0 & arg='-'

// printf("____!W P____\n");
// ft_printf("%.7i\n", -3); //-1
// ft_printf("%.4i\n", -1234);
// ft_printf("%.2i\n", -1234);
// // wrong when P>aff_count

// printf("____W P____\n");
// ft_printf("%8.3i\n", -1234);
// ft_printf("%3.7i\n", -1234); //-1
// ft_printf("%3.3i\n", -1234);
// ft_printf("%-3.7i\n", -1234);
// // wrong when P>aff_count

// printf("____!P____\n");
// ft_printf("%d\n", -1234);
// ft_printf("%2d\n", -1234);
// ft_printf("%4d\n", -1234);
// ft_printf("%5d\n", -1234);
// ft_printf("%7i\n", -14);
// ft_printf("%5i\n", -1234);
// seems good to me

// printf("____NEG==0____\n");
// ft_printf("%0d\n", 1234);
// ft_printf("%10d\n", 1234);
// ft_printf("%10.2d\n", 1234);
// ft_printf("%.6d\n", 1234);
// //sounds good to me

// printf("____!W____\n");
// ft_printf("%-.0d\n", -1234);
// ft_printf("%-.2d\n", 1234);
// ft_printf("%-.4d\n", -1234);
// ft_printf("%-.6d\n", -1234);
// seems to work FINE

// printf("____DOUBLE_NEG____\n");
// ft_printf("%-10.2d\n", -1234);
// ft_printf("%-2d\n", -1234);
// ft_printf("%-d\n", -1234);
// ft_printf("%-10.2d\n", -1234);
// ft_printf("%-.4d\n", -3);
//seems good to me
*/


// printf("pr_%10.7s\n", "abcdefghijk");
// printf("pr_%10.12s\n", "abcdefghijk");

// ft_printf("ft_%20s\n", s); // ok
// ft_printf("ft_%20.7s\n", s); // lacks W
// ft_printf("ft_%10.7s\n", s); // lacks 3
// ft_printf("ft_%10.17s\n", s); // ok
// ft_printf("ft_%10.s\n", s); // ok
// ft_printf("ft_%10s\n", s); // ok
// ft_printf("ft_%20.s\n", s); // ok
// ft_printf("ft_%20s\n", s); // ok
// ft_printf("ft_%.s\n", s); // ok
// ft_printf("ft_%.7s\n", s); // ok
// ft_printf("ft_%.17s\n", s); // ok


// printf("pr_%7.2s\n", "hellolita");
// ft_printf("ft_%7.2s\n", "hellolita");
// printf("pr_%.*i\n", -32, -440);
// ft_printf("ft_%.*i\n", -32, -440);

//system("leaks a.out");
// printf("%010s %0d %5s %-10d %0.7s\n", "salut", 0, "fait", "1", "cho");
// ft_printf("%010s %0d %5s %-10d %0.7s\n", "salut", 0, "fait", "1", "cho");
//    printf("pr_salut %s c'estmoi %x %c %1c %0d %-10s\n", " ", 0, '\0', '\0', 1, "et je reviens");
// ft_printf("ft_salut %s c'estmoi %x %c %1c %0d %-10s\n", " ", 0, '\0', '\0', 1, "et je reviens");
//
// printf("%-f\n", 32.2);
// ft_printf("%-f\n", 32.2);


// printf("%d\n", -2147483648);
// ft_printf("%d\n", -2147483648);
//TO TEST -2147483648

// printf("ps_[%5.0c]\n", '\0');
// ft_printf("fs_[%5.0c]\n", '\0');

// printf("ret = %d\n", printf("ps_[%5.0c]\n", '\0'));
// ft_printf("ret = %d\n", ft_printf("fs_[%5.0c]\n", '\0'));

// printf("ps_[%5d]\n", 120);
// ft_printf("fs_[%5d]\n", 120);
/* TO BE RESOLVED
printf("pr_%020p\n", p);
ft_printf("ft_%020p\n", p);
____
ft_printf("ft_[%*.4d]\n", -9, 1234);
printf("pr_[%*.4d]\n", -9, 1234);
____
// Pb is only when P = strlen(aff)
// ft_printf("ft_[%*.*d]\n", 20, 10, -1234);
// printf("pr_[%*.*d]\n", 20, 10, -1234);
*/

// NOT RESOLVED
// ft_printf("return %-5%\n");
// printf("return %-5%\n");
// ft_printf("ft_%05d \n", 1);
// printf("pr_%05d \n", 1);

// ft_printf("ft_%05d %c \n", 1, 'a');
// printf("pr_%05d %c \n", 1, 'a');

// ft_printf("ft_%05d %c %s\n", 1, '\0', NULL);
// printf("pr_%05d %c %s\n", 1, '\0', NULL);

// ft_printf("ret = %d\n", ft_printf("ft_%-5c\n", '\0'));
// printf("ret = %d\n", printf("pr_%-5c\n", '\0'));
// ft_printf("ft_%-5c\n", '\0');
// printf("pr_%-5c\n", '\0');
// ft_printf("ft_%c\n", '\0');
// printf("pr_%c\n", '\0');
// ft_printf("ft_%5c\n", '\0');
// printf("pr_%5c\n", '\0');
// ft_printf("ft_%-5c\n", '\0');
// printf("pr_%-5c\n", '\0');

// printf("test is p value = p - [W : 5]\n");
// printf("1pr_[%5.p]\n", NULL);
// ft_printf("1ft_[%5.p]\n", NULL);
// ft_printf("\n");
//
// printf("test is p value = p - [W : 5]\n");
// printf("1pr_[%5.10p]\n", NULL);
// ft_printf("1ft_[%5.10p]\n", NULL);
// ft_printf("\n");

// printf("test is p value = 1\n");
// printf("1pr_[%p]\n", 1);
// ft_printf("1ft_[%p]\n", 1);
// ft_printf("\n");

// printf("test is p value = 0 - P[-1]\n");
// printf("1pr_[%p]\n", 0);
// ft_printf("1ft_[%p]\n", 0);
// ft_printf("\n");

// printf("test is p value = 0 - P[0]\n");
// printf("1pr_[%.p]\n", 0);
// ft_printf("1ft_[%.p]\n", 0);
// ft_printf("\n");

// printf("test is p value = p\n");
// printf("1pr_[%p]\n", p);
// ft_printf("1ft_[%p]\n", p);
// ft_printf("\n");

// printf("test is p value = p - Width [15] - P [-1]\n");
// printf("1pr_[%15p]\n", p);
// ft_printf("1ft_[%15p]\n", p);
// ft_printf("\n");
//
// printf("test is p value = p - Width [10] - P [-1]\n");
// printf("1pr_[%-20p]\n", p);
// ft_printf("1ft_[%-20p]\n", p);
// ft_printf("\n");

//P > always got 2 zeros less
// printf("test is 13.p value = -1\n");
// printf("1pr_[%13.p]\n", -1);
// ft_printf("1ft_[%13.p]\n", -1);
// ft_printf("\n");

// printf("test is 13.p value = 1\n");
// printf("2pr_[%13.p]\n", 1);
// ft_printf("2ft_[%13.p]\n", 1);
// ft_printf("\n");
//
// printf("test is 13.p value = 0\n");
// printf("2pr_[%13.p]\n", 0);
// ft_printf("2ft_[%13.p]\n", 0);
// ft_printf("\n");

// printf("test is 3.12p value = -1\n");
// printf("3pr_[%3.12p]\n", -1);
// ft_printf("3ft_[%3.12p]\n", -1);
// ft_printf("\n");

// printf("test is .13p value = -1\n");
// printf("4pr_[%.13p]\n", -1);
// ft_printf("4ft_[%.13p]\n", -1);
// ft_printf("\n");
//
// printf("test is .5p value = 1\n");
// printf("5pr_[%.5p]\n", 1);
// ft_printf("5ft_[%.5p]\n", 1);
// ft_printf("\n");






// ft_printf("ft_[%*.4d]\n", -9, 1234);
// printf("pr_[%*.4d]\n", -9, 1234);

//Basic test here
// if P == -1 -- neg != 1 spacing is good
//>> neg == 0 || neg == -
// si P < strlen(aff) et neg == 1 >>> un espace en trop
// printf("1pr_[%0-8.2i]\n", -123);
// ft_printf("1ft_[%0-8.2i]\n", -123);
// printf("2pr_[%-8.5i]\n", -123);
// ft_printf("2ft_[%-8.5i]\n", -123);
// printf("3pr_[%-8.5i]\n", 12);
// ft_printf("3ft_[%-8.5i]\n", 12);
// printf("4pr_[%0-8.3u]\n", 1234);
// ft_printf("4ft_[%0-8.3u]\n", 1234);
// printf("5pr_[%0-8.3u]\n", 1234);
// ft_printf("5ft_[%0-8.3u]\n", 1234);
// printf("2pr_[%0-8.10i]\n", 123);
// ft_printf("2ft_[%0-8.10i]\n", 123);
// printf("2ft_[%.s]\n", "coucou");
// ft_printf("2ft_[%.s]\n", "coucou");
// ft_printf("1ft_ret = %d\n", ft_printf("1ft_[%*.*u]\n", -12, 10, -50));
// printf("1pr_ret = %d\n", printf("1pr_[%*.*u]\n", -12, 10, -50));
// printf("2pr_ret = %d\n", printf("2pr_[%*.*d]\n", 100, 50, -300));
// ft_printf("2ft_ret = %d\n", ft_printf("2ft_[%*.*d]\n", 100, 50, -300));
//>>> lacks one space
// ft_printf("2ft_ret = %d\n", ft_printf("2ft_[%*.*d]\n", -9, 2, 100));
// printf("2pr_ret = %d\n", printf("2pr_[%*.*d]\n", -9, 2, 100));
//is good

// printf("1pr_ret = %d\n", printf("1%%p::pr_[%10.1s]\n", "coucou"));
// ft_printf("1ft_ret = %d\n", ft_printf("1%%p::ft_[%10.1s]\n", "coucou"));
// printf("2pr_ret = %d\n", printf("2%%p::pr_[%10.12s]\n", "coucou et puis je sais pas"));
// ft_printf("2ft_ret = %d\n", ft_printf("2%%p::ft_[%10.12s]\n", "coucou et puis je sais pas"));



// ft_printf("fv_[%*.4d]\n", -3, 1234);
// printf("pv_[%*.4d]\n", -3, 1234);

// ft_printf("fs_[%*.3d]\n", -9, 1234);
// printf("ps_[%*.3d]\n", -9, 1234);

// ft_printf("fu_[%*.4d]\n", -9, 12345);
// printf("pu_[%*.4d]\n", -9, 12345);

// ft_printf("ft_[%*.10s]\n", -9, "coucou");
// printf("pr_[%*.10s]\n", -9, "coucou");

// printf("0pr_ret = %d\n", printf("3%%p::pr_[%0.0d]\n", 0));
// ft_printf("0ft_ret = %d\n", ft_printf("3%%p::ft_[%0.0d]\n", 0));


// printf("3pr_ret = %d\n", printf("3%%p::pr_[%7.0s]\n", "coucou"));
// ft_printf("3ft_ret = %d\n", ft_printf("3%%p::ft_[%7.0s]\n", "coucou"));
// printf("3pr_ret = %d\n", printf("3%%p::pr_[Hello 1 %10.12s - Hello 2 %10s]\n", "coucou", "toi"));
// ft_printf("3ft_ret = %d\n", ft_printf("3%%p::ft_[Hello 1 %10.12s - Hello 2 %10s]\n", "coucou", "toi"));


//If W > P OK /
// If P > W : 1st print space then 0
  // printf("pr_%*.*x\n", 10, 20, 2);
  // ft_printf("ft_%*.*x\n", 10, 20, 2);
  // printf("pr_%*.*x\n", 20, 20, 2);
  // ft_printf("ft_%*.*x\n", 20, 20, 2);
  // printf("pr_%*.*d\n", 3, 4, 2);
  // printf("ps_%*.*x\n", 3, 4, 2);
  // ft_printf("fs_%*.*x\n", 3, 4, 2);
  //
  // printf("pps_%*x\n", 3, 2);
  // ft_printf("ffs_%*x\n", 3, 2);
// ft_printf("ft_[%15p]\n", NULL);
// ft_printf("ft_[%015p]\n", NULL); //should start with 0x0 but is starting with flags
  // printf("pr_[%-05d]\n", -8765);
  // printf("pr_[%-5d]\n", -8765);
  // ft_printf("ft_[%-05d]\n", -8765);
  // ft_printf("ft_[%-5d]\n", -8765);

  // printf("ps_[%10d]\n", -8765);
  // ft_printf("fs_[%10d]\n", -8765);
  // printf("pr_[%01.20d]\n", -8765);
  // ft_printf("ft_[%01.20d]\n", -8765);

  // printf("ps_[%10d]\n", -2345);
  // ft_printf("fs_[%10d]\n", -2345);


  // printf("pr_[%7.8d]\n", -2345);
  // ft_printf("fr_[%7.8d]\n", -2345);
  // printf("ps_[%2.3d]\n", -2345);
  // printf("\n");

// printf("%.*\n"); // WARNING
// ft_printf("%.*\n"); // --> prints .*

// ft_printf("ft_[%010.1d]\n", -8888);
// printf("pr_[%010.1d]\n", -8888);
// ft_printf("fs_[%010.1s]\n", "8888");
// printf("ps_[%010.1s]\n", "8888");


// ft_printf("ft_%10.16s\n", s);
// printf("pr_%10.16s\n", s);
// printf("pr_%.4u %d\n", 10020, d);
// ft_printf("ft_%.4u %d\n", 10020, d);
// THE 0 EXCEPTION IN D
// on tests below, 0 should not be printed but 0 taken in account
// printf("pr_%.*d\n", 0, 0);
// printf("pr_%10.0x\n", 0);
// printf("pr_%50.3x\n", 20);
// ft_printf("ft_%50.3x\n", 20);
// printf("pr_%.2x\n", -20);
// ft_printf("ft_%.2x\n", -20);
// printf("pr_%010d\n", 20);
// ft_printf("ft_%010d\n", 20);
// printf("pr_%.0u\n", 0);

// ft_printf("%.0d\n", 1);
// ft_printf("2. %4.4d\n", 111);
// ft_printf("%2.2d\n", 1);
// ft_printf("%2.7d\n", 1);
// ft_printf("%2.8d\n", 1);

// printf("%10s\n", s);
// printf("test is W = 10 -- P = 5\n");
// printf("%10.5d\n", 1);
// // printf("%10.5s\n", s);
// printf("test is W = 5 -- P = 10\n");
// printf("%5.10d\n", 1);
// // printf("%5.10s\n", s);
// printf("test is W = 2 -- P = 5 -- arg_count = 3\n");
// printf("%2.5d\n", 111);
// // printf("%2.5s\n", "hey");
// printf("test is W = 5 -- P = 2 -- arg_count = 3\n");
// printf("%5.2d\n", 111);
// // printf("%5.2s\n", "hey");
// printf("test is W = -2 -- P = 0 -- arg_count = 3\n");
// printf("%2.0d\n", 111);

// below, ft_count is +1
// printf("pr_ret : %d\n", printf("pr_%.0i\n", -10));
// ft_printf("ft_ret : %d\n", ft_printf("ft_%.0i\n", -10));

// printf("pr2_%.8i\n", -10);
// printf("pr3_%*.8i\n", -5, -10);
// don't see the diff here - weird pb
// ft_printf("1. %10.2x\n", -20);
// printf("1/ %10.2x\n", -20);

// RETURNED FALSE FROM PERSONAL TESTS
// ft_printf("%4.1d\n", 20);
// printf("%4.1d\n", 20);

  // ft_printf("%*.6d\n", 3, d);
  // printf("%*.6d\n", 3, d);
  //ft_printf("%0x\n", x);
  //ft_printf("%03.2x\n", x);
  //printf("%03.2x\n", x);
  // ft_printf("voila %%%\n", 'a');
  // printf("voila %%%\n", 'a');
  // ft_printf("%s %03.2x %2.4p %02.4d %05d %10c %-x %-X %% % d %q %%%\n", "", x, p, d, d, 'a', x, X);
  // printf("%s %03.2x %2.4p %02.4d %05d %10c %-x %-X %% % d %q %%%\n", "", x, p, d, d, 'a', x, X);

  // ft_printf("%03.2d\n", d);
  // printf("%03.2d\n", d);
  // ft_printf("%3.2d\n", d);
  // printf("%3.2d\n", d);
  // ft_printf("%3d\n", d);
  // printf("%3d\n", d);
  //printf("%0x\n", x);
  //ft_printf("%3.2p\n", p);

  // D Basics without prec - testing OK
  // ft_printf("%3.2d\n", d);
  //printf("%3.2d\n", d);
  //printf("%03.2d\n", d);
  //ft_printf("%03.2d\n", d);
  // printf("%3d\n", d);
  // ft_printf("%3.10d\n", d);
  // printf("%3.10d\n", d);
  // ft_printf("%-3.2d\n", d);
  // printf("%-3.2d\n", d);
  // ft_printf("%03.5d\n", d);
  // printf("%03.5d\n", d);
  // ft_printf("%3.5d\n", d);
  // printf("%3.5d\n", d);
  // ft_printf("%-2.2d\n", d);
  // printf("%-2.2d\n", d);
  // ft_printf("%-4.2d\n", d);
  // printf("%-4.2d\n", d);
  // ft_printf("%-4.3d\n", d);
  // printf("%-4.3d\n", d);

  // C Basics without prec - testing OK
  // ft_printf("%s %s\n", s, s);
  // printf("%s %s\n", s, s);
  // ft_printf("%0s\n", s);
  // printf("%0s\n", s);

  // ft_printf("%2s\n", s);
  // printf("%2s\n", s);
  // ft_printf("%20s\n", s);
  // printf("%20s\n", s);
  // ft_printf("%-10s\n", s);
  // printf("%-10s\n", s);
  // ft_printf("%10.20s\n", s);
  // printf("%10.20s\n", s);

  //ok but not properly ok because of free problems
  //char *s = "hello";
  // ft_printf("%-20.10s\n", s); // // set a breakpoint in malloc
  // printf("%-20.10s\n", s);
  // ft_printf("%10.2s\n", s); // set a breakpoint in malloc
  // printf("%10.2s\n", s);
  // ft_printf("%-*d\n", 3, d);
  // printf("%-*d\n", 3, d);
  // ft_printf("%*.6d\n", 3, d);
  // printf("%*.6d\n", 3, d);
  // ft_printf("%*.*d\n", 3, 6, d);
  // printf("%*.*d\n", 3, 6, d);

  // OK
  //ft_printf("%4.2s\n", s);
  // ft_printf("%4.1s %10s\n", s, s);
  // ft_printf("%4.1s %10s %2d, %2.4d\n", s, s, d, d);
  // ft_printf("%*d\n",10, d);
  // ft_printf("%*.*s %*d\n", 5, 7, s, 10, d);
  // printf("%*.*s %*d\n", 5, 7, s, 10, d);
  // ft_printf("%0-4.5s %5.2d\n", s, d);
  // printf("%0-4.5s %5.2d\n", s, d);
  // ft_printf("%-0.2s\n", s);
  // printf("%-0.2s\n", s);

  // ONLY D TESTINGS
  //OK tests
  // ft_printf("%5.3d\n", d);
  // printf("%5.3d\n", d);
  // ft_printf("%22d\n", d);  // W
  // printf("%22s\n", s);
  // ft_printf("%-2d\n", d);  // W && neg
  // ft_printf("%-2.4d\n", d); // W N P  // P > W
  // ft_printf("%-4.5d\n", d); // W N P  // P > W // 1 seul écart
  // ft_printf("%-4.4d\n", d); // W N P // W = P
  // ft_printf("%-4.6d\n", d); // W && neg && prec // W > P
  // ft_printf("%-4.5d\n", d); // W N P  // W > P // 1 seul écart
  // ft_printf("%-1d\n", d); // -1W
  // ft_printf("%x\n", x); // x
  // ft_printf("%10.22d\n", d); // P > W
  // ft_printf("%0-3.20d\n", d); // Z W N P
  // ft_printf("%12.10p lala\n", p); // W P and *arg
  // ft_printf("%02.2d\n", d); // Z W P
  // ft_printf("%2.2d\n", d); // P = W
  // ft_printf("%03.2d\n", d);
  // ft_printf("%3.2d\n", d);
  // ft_printf("%04.1d\n", d);
  // ft_printf("%-4.10d\n", d);
  // ft_printf("%2d\n", d);
  // ft_printf("%02d\n", d);

  //ft_printf("%-23d\n", d);
  //*/ UNCHECKED


  // printf("zero is 0 - neg is 1 -- width is 2 -- prec is 4 // P > W \n");
  // printf("%-2.4d\n", d);
   //not working anymore
  //ft_printf("%-20s %d\n", s, d);
  //printf("%-20s\n", s);
  // ft_printf("%2d salut %-5d\n", d, d); //not writing last 0 down but entering function... only %-5d works fine...
  // printf("%2d salut %-5d\n", d, d);
  // ft_printf("%2d\n", d);
  // printf("%2d\n", d);
   // ft_printf("%-2d\n", d);
   // printf("%-2d\n", d);
  // ft_printf("%-2.4d\n", d);
  // ft_printf("%4.2d\n", d);
  // ft_printf("%-4.2d\n", d);
  //
  // ft_printf("\n");
  // ft_printf("this is now printf results\n");
  // printf("%-23s\n", s);
  // printf("%2d\n", d);
  // printf("%-2d\n", d);
  // printf("%-2.4d\n", d);
  // printf("%4.2d\n", d);
  // printf("%-4.2d\n", d);

  // ft_printf("%-4.3d\n", d);
  // printf("%-4.3d\n", d);
  // printf("%23s--\n", s);
  // ft_printf("%23s--\n", s);
  //ft_printf("%2.4d--\n", 1);
  //ft_printf("%23s--\n", 1);
  // printf("%0*s\n", s);
  // printf("%0*s\n", s);

  // FLAGS 0 and - can NOT be combined

  // ft_printf("yo c moi");
   // ft_printf("%-2.8d %p\n", &s);
  //ft_printf("%d %s\n", d, s);
  // ft_printf("salut\n");
  //printf("%-2.4d--\n", 1);
  // ft_printf("%2.1d\n", 1);
  // printf("%2.1d--\n", 1);

// TESTING GOOD
  //ft_printf("%5.1d %3.20s %d\n", d, s, d);
  //printf("%-20.2d %10.15s yo\n", d, s);
  //printf("%-3.10d%s-- printf_result\n", d, s);
  //ft_printf("\n");
  // ft_printf("%%%%%s -- my result\n", s);
  // printf("%%%%%s -- printf_result\n", s);

  // ft_printf("\n");
  // ft_printf("test is : modulo22d coucou\n");
  // ft_printf("%22d coucou --- \n", d);
  // printf("%22d coucou --- \n", d);
  // ft_printf("test is : modulo2d 2s\n");
  // ft_printf("%2d %2s coucou --- \n", d, s);
  // printf("%2d %2s coucou --- \n", d, s);
  // ft_printf("test is : modulo022d 2s\n");
  // ft_printf("%022d %2s coucou --- \n", d, s);
  // printf("%022d %2s coucou --- \n", d, s);
  // ft_printf("\n");

  // d = 11;
  // printf("test is : modulo05d\n");
  // ft_printf("%05d\n", d);
  // printf("%05d   --- showing printf result\n", d);
  // printf("test is : modulo010d\n");
  // ft_printf("%010d\n", d);
  //
  // ft_printf("test is : modulo2d\n");
  // ft_printf("%2d\n", d);
  // printf("%2d\n", d);
//*/

  // ft_printf("test is : modulo2.2d\n");
  // ft_printf("%02.3d\n", d);
  // printf("%02.3d --printf\n", d);
  // ft_printf("%123d\n", d);
  // printf("%123d ---printf\n", d);
  // ft_printf("%6.4d\n", d);
  // printf("%6.4d ---printf\n", d);
  // ft_printf("%8.3d\n", d);
  // printf("%8.3d ---printf\n", d);

  // not working anymore
  // ft_printf("%02d\n", d);
  // printf("%02d\n", d);
  // ft_printf("%-20d\n", d);
  // printf("%-20d\n", d);
  // ft_printf("%.3d\n", d);
  // printf("%.3d\n", d);
  // ft_printf("%-23.5d\n", d);
  // // printf("%-23.5d\n", d);
  // ft_printf("%-2.3d\n", d);
  // printf("%-2.3d\n", d);


  // printf("%3.4d\n", d);
  // printf("%2.10d\n", d);
  //printf("%2d\n", d);
  // ft_printf("test is : modulo-2.2d\n");
  // ft_printf("%-2.2d\n", d);
  // printf("%-2.2d\n", d);
  // ft_printf("test is : modulo5.2d\n");
  // ft_printf("%5.2d\n", d);
  // printf("%5.2d\n", d);
  // ft_printf("test is : modulo05.2d\n");
  // ft_printf("%05.2d\n", d);
  // printf("%05.2d\n", d);

  // printf("lalala %-5d\n", d); // cree 4 espaces apres le 1
  // printf("lalala %-3d\n", d);
  // printf("%-100d\n", d);
  // printf("%d\n", d);
  // printf("%02d\n", d);
  //printf("%000d\n", d);
  // ft_printf("%02d\n", d);
  //printf("%02d\n", d);

  // ft_printf("%0d %s\n", d, s);
  // ft_printf("%d\n", -d);
  // ft_printf("%d\n", 0);
  // ft_printf("%d\n", -2147483648);
  // ft_printf("%d\n", 2147483647);
  // printf("%02d%2d\n", d, d);
  // printf("%2d%02d\n", d, d);
  // printf("%0100d\n", d);
  // ft_printf("______________________\n");
  // ft_printf("%s\n", s);
  // ft_printf("%s\n", "PartTwo");
  // ft_printf("%01s\n", s);
  // ft_printf("%02s\n", s);





  /* OK TESTS - SHOULD ALL WORK FINE
  printf("TESTING MODULOS\n");
  printf("pr_%%\n");
  ft_printf("ft_%%\n");
  printf("pr_%%%\n");
  ft_printf("ft_%%%\n");
  printf("pr_%%%d\n", d);
  ft_printf("ft_%%%d\n", d);
  printf("pr_%\n");
  ft_printf("ft_%\n");
  printf("pr_%10%\n");
  ft_printf("ft_%10%\n");

  _____ THE S AND C TESTINGS _____
  printf("when S > P\n");
  printf("pr_%020.1c\n", 'a');
  ft_printf("ft_%020.1c\n", 'a');
  printf("pr_%020.1s\n", s);
  ft_printf("ft_%020.1s\n", s);
  printf("pr_%10.0s\n", s);
  ft_printf("ft_%10.0s\n", s);
  printf("pr_%-10.2c\n", 'a');
  ft_printf("ft_%-10.2c\n", 'a');
  printf("pr_%-10.10c\n", 'a');
  ft_printf("ft_%-10.10c\n", 'a');

  ____ START AGAIN HERE _____
  printf("when S <= P\n");
  printf("pr_%10.15s\n", s);
  ft_printf("ft_%10.15s\n", s);
  printf("pr_%10.16s\n", s);
  ft_printf("ft_%10.16s\n", s);
  printf("when S <= W\n");
  printf("pr_%015.11s\n", s);
  ft_printf("ft_%015.11s\n", s);
  printf("pr_%16.11s\n", s);
  ft_printf("ft_%16.11s\n", s);
  printf("when S > P = W\n");
  printf("pr_%11.11s\n", s);
  ft_printf("ft_%11.11s\n", s);
  printf("when S < P = W\n");
  printf("pr_%15.15s\n", s);
  ft_printf("ft_%15.15s\n", s);
  printf("when S = ""\n");
  printf("pr_%5.0s\n", "");
  ft_printf("ft_%5.0s\n", "");
  printf("when P = 0\n");
  printf("pr_%15.0s\n", s);
  ft_printf("ft_%15.0s\n", s);
  printf("when W = 0\n");
  printf("pr_%0.15s\n", s);
  ft_printf("ft_%0.15s\n", s);
  printf("when W = 0 && P>S\n");
  printf("pr_%0.20s\n", s);
  ft_printf("ft_%0.20s\n", s);
  printf("%20.10s\n", s);
  printf("%10.0s\n", s);
  printf("pr_%-10.2s\n", s);
  ft_printf("ft_%-10.2s\n", s);

  printf("pr_%s -empty line\n", "");
  ft_printf("ft_%s -empty line\n", "");
  printf("%-0s\n", s);
  ft_printf("%-0s\n", s);
  printf("%.0s -P==0\n", s);
  ft_printf("%.0s -P==0\n", s);
  printf("%10s -W=10\n", s);
  ft_printf("%10s -W=10\n", s);

  printf("pr_%0.8s -P==3\n", "Test");
  ft_printf("ft_%0.8s -P==3\n", "Test");
  printf("%10.3s\n", "Test");
  ft_printf("%10.3s\n", "Test");
  printf("%3.10s\n", "Test");
  ft_printf("%3.10s\n", "Test");
  printf("%-3.10s\n", "Test");
  ft_printf("%-3.10s\n", "Test");
  printf("%-10.3s\n", "Test"); //prints Tes and 7 spaces
  ft_printf("%-10.3s\n", "Test");

  PART OF D TESTINGS
  printf("___ W > P\n");
  printf("%7d\n", 1);
  ft_printf("%7d\n", 1);
  printf("pr_%7.2d\n", 1);
  ft_printf("ft_%7.2d\n", 1);
  printf("pr_%07.1c\n", 'c');
  ft_printf("ft_%07.1s\n", s);
  printf("%07.6d\n", 1);
  ft_printf("%07.6d\n", 1);

  printf("___ P >= W\n");
  printf("%01.4d\n", 111);
  ft_printf("%01.4d\n", 111);
  printf("%04.4d\n", 111);
  ft_printf("%04.4d\n", 111);
  printf("%02.2d\n", 1);
  ft_printf("%02.2d\n", 1);
  printf("%02.7d\n", 1);
  ft_printf("%02.7d\n", 1);
  printf("%02.8d\n", 1);
  ft_printf("%02.8d\n", 1);
  printf("2. %1.4d\n", 111);
  ft_printf("2. %1.4d\n", 111);
  */

  /* TESTS FOR NEG VALUE AND ZERO FLAG
  printf("pr_[%10.8d]\n", -8765);
  ft_printf("ft_[%10.8d]\n", -8765);
  // printf("*arg == ['d'] -- W = [2] - P = [8] - aff is [-8765]\n");
  // printf("pr_[%8.2d]\n", -8765);
  // ft_printf("ft_[%8.2d]\n", -8765);
  // printf("*arg == ['d'] -- W = [3] - P = [2] - aff is [-8765]\n");
  // printf("pr_[%3.2d]\n", -8765);
  // ft_printf("fs_[%3.2d]\n", -8765);
  // printf("\n");

  // printf("*arg == ['s'] -- W = [10] - P = [2] - aff is [-8765]\n");
  // printf("ps_[%010.2s]\n", "-8765");
  // printf("*arg == ['d'] -- W = [10] - P = [2] - aff is [-8765]\n");
  // printf("pr_[%010.2d]\n", -8765);
  // printf("ps_[%10.2d]\n", -8765);
  // ft_printf("ft_[%010.2d]\n", -8765);
  // ft_printf("fs_[%10.2d]\n", -8765);
  // printf("\n");

  // printf("*arg == ['d'] -- W = [10] - P = [4] - aff is [-8765]\n");
  // printf("pr_[%010.4d]\n", -8765);
  // printf("pr_[%10.4d]\n", -8765);
  // ft_printf("ft_[%010.4d]\n", -8765);
  // ft_printf("fs_[%10.4d]\n", -8765);
  // printf("\n");

  // printf("*arg == ['d'] -- W = [3] - P = [10] - aff is [-8765]\n");
  // printf("pr_[%03.10d]\n", -8765);
  // printf("ps_[%3.10d]\n", -8765);
  // ft_printf("ft_[%03.10d]\n", -8765);
  // ft_printf("fs_[%3.10d]\n", -8765);
  // printf("\n");


  // printf("*arg == ['d'] -- W = [10] - P = [5] - aff is [-8765]\n");
  // printf("pr_[%010.5d]\n", -8765);
  // printf("ps_[%10.5d]\n", -8765);
  // ft_printf("ft_[%010.5d]\n", -8765);
  // ft_printf("fs_[%10.5d]\n", -8765);
  // printf("\n");


  // printf("*arg == ['s'] -- W = [10] - P = [0] - aff is [-8765]\n");
  // printf("ps_[%010.0s]\n", "-8765");
  // printf("*arg == ['d'] -- W = [10] - P = [0] - aff is [-8765]\n");
  // printf("pr_[%010.0d]\n", -8765);
  // printf("ps_[%10.0d]\n", -8765);
  // ft_printf("ft_[%010.0d]\n", -8765);
  // ft_printf("fs_[%10.0d]\n", -8765);
  // printf("\n");

  // printf("*arg == ['d'] -- W = [10] - P = [-1] - aff is [-8765]\n");
  // printf("pr_[%010d]\n", -8765);
  // printf("ps_[%10d]\n", -8765);
  // ft_printf("ft_[%010d]\n", -8765);
  // ft_printf("fs_[%10d]\n", -8765);
  // printf("\n");

  // printf("*arg == ['d'] -- W = [3] - P = [-1] - aff is [-8765]\n");
  // printf("pr_[%03d]\n", -8765);
  // printf("ps_[%3d]\n", -8765);
  // ft_printf("ft_[%03d]\n", -8765);
  // ft_printf("fs_[%3d]\n", -8765);
  // printf("\n");

  // printf("*arg == ['d'] -- W = [5] - P = [-1] - aff is [-8765]\n");
  // printf("pr_[%05d]\n", -8765);
  // printf("ps_[%5d]\n", -8765);
  // ft_printf("ft_[%05d]\n", -8765);
  // ft_printf("fs_[%5d]\n", -8765);
  // printf("\n");

  // printf("*arg == ['d'] -- W = [] - P = [1] - aff is [-8765]\n");
  // printf("pr_[%0.1d]\n", -8765);
  // printf("ps_[%.1d]\n", -8765);
  // ft_printf("ft_[%0.1d]\n", -8765);
  // ft_printf("fs_[%.1d]\n", -8765);
  // printf("\n");

  // printf("*arg == ['d'] -- W = [] - P = [] - aff is [-8765]\n");
  // printf("pr_[%0d]\n", -8765);
  // printf("pr_[%d]\n", -8765);
  // ft_printf("pr_[%0d]\n", -8765);
  // ft_printf("pr_[%d]\n", -8765);

  // ft_printf("ft_[%010.1d]\n", -8765);
  // printf("pr_[%010.1d]\n", -8765);
  */


  /* GETTING space_flags exceptin
  // printf("pr_[%15p]\n", NULL);
  // printf("pr_[%15s]\n", NULL);
  // printf("pr_[%15c]\n", 'a');
  // printf("pr_[%15d]\n", 1);
  // printf("pr_[%15i]\n", 1);
  // printf("pr_[%15u]\n", 1);
  // printf("pr_[%15x]\n", 1);
  // printf("pr_[%15X]\n", 1);
  //
  // printf("pr_[%015p]\n", NULL);
  // printf("pr_[%015s]\n", NULL);
  // printf("pr_[%015c]\n", 'a');
  // printf("pr_[%015d]\n", 1);
  // printf("pr_[%015i]\n", 1);
  // printf("pr_[%015u]\n", 1);
  // printf("pr_[%015x]\n", 1);
  // printf("pr_[%015X]\n", 1);
  */


  /* Unsigned tests
  // printf("pr_%-.12u\n", -2000000000);
  // ft_printf("ft_%-.12u\n", -2000000000);
  // printf("ps_%-20.12u\n", 2000000000);
  // ft_printf("fs_%-20.12u\n", 2000000000);
  // printf("pr_%-.14u\n", -2000000000);
  // printf("ps_%-12u\n", -42);
  // ft_printf("fs_%-12u\n", -42);
  */

  // D RET TESTS
  // printf("1st print : P == 1 --- 2d print : P == strlen(aff) --- 3rd print : P > strlen(aff)\n");
  // printf("1pr_ret = %d\n", printf("1%%p::pr_[%010.1d]\n", 8888));
  // ft_printf("1ft_ret = %d\n", ft_printf("1%%p::ft_[%010.1d]\n", 8888));
  // printf("2pr_ret = %d\n", printf("2%%p::pr_[%010.4d]\n", 8888));
  // ft_printf("2ft_ret = %d\n", ft_printf("2%%p::ft_[%010.4d]\n", 8888));
  // printf("3pr_ret = %d\n", printf("3%%p::pr_[%010.6d]\n", 8888));
  // ft_printf("3ft_ret = %d\n", ft_printf("3%%p::ft_[%010.6d]\n", 8888));

  return (0);
}
