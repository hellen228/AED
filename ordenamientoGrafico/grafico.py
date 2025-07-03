import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("tiempos.csv")

plt.figure(figsize=(10, 6))

for columna in df.columns[1:]:
    plt.plot(df["CantidadDatos"], df[columna], label=columna, marker='.')

plt.xlabel("Cantidad de Datos")
plt.ylabel("Tiempo (ms)")
plt.title("Comparación de Algoritmos de Ordenamiento")
plt.legend()
plt.grid(True)
plt.tight_layout()

plt.savefig("comparacion_7ordenamientos.png")
plt.show()
