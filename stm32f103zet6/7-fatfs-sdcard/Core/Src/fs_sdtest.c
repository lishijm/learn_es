#include "fs_sdtest.h"
#include "malloc.h"
#include "string.h"

void fs_test(void){
    FRESULT ret;
    FATFS *fs_obj;
    FIL *fil_obj;

    uint8_t rd_buf[32]={0};
    uint16_t fsize=0;
    uint16_t rd_count,wd_count;
    
    printf("malloc before\r\n");
    fs_obj=mymalloc(0,sizeof(FATFS));
    fil_obj=mymalloc(0,sizeof(FIL));
    printf("malloc after,fs_obj:%p,fil_obj:%p\r\n",fs_obj,fil_obj);
    
    ret=f_mount(fs_obj,"0:",1);
    printf("after mount,ret=%d\r\n",ret);
    if(ret){
        printf("mount fail,error ret=%d\r\n",ret);
    }
    else{
        printf("mount success\r\n");
    }
    
    ret=f_open(fil_obj,"0:test.txt",FA_OPEN_ALWAYS|FA_READ|FA_WRITE);
    printf("after open,ret=%d\r\n",ret);
    if(ret){
        printf("open fail,error ret=%d\r\n",ret);
    }
    else{
        printf("open success\r\n");
    }
    
    ret=f_write(fil_obj,"FATFS-TEST",11,(UINT *)&wd_count);//结尾默认带EOF，所以需要将文件指针指向EOF前面
    printf("after write,ret=%d\r\n",ret);
    f_lseek(fil_obj,10);
    f_printf(fil_obj," SDCARD00\r\n");

    f_lseek(fil_obj,0);
    fsize=f_size(fil_obj);
    printf("fsize=%d\r\n",fsize);

    ret=f_read(fil_obj,(void *)rd_buf,(UINT)fsize,(UINT *)&rd_count);
    printf("after read,ret=%d,rd_count=%d,rd_buf size=%d\r\n",ret,rd_count,strlen((const char *)rd_buf));
    if(rd_count!=0){
        printf("rd_count:%d rd_buf:%s\r\n",rd_count,rd_buf);
    }
    
    f_close(fil_obj);
    myfree(0,fs_obj);
    myfree(0,fil_obj);
}