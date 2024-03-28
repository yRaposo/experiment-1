const express = require("express");
const bodyParser = require("body-parser");

const app = express();

// Use o middleware body-parser para analisar o corpo das solicitações JSON
app.use(bodyParser.json());

let Click = 0;

app.post("/clicks", (req, res) => {
  // Extraia a variável Click do corpo da solicitação
  Click = req.body.clicks;

  res.send("Received clicks: " + Click);
});

app.get("/clicks", (req, res) => {
  // Envie a variável Click para o front-end
  res.json({ clicks: Click });
});

app.listen(8081, () => {
  console.log("Servidor rodando na porta 8081");
});