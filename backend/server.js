const express = require("express");
const cors = require("cors");

const app = express();
app.use(cors());

let parkingStatus = "unknown";

app.get("/update", (req, res) => {
  parkingStatus = req.query.status;
  res.send("OK");
});

app.get("/status", (req, res) => {
  res.json({ status: parkingStatus });
});

app.listen(3000, () => {
  console.log("Server running on port 3000");
});
