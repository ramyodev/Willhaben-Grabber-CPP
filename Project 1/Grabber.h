#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>
#include <string>
#include <clocale>



class Grabber
{
public:
	Grabber() {
		menu = {
			"/antiquitaeten-kunst-6941", "/kameras-tv-multimedia-6808", "/baby-kind-3928",
			"/kfz-zubehoer-motorradteile-6142", "/beauty-gesundheit-wellness-3076",
			"/mode-accessoires-3275", "/boote-yachten-jetskis-5007823", "/smartphones-telefonie-2691",
			"/buecher-filme-musik-387", "/spielen-spielzeug-5136", "/computer-software-5824",
			"/sport-sportgeraete-4390", "/dienstleistungen-537", "tiere-tierbedarf-4915",
			"/freizeit-instrumente-kulinarik-6462", "/uhren-schmuck-2409", "/games-konsolen-2785",
			"/wohnen-haushalt-gastronomie-5387", "/haus-garten-werkstatt-3541", "/zu-verschenken/"

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
		to_filter_url['+'] = "%2B";
		to_filter_url[' '] = "+";
		to_filter_url['?'] = "%3F";
		to_filter_url['#'] = "%23";
		to_filter_url['!'] = "%21";
		to_filter_url['/'] = "%2F";
		to_filter_url[','] = "%2C";
		to_filter_url['%'] = "%25";
		to_filter_url['='] = "%3D";
		to_filter_url['('] = "%28";
		to_filter_url[')'] = "%29";
		to_filter_url['&'] = "%26";
		to_filter_url[';'] = "%3B";
		to_filter_url[':'] = "%3A";
		to_filter_url[oe] = "%F6";
		to_filter_url[ss] = "%DF";
		to_filter_url[ue] = "%FC";
		to_filter_url[ae] = "%E4";
		to_filter_url[OE] = "%D6";
		to_filter_url[UE] = "%DC";
		to_filter_url[AE] = "%C4";
		to_filter_url[xx] = "%D7";

	}
	void Marktplatz() {
		std::string mp_first_under;
		std::string search_url;

		while (true) {
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
							search_url = build_willhaben_url(mp_user_choice_uc);
							break;
						}
					}

				}
				break;
			}


			else if (mp_first_under == "n" || mp_first_under == "N") {
				search_url = build_willhaben_url(-1);
				break;
			}
			else
			{
				std::cout << "--------------------\nInvalid selection!\n--------------------";
			}

		}
		std::cout << search_url << std::endl;
		std::cout << "Raus ende";
	}

	std::string build_willhaben_url(int uk) {
		std::string keyword_input;
		std::cout << "Select keyword:" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, keyword_input);
		std::string keyword;

		for (char cat : keyword_input) {
			if (to_filter_url.count(cat)) {
				keyword += to_filter_url[cat];
			} 
			else {
				keyword += cat;
			}
		}
		
		int typ;
		std::cout << "By whom should products be grabbed?\n0 - Private dealers\n1 - Business Dealers\n2 - Both" << std::endl;
		std::cin >> typ;

		if (uk == 20) {
			return "https://www.willhaben.at/iad/kaufen-und-verkaufen/zu-verschenken/marktplatz?rows=100&keyword=" + keyword;

		}

		else
		{
			int minimum_price;
			int maximum_price;
			while (true) {

				std::cout << "Minimum price:" << std::endl;
				std::cin >> minimum_price;

				std::cout << "Maximum price:" << std::endl;
				std::cin >> maximum_price;

				if (minimum_price > maximum_price) {
					std::cout << "---------------------------------------------------\nMinimum price cannot be higher than maximum price!\n---------------------------------------------------" << std::endl;
				}
				else
				{
					break;
				}
			}

			if (uk != -1) {
				return base_url + menu[uk - 1] + "?PRICE_FROM=" + std::to_string(minimum_price) + types_of_vendor[typ] + "&keyword=" + keyword + "&PRICE_TO=" + std::to_string(maximum_price) + "&rows=100";

			}
			else
			{
				return base_url + "?PRICE_FROM=" + std::to_string(minimum_price) + types_of_vendor[typ] + "&keyword=" + keyword + "&PRICE_TO=" + std::to_string(maximum_price) + "&rows=100";
			}
		}
	}

private:
	std::string base_url = "https://www.willhaben.at/iad/kaufen-und-verkaufen/marktplatz";
	std::array<std::string, 20> menu;
	std::array<std::string, 21> menu_printed;
	std::vector<std::string> links_with_products;
	std::array<std::string, 3> types_of_vendor = { "&ISPRIVATE = 1", "&ISPRIVATE=0", "" };
	std::unordered_map<char, std::string> to_filter_url;

	const unsigned char AE = static_cast<unsigned char>(142);
	const unsigned char ae = static_cast<unsigned char>(132);
	const unsigned char OE = static_cast<unsigned char>(153);
	const unsigned char oe = static_cast<unsigned char>(148);
	const unsigned char UE = static_cast<unsigned char>(154);
	const unsigned char ue = static_cast<unsigned char>(129);
	const unsigned char ss = static_cast<unsigned char>(225);
	const unsigned char xx = static_cast<unsigned char>(215);

};
