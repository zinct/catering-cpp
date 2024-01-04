//
//  main.cpp
//  catering
//
//  Created on 16/12/23.
//

#include <iostream>
#include "catering.h"

using namespace std;

int main() {
    CateringList cateringList;
    FoodMenuList foodMenuList;
    
    createCateringList(cateringList);
    createFoodMenuList(foodMenuList);
    
    int menu;
    
    do {
        cout << "========== Selamat datang di layanan catering ==========" << endl;
        cout << "1. Tambah Catering" << endl;
        cout << "2. Tambah Menu Makanan" << endl;
        cout << "3. Hubungkan Catering dan Menu Makanan" << endl;
        cout << "4. Hapus Data Catering" << endl;
        cout << "5. Hapus Data Menu Makanan" << endl;
        cout << "6. Tampilkan Data Catering" << endl;
        cout << "7. Tampilkan Data Makanan" << endl;
        cout << "8. Tampilkan Data Catering Beserta Makanan" << endl;
        cout << "9. Tampilkan Makanan Terbanyak yang dijual" << endl;
        cout << "10. Cari Data Catering" << endl;
        cout << "11. Cari Data Makanan" << endl;
        cout << "12. Cari Data Menu Makanan Pada Catering" << endl;
        cout << "13. Tampilkan jumlah makanan dalam catering" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        
        // Menu process
        if(menu == 1) {
            CateringInfoType cateringInfo;
            cateringInfo.id = getMaxCateringID(cateringList) + 1;
            cout << "Masukkan Nama Catering: ";
            cin.ignore();
            getline(cin, cateringInfo.name);
            cout << "Masukkan Harga: ";
            cin >> cateringInfo.price;
            
            insertCatering(cateringList, createCateringElement(cateringInfo));
            cout << "Catering berhasil ditambahkan." << endl;
        } else if(menu == 2) {
            FoodMenuInfoType foodMenuInfo;
            foodMenuInfo.id = getMaxFoodMenuID(foodMenuList) + 1;
            foodMenuInfo.totalOrdered = 0;
            cout << "Masukkan Nama Menu Makanan: ";
            cin.ignore();
            getline(cin, foodMenuInfo.name);
            
            insertFoodMenu(foodMenuList, createFoodMenuElement(foodMenuInfo));
            cout << "Menu makanan berhasil ditambahkan." << endl;
        } else if(menu == 3) {
            int cateringId;
            cout << "Masukkan ID Catering: ";
            cin >> cateringId;
            
            CateringAddress catering = findCatering(cateringList, cateringId);
            
            if(catering == NULL) {
                cout << "Data Catering tidak ditemukan!" << endl;
                continue;
            }
            
            int foodId;
            cout << "Masukkan ID Makanan: ";
            cin >> foodId;
            
            FoodMenuAddress foodMenu = findFoodMenu(foodMenuList, foodId);
            
            if(foodMenu == NULL) {
                cout << "Data Makanan tidak ditemukan!" << endl;
                continue;
            }
            
            connectCateringToFoodMenu(catering, foodMenu);
            
            cout << "Berhasil menguhubungkan Catering dengan Makanan" << endl;
            
        } else if(menu == 4) {
            int id;
            cout << "Masukkan ID yang ingin dihapus: ";
            cin >> id;
            cout << id << endl;
            
            CateringAddress deletedCatering = findCatering(cateringList, id);
            
            if(deletedCatering == NULL) {
                cout << "ID Tidak ditemukan!" << endl;
            } else {
                deleteCatering(cateringList, deletedCatering);
                cout << "Berhasil menghapus catering" << endl;
            }
        } else if(menu == 5) {
            int id;
            cout << "Masukkan ID yang ingin dihapus: ";
            cin >> id;
            cout << id << endl;
            
            FoodMenuAddress deletedFoodMenu = findFoodMenu(foodMenuList, id);
            
            if(deletedFoodMenu == NULL) {
                cout << "ID Tidak ditemukan!" << endl;
            } else {
                CateringAddress catering = first(cateringList);
                while(catering != NULL) {
                    FoodMenuAddress foodMenu = findFoodMenuInCatering(catering, id);
                    if(foodMenu != NULL) {
                        deleteFoodMenuInCatering(catering, foodMenu);
                    }
                    catering = next(catering);
                }
                
                deleteFoodMenu(foodMenuList, deletedFoodMenu);
                cout << "Berhasil menghapus makanan" << endl;
            }
        } else if(menu == 6) {
            showCateringList(cateringList);
        } else if(menu == 7) {
            showFoodMenuList(foodMenuList);
        } else if(menu == 8) {
            showCateringListWithFoodMenu(cateringList);
        } else if(menu == 9) {
            FoodMenuAddress foodMenu = showHightesOrdered(foodMenuList);
            
            if(foodMenu == NULL) {
                cout << "Data makanan kosong!" << endl;
            } else {
                cout << "Makanan terbanyak terjual adalah: " << info(foodMenu).name << endl;
            }
        } else if(menu == 10) {
            int id;
            cout << "Masukkan ID yang dicari: ";
            cin >> id;
            cout << id << endl;
            
            CateringAddress catering = findCatering(cateringList, id);
            if(catering == NULL) {
                cout << "Data tidak ditemukan!" << endl;
            } else {
                cout << "Data ditemukan dengan nama: " << info(catering).name << endl;
            }
        } else if(menu == 11) {
            int id;
            cout << "Masukkan ID yang dicari: ";
            cin >> id;
            cout << id << endl;
            
            FoodMenuAddress foodMenu = findFoodMenu(foodMenuList, id);
            if(foodMenu == NULL) {
                cout << "Data tidak ditemukan!" << endl;
            } else {
                cout << "Data ditemukan dengan nama: " << info(foodMenu).name << endl;
            }
        } else if(menu == 12) {
            int id;
            cout << "Masukkan ID Catering: ";
            cin >> id;
            cout << id << endl;
            
            CateringAddress catering = findCatering(cateringList, id);
            if(catering == NULL) {
                cout << "Data tidak ditemukan!" << endl;
                continue;
            }
            
            cout << "Masukkan ID Makanan: ";
            cin >> id;
            cout << id << endl;
            
            FoodMenuAddress foodMenu = findFoodMenuInCatering(catering, id);
            if(foodMenu == NULL) {
                cout << "Data tidak ditemukan!" << endl;
            } else {
                cout << "Data ditemukan dengan nama: " << info(foodMenu).name << endl;
            }
        } else if(menu == 13) {
            int id;
            cout << "Masukkan ID Catering: ";
            cin >> id;
            cout << id << endl;
            
            CateringAddress catering = findCatering(cateringList, id);
            if(catering == NULL) {
                cout << "Data tidak ditemukan!" << endl;
                continue;
            }
            
            int total = getTotalFoodMenuInCatering(catering);
            cout << "Total menu berjumlah: " << total << endl;
        } else {
            cout << "Menu Tidak ditemukan!" << endl;
        }
        
    } while (menu != 0);
    
    cout << "Berhasil keluar aplikasi" << endl;
    
    return 0;
}
