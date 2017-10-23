
metaTab_t *leeMetaTab(char *file);

int addItemObjeto(itemObjeto_t *objeto,char *label,char *descri,int len);
int addItemCharMetaTab(metaTab_t *tabla,char *label,char *descri,int len);
int addItemListMetaTab(metaTab_t *tabla,char *label,char *descri,int lenLista,int lenChar);
int addItemTipoMetaTab(metaTab_t *tabla,char *label,char *descri,char *tipo);
int addItemObjMetaTab(metaTab_t *tabla,itemObjeto_t **objeto);



