/*-az---------------------------------------------------------------------------
 * Cardpad 演示脚本
 * ---------------------------------------
 *
 * 1. GP 卡应用安装、删除、列应用
 *
 * by 渝武陶 (y.volta@mail.com)
 * rev 1.0.0, $$ 2011-09-17 12:50:00 $$
 *---------------------------------------------------------------------------*/

cls; 
rd_reset ();
auth();

void get_data_0 ()
{
    get_data -identifier 9F7F;
    get_data -identifier 66;
}

void get_status_0 ()
{
    get_status -element e0;
    get_status -element 20;
    get_status -element 40;
    get_status -element 80;
}

void list_0 ()
{
    select -AID a000000003000000;
    
    // Open secure channel
    open_sc -security 1 -keyind 0 -keyver 0 -mac_key 404142434445464748494a4b4c4d4e4f -enc_key 404142434445464748494a4b4c4d4e4f;

    get_status -element 10;
    get_status -element 20;
    get_status -element 40;
    get_status -element 80;
}

void hello_delete ()
{
    select -AID a000000003000000;
    
    // Open secure channel
    open_sc -security 1 -keyind 0 -keyver 0 -mac_key 404142434445464748494a4b4c4d4e4f -enc_key 404142434445464748494a4b4c4d4e4f ;
    gpdelete -AID D0D1D2D3D4D50101;
    gpdelete -AID D0D1D2D3D4D501;
}

void hello_install ()
{
    hello_delete ();
    
    install -file ../res/helloworld.cap -sdAID a000000003000000 -priv 2;
}

//get_data_0();
list_0 ();
//hello_install ();


/* --------------------------------------------- end-of-script ---------------*/
