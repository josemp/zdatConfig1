#define TIPO_ITEM(nTabla,nItem) ((nTabla)->tabla->item[(nItem)].tipo )
#define DATA_ITEM(nTabla,nItem) ((nTabla)->tabla->item[(nItem)].data )

typedef struct
{
 char nombre[200+1];
 int lenChar;
} itemChar_t;
typedef struct
{
 char nombre[200+1];
 int lenLista;
 int lenChar;
} itemLista_t;
typedef struct
{
 char nombre[200+1];
 itemChar_t *item;
 int numItems;
}itemObjeto_t;

typedef struct
{
  char tipo;
  void *data;
} metaTabItem_t;
typedef struct
{
 int numItems; 
 metaTabItem_t *item;
} metaTab_t;

metaTab_t *leeMetaTab(char *file);

int addItemObjeto(itemObjeto_t *objeto,char *label,int len);
int addItemCharMetaTab(metaTab_t *tabla,char *label,int len);
int addItemListMetaTab(metaTab_t *tabla,char *label,int lenLista,int lenChar);
int addItemObjMetaTab(metaTab_t *tabla,itemObjeto_t **objeto);
char *getNombreItemTabla(metaTab_t *tabla,int itemTabla);
int  getLenCharItemTabla(metaTab_t *tabla,int itemTabla);
int  getLenListaItemTabla(metaTab_t *tabla,int itemTabla);
char *getNombreItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto);
int getLenCharItemObjeto(metaTab_t *tabla,int itemTabla,int numItemObjeto);
int  getNumItemsObjeto(metaTab_t *tabla,int itemTabla);




