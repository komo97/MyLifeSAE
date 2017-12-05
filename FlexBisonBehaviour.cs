using System.Runtime.InteropServices;
using System.Text;
using System;


public struct BisonString
{
    [MarshalAs(UnmanagedType.LPStr)] string str;
    int len;
    static public implicit operator string(BisonString value)
    {
        return value.str;
    }

};


public class FlexBisonBehaviour {


    [DllImport("FlexBisonUnityDll", EntryPoint = "GetBisonString")]
    public static extern BisonString GetBisonString();

    [DllImport("FlexBisonUnityDll", EntryPoint = "PushBisonString")]
    public static extern void PushBisonString([MarshalAs(UnmanagedType.LPStr)]string str, UIntPtr size);

    [DllImport("FlexBisonUnityDll", EntryPoint = "StartBison")]
    public static extern void StartBison();

    [DllImport("FlexBisonUnityDll", EntryPoint = "TerminateBison")]
    public static extern void TerminateBison();

    /// <summary>
    /// Utilizar esta funcion para absolutamente todo, le meten un string normalito y les va a entregar un valor
    /// que pueden igualar directamente sobre un string normalito.
    /// </summary>
    /// <param name="str">El string de entrada.</param> 
    /// <param name="size">El tamaño del string de entrada.</param>
    /// <returns>Un BisonString igualable a un string que regresa un caracter nulo si bison fallo al parsear
    /// o el resultado esperado si funciono.</returns>
    [DllImport("FlexBisonUnityDll", EntryPoint = "BisonAllExecution")]
    public static extern BisonString BisonAllExecution([MarshalAs(UnmanagedType.LPStr)]string str, UIntPtr size);
}
