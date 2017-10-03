

/**
 * @file metaTab.h
 * @brief tipos de estructuras para representar los metadatos de un fichero de configuración
 
 */
 
 
 /**
 * 
 * @brief Tipo estructura para un meta valor tipo char
 *
 *  El nombre/etiqueta es como muncho de longitud 200
 * Corresponde a una linea del tipo :\n
 * \verbatim
   etiqueta:C:10
   \endverbatim
* Que define una linea del fichero de configuración de este formato: \n
  \verbatim
   etiqueta: texto
  \endverbatim
   Uso:
   \verbatim
   itemChar_t item;
   \endverbatim
 */
typedef struct
{
 char nombre[200+1]; /**<   la etiqueta  */
 int lenChar;  /**<   la longitud del texto del fichero de configuración */
} itemChar_t; 

 /**
 * 
 * @brief Tipo estructura para un meta valor tipo lista
 *
 *  El nombre/etiqueta es como muncho de longitud 200
 * Corresponde a una linea del tipo lista :\n
 * \verbatim
   etiqueta:L:2:20
   \endverbatim
* Que define una linea del fichero de configuración de este formato: \n
  \verbatim
   etiqueta: texto1:texto2
  \endverbatim
   Uso:
   \verbatim
   itemLista_t item;
   \endverbatim
 */
typedef struct
{
 char nombre[200+1]; /**<   la etiqueta  */
 int lenLista; /**<  numero de elementos de la lista  */
 int lenChar; /**<   longitud máxima del texto  */
} itemLista_t;

 /**
 * 
 * @brief Tipo estructura para un meta valor tipo objeto
 *
 *  El nombre/etiqueta es como muncho de longitud 200
 * Corresponde a una linea del tipo objeto :\n
 * \verbatim
   etiqueta:O:item1:len1:item2:len2...
   \endverbatim
* Que define una linea del fichero de configuración de este formato: \n
  \verbatim
   etiqueta: texto1:texto2...
  \endverbatim
   Uso:
   \verbatim
   itemObjeto_t item;
   \endverbatim
 */
typedef struct
{
 char nombre[200+1]; /**<   la etiqueta  */
 itemChar_t *item; /**< Lista de parejas item/len */
 int numItems; /**< Numero de items */
}itemObjeto_t;

 /**
 * 
 * @brief Tipo estructura para un item independiente del tipo
 *
 *  Incluye un tipo y una estructura dependiendo del tipo
   Uso:
   \verbatim
   metaTabItem_t tabItem;
   \endverbatim
 */
typedef struct
{
  char tipo;  /**< El tipo que puede ser 'C','L' u 'O' */
  void *data; /**< El dato que puede ser `itemChar_t`, `itemList_t` o `itemObjeto_t` */
} metaTabItem_t;

 /**
 * 
 * @brief Tipo estructura que representa una lista de items, que define el fichero meta entero
 *
 *  Incluye el numero de items y un puntero a una lista de items.
   Uso:
   \verbatim
   metaTab_t metaTab
   \endverbatim
 */
typedef struct
{
 int numItems; /**< Numero de Items instanciados en la lista */
 metaTabItem_t *item; /**< lista de metaTab items */
} metaTab_t;

metaTab_t *leeMetaTab(char *file);




