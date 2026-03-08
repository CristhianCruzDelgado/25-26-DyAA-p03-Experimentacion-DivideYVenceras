import json
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.patches import Patch

# Cargar el JSON
with open("solution.json", "r") as f:
    data = json.load(f)

schedule = data["schedule"]
numE = data["employees"]  # número de empleados
numD = data["days"]
numS = data["shifts"]     # número de turnos
objective_value = data.get("objective_function", None)  # añadir valor de la función objetivo

# Crear una matriz de enteros para el heatmap
# Cada celda = 0 si libre, 1..numS si asignado a turno
heatmap = np.zeros((numE, numD), dtype=int)

for e in range(numE):
    for d in range(numD):
        for s in range(numS):
            if schedule[e][d][s]:
                heatmap[e][d] = s + 1  # s+1 para diferenciar colores

# Colores: 0=blanco (libre), T1..Tn para turnos
cmap = plt.get_cmap("tab10", numS + 1)

plt.figure(figsize=(10, 6))
plt.imshow(heatmap, cmap=cmap, origin="upper", aspect="auto")

# Ejes
plt.xticks(ticks=np.arange(numD), labels=[f"Day {d}" for d in range(numD)])
plt.yticks(ticks=np.arange(numE), labels=[f"Employee {e}" for e in range(numE)])
plt.xlabel("Days")
plt.ylabel("Name")
title = "Employee Shift Planning"
if objective_value is not None:
    title += f" | Objective: {objective_value:.2f}"
plt.title(title)

# Leyenda
legend_elements = [
    Patch(facecolor=cmap(i), edgecolor='k', label=f"T{i}" if i>0 else "FreeDay")
    for i in range(numS + 1)
]
plt.legend(handles=legend_elements, bbox_to_anchor=(1.05, 1), loc='upper left')

plt.tight_layout()
plt.savefig("heatmap.png", dpi=300)  # guarda la imagen
plt.show()
print("Heatmap guardado en heatmap.png")
if objective_value is not None:
    print(f"Valor de la función objetivo: {objective_value:.2f}")