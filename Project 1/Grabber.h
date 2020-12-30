#pragma once
#include <iostream>
#include <array>
#include <vector>

class Grabber
{
public:
	Grabber() {
		menu = {
			"/kaufen-und-verkaufen/antiquitaeten-kunst-6941", "/kaufen-und-verkaufen/kameras-tv-multimedia-6808", "/kaufen-und-verkaufen/baby-kind-3928",
			"/kaufen-und-verkaufen/kfz-zubehoer-motorradteile-6142", "/kaufen-und-verkaufen/beauty-gesundheit-wellness-3076",
			"/kaufen-und-verkaufen/mode-accessoires-3275", "/kaufen-und-verkaufen/boote-yachten-jetskis-5007823", "/kaufen-und-verkaufen/smartphones-telefonie-2691",
			"/kaufen-und-verkaufen/buecher-filme-musik-387", "/kaufen-und-verkaufen/spielen-spielzeug-5136", "/kaufen-und-verkaufen/computer-software-5824",
			"/kaufen-und-verkaufen/sport-sportgeraete-4390", "/kaufen-und-verkaufen/dienstleistungen-537", "/kaufen-und-verkaufen/tiere-tierbedarf-4915",
			"/kaufen-und-verkaufen/freizeit-instrumente-kulinarik-6462", "/kaufen-und-verkaufen/uhren-schmuck-2409", "/kaufen-und-verkaufen/games-konsolen-2785",
			"/kaufen-und-verkaufen/wohnen-haushalt-gastronomie-5387", "/kaufen-und-verkaufen/haus-garten-werkstatt-3541", "/kaufen-und-verkaufen/zu-verschenken/"

		};
		menu_printed = {
			"0. Back",
			"1. Antiquitäten / Kunst",
			"2. Kameras / TV / Multimedia",
			"3. Baby / Kind",
			"4. KFZ-Zubehör / Motorradteile",
			"5. Beauty / Gesundheit / Wellness",
			"6. Mode / Accessoires",
			"7. Boote / Yachten / Jetskis",
			"8. Smartphones / Telefonie",
			"9. Bücher / Filme / Musik",
			"10. Spielen / Spielzeug",
			"11. Computer / Software",
			"12. Sport / Sportgeräte",
			"13. Dienstleistungen",
			"14. Tiere / Tierbedarf",
			"15. Freizeit / Instrumente / Kulinarik",
			"16. Uhren / Schmuck",
			"17. Games / Konsolen",
			"18. Wohnen / Haushalt / Gastronomie",
			"19. Haus / Garten / Werkstatt",
			"20. To give away Free"
		};
	}
	void Marktplatz() {
		while (true) {
			std::string mp_first_under;
			std::cout << "Do you want to choose a subcategory? Y - Yes or N - No\n";
			std::cin >> mp_first_under;

			if (mp_first_under == "y" || mp_first_under == "Y") {
				while (true) {
					for (std::string cat : menu_printed) {
						std::cout << cat << std::endl;

					}
					int mp_user_choice_uc;
					std::cin >> mp_user_choice_uc;

					if (mp_user_choice_uc <= 20 && mp_user_choice_uc >= 0) {
						if (mp_user_choice_uc == 0) {
							break;
						}
						else
						{

						}
					}
				}
			}
			else if (mp_first_under == "n" || mp_first_under == "N") {

			}

		}
	}

	std::string build_willhaben_url(std::string uk) {
		std::string keyword;
		std::cout << "Select keyword:" << std::endl;
		std::cin >> keyword;

	}

private:
	std::string base_url = "https://www.willhaben.at/iad/kaufen-und-verkaufen/marktplatz";
	std::array<std::string, 20> menu;
	std::array<std::string, 21> menu_printed;
	std::vector<std::string> links_with_products;
	std::array<std::string, 3> types_of_vendor = { "&ISPRIVATE = 1", "&ISPRIVATE=0", "" };
};
