async function getStatus() {
  const res = await fetch("http://localhost:3000/status");
  const data = await res.json();

  const statusEl = document.getElementById("status");

  statusEl.innerText = data.status;

  if (data.status === "occupied") {
    statusEl.style.color = "red";
  } else {
    statusEl.style.color = "green";
  }
}

setInterval(getStatus, 2000);
